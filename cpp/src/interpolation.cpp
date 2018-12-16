#include "interpolation.h"
#include "interpolationmatrix.h"

#include "unsupported/Eigen/CXX11/Tensor"

#include <cmath>
#include <iostream>


RescaledFunction<Polynomial> tricubic_interpolate(const InterpolationParameter &p,
                                      Point corner0,
                                      Point corner1)
{
  double hx = corner1[0] - corner0[0];
  double hy = corner1[1] - corner0[1];
  double hz = corner1[2] - corner0[2];
  Eigen::VectorXd temp(64);
  for (size_t i = 0; i < 8; i++) {
    temp(i) = p.f[i];
    temp(i + 8) = p.dfdx[i] * hx;
    temp(i + 16) = p.dfdy[i] * hy;
    temp(i + 24) = p.dfdz[i] * hz;
    temp(i + 32) = p.d2fdxdy[i] * hx * hy;
    temp(i + 40) = p.d2fdxdz[i] * hx * hz;
    temp(i + 48) = p.d2fdydz[i] * hy * hz;
    temp(i + 56) = p.d3fdxdydz[i] * hx * hy * hz;
  }
  Eigen::VectorXd a = A * temp;
  Eigen::Tensor<double, 3> c(4, 4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        c(i, j, k) = a[i + 4 * j + 16 * k];
      }
    }
  }
  return RescaledFunction<Polynomial>(Polynomial(c), corner0, corner1);
}
