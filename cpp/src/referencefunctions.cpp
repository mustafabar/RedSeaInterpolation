#include "referencefunctions.h"

#include <numeric>
#include <random>

Eigen::Vector3d ReferenceFunction::grad(const Point &x) const
{
  return {dx(x), dy(x), dz(x)};
}

Eigen::Matrix3d ReferenceFunction::hess(const Point &x) const
{
  Eigen::Matrix3d h;
  h(0, 0) = d2x(x);
  h(0, 1) = dxdy(x);
  h(0, 2) = dxdz(x);
  h(1, 0) = h(0, 1);
  h(1, 1) = d2y(x);
  h(1, 2) = dydz(x);
  h(2, 0) = h(0, 2);
  h(2, 1) = h(1, 2);
  h(2, 2) = d2z(x);
  return h;
}

double differentiate_monomial(double x, int p, int deriv)
{
  double v = std::pow(x, p - deriv);
  if (deriv == 0){ return v; };
  for (int i = 0; i < deriv; i++) {
    v *= p - i;
  }
  return v;
}

double Polynomial::derivative(const Point &x,
                              const std::array<size_t, 3> &deriv) const
{
  double v = 0;
  for (int i = deriv[0]; i < order[0] + 1; i++) {
    for (int j = deriv[1]; j < order[1] + 1; j++) {
      for (int k = deriv[2]; k < order[2] + 1; k++) {
        v += c(i, j, k) * differentiate_monomial(x[0], i, deriv[0])
             * differentiate_monomial(x[1], j, deriv[1])
             * differentiate_monomial(x[2], k, deriv[2]);
      }
    }
  }
  return v;
}

Sine::Sine()
{
  std::random_device rd;
  std::mt19937 mt;
  std::uniform_real_distribution<> uni;
  for (auto &&i : c) {
    i = uni(mt);
  }
}

double Sine::derivative(const Point &x,
                        const std::array<size_t, 3> &deriv) const
{
  double cx = 0;
  double y = 0;
  for (int i = 0; i < 3; i++) {
    cx += c[i] * x[i];
  }
  size_t n_deriv = std::accumulate(deriv.begin(), deriv.end(), size_t(0));
  y = std::pow(-1.0, std::floor(static_cast<double>(n_deriv) / 2));
  if (n_deriv % 2 != 0) {
    y *= std::sin(cx);
  } else {
    y *= std::cos(cx);
  }
  for (int i = 0; i < 3; i++) {
    auto ci = std::pow(c[i], deriv[i]);
    y *= ci;
  }
  return y;
}
