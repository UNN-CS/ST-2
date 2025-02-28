// Copyright 2025 Vladlen Korablev
#include <cmath>
#include <cstdint>
#include "circle.h"

static const double pi = std::acos(-1.0);

Circle::Circle(double r) {
  setRadius(r);
}
void Circle::setRadius(double r) {
  radius = r;
  ference = 2.0 * pi * r;
  area = pi * r * r;
}
void Circle::setFerence(double c) {
  ference = c;
  radius = c / (2.0 * pi);
  area = pi * radius * radius;
}
void Circle::setArea(double a) {
  area = a;
  radius = std::sqrt(a / pi);
  ference = 2.0 * pi * radius;
}
double Circle::getRadius() const {
  return radius;
}
double Circle::getFerence() const {
  return ference;
}
double Circle::getArea() const {
  return area;
}


