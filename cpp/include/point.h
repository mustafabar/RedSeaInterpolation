#ifndef POINT_H

#define POINT_H
#include <array>
#include <ostream>

class Point
{
public:
  Point(double x, double y, double z)
      : pos{x, y, z} {};
  Point(const double *x)
      : pos{x[0], x[1], x[2]} {};
  double operator[](size_t i) const { return pos[i]; };
  double &operator[](size_t i) { return pos[i]; };

private:
  std::array<double, 3> pos;
};

inline std::ostream &operator<<(std::ostream &stream, const Point &p)
{
  stream << p[0] << ' ' << p[1] << ' ' << p[2];
  return stream;
}

#endif
