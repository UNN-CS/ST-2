// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include "circle.h"

Circle::Circle(double r) {
  setRadius(r);
}

void Circle::setRadius(double r) {
  radius = r;
  ference = 2 * 3.141592653589793 * radius;
  area = 3.141592653589793 * radius * radius;
}

void Circle::setFerence(double f) {
  ference = f;
  radius = f / (2 * 3.141592653589793);
  area = 3.141592653589793 * radius * radius;
}

void Circle::setArea(double a) {
  area = a;
  radius = sqrt(a / 3.141592653589793);
  ference = 2 * 3.141592653589793 * radius;
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
