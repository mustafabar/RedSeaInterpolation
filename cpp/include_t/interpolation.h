#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "point.h"
#include "referencefunctions.h"

#include <array>

struct InterpolationParameter {
  double f[8];
  double dfdx[8];
  double dfdy[8];
  double dfdz[8];
  double d2fdxdy[8];
  double d2fdxdz[8];
  double d2fdydz[8];
  double d3fdxdydz[8];
};

RescaledFunction<Polynomial> tricubic_interpolate(const InterpolationParameter &p,
                                      Point corner0 = Point(0, 0, 0),
                                      Point corner1 = Point(1, 1, 1));

#endif
