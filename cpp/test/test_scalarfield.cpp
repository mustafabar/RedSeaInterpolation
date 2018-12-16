#include "referencefunctions.h"
#include "scalarfield.h"

#include "Eigen/Dense"
#include "yaml-cpp/yaml.h"

#include "gtest/gtest.h"
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <random>

YAML::Node uConfig;
YAML::Node vConfig;
YAML::Node wConfig;

TEST(ScalarFieldTest, RowMajor)
{
  ScalarField uf(uConfig);
  ScalarField vf(vConfig);
  ScalarField wf(wConfig);
  Eigen::Vector3d v;
  v << uf(487, 67, 19), vf(487, 67, 19), wf(487, 67, 19);
  Eigen::Vector3d v_true = {
      0.09129716000519693, 0.1546565382758854, 0.00031860935451052545};
  EXPECT_LT((v - v_true).norm(), 1e-14 * v_true.norm());
}

TEST(ScalarFieldTest, FindCell)
{
  ScalarField uf(uConfig);
  double x[3] = {20000, 400000, -60};
  auto index = uf.find_cell(x);

  // x
  EXPECT_EQ(index[0], 4);
  EXPECT_GT(x[0], index[0] * uf.getHx());
  EXPECT_LT(x[0], (index[0] + 1) * uf.getHx());
  // y
  EXPECT_EQ(index[1], 89);
  EXPECT_GT(x[1], index[1] * uf.getHy());
  EXPECT_LT(x[1], (index[1] + 1) * uf.getHy());
  // z
  EXPECT_EQ(index[2], 9);
  EXPECT_LT(x[2], uf.getZGrid()[index[2]]);
  EXPECT_GT(x[2], uf.getZGrid()[index[2] + 1]);
}

ScalarField scalarFieldTestHelper(const ReferenceFunction &fun,
                                  long nx,
                                  long ny,
                                  long nz,
                                  double &hx,
                                  double &hy)
{
  std::mt19937 mt(0);
  std::uniform_real_distribution<> uni;
  hx = 1.0 / static_cast<double>(nx - 1);
  hy = 1.0 / static_cast<double>(ny - 1);
  Eigen::VectorXd z_grid(nz);
  for (long i = 0; i < nz - 2; i++) {
    z_grid(i) = uni(mt);
  }
  z_grid(nz - 2) = 0.;
  z_grid(nz - 1) = 1.;
  std::sort(z_grid.data(), z_grid.data() + nz, std::greater<double>());

  Eigen::Tensor<double, 3, Eigen::RowMajor> values(nx, ny, nz);
  double xi, yj, zk;
  for (long i = 0; i < nx; i++) {
    for (long j = 0; j < ny; j++) {
      for (long k = 0; k < nz; k++) {
        xi = static_cast<double>(i) * hx;
        yj = static_cast<double>(j) * hy;
        zk = z_grid(k);
        Point x(xi, yj, zk);
        values(i, j, k) = fun(x);
      }
    }
  }
  return ScalarField(nx, ny, nz, hx, hy, z_grid, values);
}

TEST(ScalarFieldTest, FiniteDifferences)
{
  Polynomial poly(std::array<long, 3>{2, 2, 2});
  long nx = 20;
  long ny = 21;
  long nz = 22;
  double hx, hy;
  auto sf = scalarFieldTestHelper(poly, nx, ny, nz, hx, hy);
  long i = 10;
  long j = 11;
  long k = 12;
  double xi = i * hx;
  double yj = j * hy;
  double zk = sf.getZGrid()(k);
  Point x(xi, yj, zk);
  double tol = 1e-12;
  EXPECT_NEAR(sf(i, j, k), poly(x), tol);
  EXPECT_NEAR(sf.dx(i, j, k), poly.dx(x), tol);
  EXPECT_NEAR(sf.dy(i, j, k), poly.dy(x), tol);
  EXPECT_NEAR(sf.dz(i, j, k), poly.dz(x), tol);
}

TEST(ScalarFieldTest, Interpolate)
{
  Sine fun(std::array<double, 3>{0.2, 0.4, 0.5});
  long nx = 50;
  long ny = 51;
  long nz = 52;
  double hx, hy;
  auto sf = scalarFieldTestHelper(fun, nx, ny, nz, hx, hy);
  Point u(0.49876, 0.54329497, 0.6423879);

  EXPECT_NEAR(fun(u), sf(u).fun, 1e-5);
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  assert(argc == 8);
  uConfig = YAML::LoadFile(argv[1]);
  vConfig = YAML::LoadFile(argv[2]);
  wConfig = YAML::LoadFile(argv[3]);
  uConfig["field"] = argv[4];
  vConfig["field"] = argv[5];
  wConfig["field"] = argv[6];
  uConfig["z_grid"] = argv[7];
  vConfig["z_grid"] = argv[7];
  wConfig["z_grid"] = argv[7];
  return RUN_ALL_TESTS();
}
