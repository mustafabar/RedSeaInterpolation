#include "interpolation.h"
#include "referencefunctions.h"

#include "Eigen/Dense"

#include "gtest/gtest.h"
#include <array>
#include <cmath>
#include <random>
#include <utility>

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

void polynomialTest(long order)
{
  std::array<long, 3> orderArray = {order, order, order};
  Polynomial fun(orderArray);
  std::array<Point, 2> corners{Point({0, 0, 0}), Point({1, 1, 1})};
  double tol = 1e-12;
  auto poly = computeInterpolationPolynomial(fun, corners);
  Point u({0.5, 0.5, 0.5});
  EXPECT_NEAR(poly(u), fun(u), tol);
  EXPECT_LT((poly.grad(u) - fun.grad(u)).norm(), tol * fun.grad(u).norm());
  EXPECT_LT((poly.hess(u) - fun.hess(u)).norm(), tol * fun.hess(u).norm());
}

TEST(InterpolationTest, Polynomial_3) { polynomialTest(3); }

TEST(InterpolationTest, Polynomial_2) { polynomialTest(2); }

TEST(InterpolationTest, Polynomial_1) { polynomialTest(1); }

void rescaleHelper(const std::array<Point, 2> &corners, double tol)
{
  std::array<long, 3> orderArray = {3, 3, 3};
  Polynomial fun(orderArray);
  auto poly = computeInterpolationPolynomial(fun, corners);

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<> uni;
  Point x(0, 0, 0);
  for (int i = 0; i < 3; i++) {
    x[i] = uni(mt) * (corners[1][i] - corners[0][i]) + corners[0][i];
  }
  EXPECT_NEAR(poly(x), fun(x), tol);
  EXPECT_LT((poly.grad(x) - fun.grad(x)).norm(), tol * fun.grad(x).norm());
  EXPECT_LT((poly.hess(x) - fun.hess(x)).norm(), tol * fun.hess(x).norm());
}

TEST(InterpolationTest, Rescale)
{
  double tol = 1e-11;
  rescaleHelper({Point(0, 0, 0), Point(1, 1, 1)}, tol);
  rescaleHelper({Point(-1, -1, -1), Point(1, 1, 1)}, tol);
  rescaleHelper({Point(0, 0, 0), Point(2, 2, 2)}, tol);
  rescaleHelper({Point(1, 1, 1), Point(-1, -1, -1)}, tol);
}
