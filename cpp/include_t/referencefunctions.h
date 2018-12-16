#ifndef REFERENCEFUNCTIONS_H
#define REFERENCEFUNCTIONS_H

#include "point.h"

#include "../../../eigen3/Eigen/Dense"
#include "../../../eigen3/unsupported/Eigen/CXX11/Tensor"

#include <cmath>
#include <iostream>
#include <random>

class ReferenceFunction
{
public:
  virtual double operator()(const Point &x) const = 0;
  virtual double dx(const Point &x) const = 0;
  virtual double dy(const Point &x) const = 0;
  virtual double dz(const Point &x) const = 0;
  virtual double dxdy(const Point &x) const = 0;
  virtual double dxdz(const Point &x) const = 0;
  virtual double dydz(const Point &x) const = 0;
  virtual double dxdydz(const Point &x) const = 0;
  virtual double d2x(const Point &x) const = 0;
  virtual double d2y(const Point &x) const = 0;
  virtual double d2z(const Point &x) const = 0;

  Eigen::Vector3d grad(const Point &x) const;
  Eigen::Matrix3d hess(const Point &x) const;
};

class Polynomial : public ReferenceFunction
{
public:
  Polynomial(std::array<long, 3> _order)
      : order(std::move(_order))
      , c(_order[0] + 1, _order[1] + 1, _order[2] + 1)
  {
    c.setRandom();
  };

  Polynomial(Eigen::Tensor<double, 3> _c)
      : c(std::move(_c))
  {
    for (int i = 0; i < 3; i++) {
      order[i] = c.dimension(i) - 1;
    }
  };

  double derivative(const Point &x, const std::array<size_t, 3> &deriv) const;

  double operator()(const Point &x) const { return derivative(x, {0, 0, 0}); };
  double dx(const Point &x) const { return derivative(x, {1, 0, 0}); };
  double dy(const Point &x) const { return derivative(x, {0, 1, 0}); };
  double dz(const Point &x) const { return derivative(x, {0, 0, 1}); };
  double dxdy(const Point &x) const { return derivative(x, {1, 1, 0}); };
  double dxdz(const Point &x) const { return derivative(x, {1, 0, 1}); };
  double dydz(const Point &x) const { return derivative(x, {0, 1, 1}); };
  double dxdydz(const Point &x) const { return derivative(x, {1, 1, 1}); };
  double d2x(const Point &x) const { return derivative(x, {2, 0, 0}); };
  double d2y(const Point &x) const { return derivative(x, {0, 2, 0}); };
  double d2z(const Point &x) const { return derivative(x, {0, 0, 2}); };

  Eigen::Tensor<double, 3> getCoef() const { return c; };
  std::array<long, 3> getOrder() const { return order; };

private:
  std::array<long, 3> order;
  Eigen::Tensor<double, 3> c;
};

class Sine : public ReferenceFunction
{
public:
  Sine();
  Sine(std::array<double, 3> _c)
      : c(std::move(_c)){};

  double derivative(const Point &x, const std::array<size_t, 3> &deriv) const;

  double operator()(const Point &x) const { return derivative(x, {0, 0, 0}); };
  double dx(const Point &x) const { return derivative(x, {1, 0, 0}); };
  double dy(const Point &x) const { return derivative(x, {0, 1, 0}); };
  double dz(const Point &x) const { return derivative(x, {0, 0, 1}); };
  double dxdy(const Point &x) const { return derivative(x, {1, 1, 0}); };
  double dxdz(const Point &x) const { return derivative(x, {1, 0, 1}); };
  double dydz(const Point &x) const { return derivative(x, {0, 1, 1}); };
  double dxdydz(const Point &x) const { return derivative(x, {1, 1, 1}); };
  double d2x(const Point &x) const { return derivative(x, {2, 0, 0}); };
  double d2y(const Point &x) const { return derivative(x, {0, 2, 0}); };
  double d2z(const Point &x) const { return derivative(x, {0, 0, 2}); };

private:
  std::array<double, 3> c;
};

template<typename T>
class RescaledFunction : public ReferenceFunction
{
public:
  RescaledFunction(T fun, Point x0, Point x1)
      : fun(std::move(fun))
      , x0(std::move(x0))
      , x1(std::move(x1)){};

  Point rescale(const Point &x) const
  {
    return Point((x[0] - x0[0]) / (x1[0] - x0[0]),
                 (x[1] - x0[1]) / (x1[1] - x0[1]),
                 (x[2] - x0[2]) / (x1[2] - x0[2]));
  };
  double operator()(const Point &x) const
  {
    return fun.operator()(rescale(x));
  };
  double dx(const Point &x) const
  {
    return fun.dx(rescale(x)) / (x1[0] - x0[0]);
  };
  double dy(const Point &x) const
  {
    return fun.dy(rescale(x)) / (x1[1] - x0[1]);
  };
  double dz(const Point &x) const
  {
    return fun.dz(rescale(x)) / (x1[2] - x0[2]);
  };
  double dxdy(const Point &x) const
  {
    return fun.dxdy(rescale(x)) / ((x1[0] - x0[0]) * (x1[1] - x0[1]));
  };
  double dxdz(const Point &x) const
  {
    return fun.dxdz(rescale(x)) / ((x1[0] - x0[0]) * (x1[2] - x0[2]));
  };
  double dydz(const Point &x) const
  {
    return fun.dydz(rescale(x)) / ((x1[2] - x0[2]) * (x1[2] - x0[2]));
  };
  double dxdydz(const Point &x) const
  {
    return fun.dxdydz(rescale(x))
           / ((x1[0] - x0[0]) * (x1[1] - x0[1]) * (x1[2] - x0[2]));
  };
  double d2x(const Point &x) const
  {
    return fun.d2x(rescale(x)) / ((x1[0] - x0[0]) * (x1[0] - x0[0]));
  };
  double d2y(const Point &x) const
  {
    return fun.d2y(rescale(x)) / ((x1[1] - x0[1]) * (x1[1] - x0[1]));
  };
  double d2z(const Point &x) const
  {
    return fun.d2z(rescale(x)) / ((x1[2] - x0[2]) * (x1[2] - x0[2]));
  };

private:
  T fun;
  Point x0;
  Point x1;
};

#endif
