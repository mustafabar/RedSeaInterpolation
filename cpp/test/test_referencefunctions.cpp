#include "referencefunctions.h"

#include "Eigen/Dense"

#include "gtest/gtest.h"
#include <array>
#include <cmath>
#include <random>

double fun(const Point &x)
{
  return 1 + x[0] + x[1] * x[1] + x[2] * x[2] * x[2];
}

TEST(ReferenceFunctionTest, Polynomial)
{
  Eigen::Tensor<double, 3> c(4, 4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        c(i, j, k) = 0;
      }
    }
  }
  c(0, 0, 0) = 1;
  c(1, 0, 0) = 1;
  c(0, 2, 0) = 1;
  c(0, 0, 3) = 1;
  Polynomial poly(c);
  auto order = poly.getOrder();
  for (int i = 0; i < 3; i++) {
    std::cout << order[i] << std::endl;
  }

  Point x(1, 2, 3);

  double tol = 1e-14;
  EXPECT_NEAR(poly(x), fun(x), tol);
  EXPECT_NEAR(poly.dx(x), 1, tol);
  EXPECT_NEAR(poly.d2x(x), 0, tol);
  EXPECT_NEAR(poly.dy(x), 2 * x[1], tol);
  EXPECT_NEAR(poly.d2y(x), 2, tol);
  EXPECT_NEAR(poly.dz(x), 3 * x[2] * x[2], tol);
  EXPECT_NEAR(poly.d2z(x), 6 * x[2], tol);
  EXPECT_NEAR(poly.dxdy(x), 0, tol);
  EXPECT_NEAR(poly.dxdz(x), 0, tol);
  EXPECT_NEAR(poly.dydz(x), 0, tol);
  EXPECT_NEAR(poly.dxdydz(x), 0, tol);
}
