// Copyright 2025 shvedovav
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>
#include <cstdint>
#include "circle.h"

Circle::Circle(double r) {
  setRadius(r);
}
void Circle::setRadius(double r) {
  radius = r;
  ference = 2.0 * M_PI * r;
  area = M_PI * r * r;
}
void Circle::setFerence(double c) {
  ference = c;
  radius = c / (2.0 * M_PI);
  area = M_PI * radius * radius;
}
void Circle::setArea(double a) {
  area = a;
  radius = std::sqrt(a / M_PI);
  ference = 2.0 * M_PI * radius;
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
