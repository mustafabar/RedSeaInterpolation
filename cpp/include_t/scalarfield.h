#ifndef SCALARFIELD_H
#define SCALARFIELD_H

#include "interpolation.h"
#include "point.h"

#include "../../eigen3/Eigen/Dense"
#include "unsupported/Eigen/CXX11/Tensor"
#include "yaml-cpp/yaml.h"

#include <array>
#include <string>

struct InterpolationResult {
  double fun;
  Eigen::Vector3d grad;
  Eigen::Matrix3d hess;
};

class ScalarField
{
public:
  ScalarField(long _nx,
              long _ny,
              long _nz,
              double _hx,
              double _hy,
              Eigen::VectorXd _z_grid,
              Eigen::Tensor<double, 3, Eigen::RowMajor> _values);
  ScalarField(const YAML::Node &config);

  void read_tensor_component(const std::string &filename, long idx);
  std::array<long, 3> find_cell(const Point &x) const;
  long find_z_index(double z) const;

  double operator()(long i, long j, long k) const;
  Eigen::Vector2d deltax() const;
  Eigen::Vector2d deltay() const;
  Eigen::Vector3d deltaz(long k) const;
  double dx(long i, long j, long k) const;
  double dy(long i, long j, long k) const;
  double dz(long i, long j, long k) const;
  double dxdy(long i, long j, long k) const;
  double dxdz(long i, long j, long k) const;
  double dydz(long i, long j, long k) const;
  double dxdydz(long i, long j, long k) const;

  inline double getHx() const { return hx; };
  inline double getHy() const { return hy; };
  inline Eigen::VectorXd getZGrid() const { return z_grid; };

  InterpolationResult operator()(const Point &x) const;

private:
  long nx;
  long ny;
  long nz;
  double hx;
  double hy;
  Eigen::VectorXd z_grid;
  Eigen::Tensor<double, 3, Eigen::RowMajor> values;
};

#endif
