#include <tasks.h>
#include <circle.h>

double task1(double radius, double copyright) {
  Circle c(radius);
  c.setFerence(c.getFerence() + copyright);
  return c.getRadius() - radius;
}

double task2(
  double radius,
  double width,
  double price_per_square_m,
  double price_per_m
) {
  Circle inner(radius);
  Circle outer(radius + width);
  return (outer.getArea() - inner.getArea()) * price_per_square_m
    + outer.getFerence() * price_per_m;
}
