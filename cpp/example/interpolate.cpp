#include "referencefunctions.h"
#include "interpolation.h"

#include <cmath>
#include <iostream>
#include <random>

void print_gradient(const Eigen::Vector3d &grad)
{
  for (int i = 0; i < 3; i++) {
    std::cout << grad(i) << ' ';
  }
  std::cout << std::endl;
}

void print_hessian(const Eigen::Matrix3d &hess)
{
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << hess(i, j) << ' ';
    }
    std::cout << std::endl;
  }
}

RescaledFunction<Polynomial>
computeInterpolationPolynomial(const ReferenceFunction &fun,
                               const std::array<Point, 2> &corners)
{
  InterpolationParameter param;
  int c = 0;
  for (int k = 0; k < 2; k++) {
    for (int j = 0; j < 2; j++) {
      for (int i = 0; i < 2; i++) {
        Point x(corners[i][0], corners[j][1], corners[k][2]);
        param.f[c] = fun(x);
        param.dfdx[c] = fun.dx(x);
        param.dfdy[c] = fun.dy(x);
        param.dfdz[c] = fun.dz(x);
        param.d2fdxdy[c] = fun.dxdy(x);
        param.d2fdxdz[c] = fun.dxdz(x);
        param.d2fdydz[c] = fun.dydz(x);
        param.d3fdxdydz[c] = fun.dxdydz(x);
        c += 1;
      }
    }
  }
  return tricubic_interpolate(param, corners[0], corners[1]);
}

int main()
{
  std::array<Point, 2> corners{Point({2, 2, 2}), Point({-1, -1, -1})};

  std::array<long, 3> orderArray = {3, 3, 3};
  Polynomial fun(orderArray);
  auto poly = computeInterpolationPolynomial(fun, corners);

  Point x(0.5, 0.6, 0.7);

  std::cout << fun(x) << std::endl;
  std::cout << poly(x) << std::endl;

  print_gradient(fun.grad(x));
  print_gradient(poly.grad(x));
  return 0;
}
