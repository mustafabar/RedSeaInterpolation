#include "scalarfield.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

ScalarField::ScalarField(long _nx,
                         long _ny,
                         long _nz,
                         double _hx,
                         double _hy,
                         Eigen::VectorXd _z_grid,
                         Eigen::Tensor<double, 3, Eigen::RowMajor> _values)
    : nx(_nx)
    , ny(_ny)
    , nz(_nz)
    , hx(_hx)
    , hy(_hy)
    , z_grid(std::move(_z_grid))
    , values(std::move(_values))
{
}

ScalarField::ScalarField(const YAML::Node &config)
    : nx(config["nx"].as<long>())
    , ny(config["ny"].as<long>())
    , nz(config["nz"].as<long>())
    , hx(config["hx"].as<double>())
    , hy(config["hy"].as<double>())
    , z_grid(nz)
    , values(nx, ny, nz)
{
  std::ifstream in0(config["z_grid"].as<std::string>(),
                    std::ios::in | std::ios::binary);
  in0.read((char *)z_grid.data(), nz * sizeof(double));
  in0.close();

  std::ifstream in1(config["field"].as<std::string>(),
                    std::ios::in | std::ios::binary);
  in1.read((char *)values.data(), nx * ny * nz * sizeof(double));
  in1.close();
}

std::array<long, 3> ScalarField::find_cell(const Point &x) const
{
  std::array<long, 3> ind = {static_cast<long>(std::floor(x[0] / hx)),
                             static_cast<long>(std::floor(x[1] / hy)),
                             find_z_index(x[2])};
  return ind;
}

long ScalarField::find_z_index(double z) const
{
  long k;
  for (k = 1; k < nz; k++) {
    if (z_grid[k] < z) {
      break;
    }
  }
  return k - 1;
}

double ScalarField::operator()(long i, long j, long k) const
{
  if ((i < 0) || (i > nx - 1) || (j < 0) || (j > ny - 1) || (k < 0)
      || (k > nz - 1) || std::isnan(values(i, j, k))) {
    return 0;
  } else {
    return values(i, j, k);
  }
}

Eigen::Vector2d ScalarField::deltax() const
{
  Eigen::Vector2d v = {-1 / (2 * hx), 1 / (2 * hx)};
  return v;
}

Eigen::Vector2d ScalarField::deltay() const
{
  Eigen::Vector2d v = {-1 / (2 * hy), 1 / (2 * hy)};
  return v;
}

Eigen::Vector3d ScalarField::deltaz(long k) const
{
  Eigen::Vector3d v;
  double hm;
  if (k == 0) {
    hm = z_grid(k);
  } else {
    hm = z_grid(k) - z_grid(k - 1);
  }
  double h;
  if (k == nz - 1) {
    h = hm;
  } else {
    h = z_grid(k + 1) - z_grid(k);
  }
  double dm = -h / (hm * (hm + h));
  double d = (h - hm) / (hm * h);
  double dp = hm / (h * (hm + h));
  v << dm, d, dp;
  return v;
}

double ScalarField::dx(long i, long j, long k) const
{
  return (operator()(i + 1, j, k) - operator()(i - 1, j, k)) / (2 * hx);
}

double ScalarField::dy(long i, long j, long k) const
{
  return (operator()(i, j + 1, k) - operator()(i, j - 1, k)) / (2 * hy);
}

double ScalarField::dz(long i, long j, long k) const
{
  Eigen::Vector3d delz = deltaz(k);
  return delz[0] * operator()(i, j, k - 1) + delz[1] * operator()(i, j, k)
         + delz[2] * operator()(i, j, k + 1);
}

double ScalarField::dxdy(long i, long j, long k) const
{
  Eigen::Vector2d delx = deltax();
  Eigen::Vector2d dely = deltay();
  double v = 0;
  for (long di = 0; di < 2; di++) {
    for (long dj = 0; dj < 2; dj++) {
      v += delx[di] * dely[dj] * operator()(i - 1 + 2 * di, j - 1 + 2 * dj, k);
    }
  }
  return v;
}

double ScalarField::dxdz(long i, long j, long k) const
{
  Eigen::Vector2d delx = deltax();
  Eigen::Vector3d delz = deltaz(k);
  double v = 0;
  for (long di = 0; di < 2; di++) {
    for (long dk = 0; dk < 3; dk++) {
      v += delx[di] * delz[dk] * operator()(i - 1 + 2 * di, j, k - 1 + dk);
    }
  }
  return v;
}

double ScalarField::dydz(long i, long j, long k) const
{
  Eigen::Vector2d dely = deltay();
  Eigen::Vector3d delz = deltaz(k);
  double v = 0;
  for (long dj = 0; dj < 2; dj++) {
    for (long dk = 0; dk < 3; dk++) {
      v += dely[dj] * delz[dk] * operator()(i, j - 1 + 2 * dj, k - 1 + dk);
    }
  }
  return v;
}

double ScalarField::dxdydz(long i, long j, long k) const
{
  Eigen::Vector2d delx = deltax();
  Eigen::Vector2d dely = deltay();
  Eigen::Vector3d delz = deltaz(k);
  double v = 0;
  for (long di = 0; di < 2; di++) {
    for (long dj = 0; dj < 2; dj++) {
      for (long dk = 0; dk < 3; dk++) {
        v += delx[di] * dely[dj] * delz[dk]
             * operator()(i - 1 + 2 * di, j - 1 + 2 * dj, k - 1 + dk);
      }
    }
  }
  return v;
}

InterpolationResult ScalarField::operator()(const Point &x) const
{
  auto ijk = find_cell(x);
  long i = ijk[0];
  long j = ijk[1];
  long k = ijk[2];
  double hz = z_grid(k + 1) - z_grid(k);
  Point u(x[0] - i * hx, x[1] - j * hy, x[2] - z_grid(k));

  std::array<Point, 2> corners{Point(0, 0, 0), Point(hx, hy, hz)};
  long cornersIndices[8][3] = {
      {0, 0, 0},
      {1, 0, 0},
      {0, 1, 0},
      {1, 1, 0},
      {0, 0, 1},
      {1, 0, 1},
      {0, 1, 1},
      {1, 1, 1},
  };

  InterpolationParameter param;
  for (size_t s = 0; s < 8; s++) {
    long *c = cornersIndices[s];
    long is = i + c[0];
    long js = j + c[1];
    long ks = k + c[2];
    param.f[s] = operator()(is, js, ks);
    param.dfdx[s] = dx(is, js, ks);
    param.dfdy[s] = dy(is, js, ks);
    param.dfdz[s] = dz(is, js, ks);
    param.d2fdxdy[s] = dxdy(is, js, ks);
    param.d2fdxdz[s] = dxdz(is, js, ks);
    param.d2fdydz[s] = dydz(is, js, ks);
    param.d3fdxdydz[s] = dxdydz(is, js, ks);
  }
  auto fun = tricubic_interpolate(param, corners[0], corners[1]);
  InterpolationResult results;
  results.fun = fun(u);
  results.grad = fun.grad(u);
  results.hess = fun.hess(u);
  return results;
}
