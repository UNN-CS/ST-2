// Copyright 2022 UNN-CS
#include <cmath>
#include "circle.h"

namespace {
const double kPi = 3.14159265358979323846;
}  // namespace

Circle::Circle(double r) {
  setRadius(r);
}

void Circle::setRadius(double r) {
  radius = r;
  ference = 2.0 * kPi * radius;
  area = kPi * radius * radius;
}

void Circle::setFerence(double f) {
  ference = f;
  radius = ference / (2.0 * kPi);
  area = kPi * radius * radius;
}

void Circle::setArea(double a) {
  area = a;
  radius = std::sqrt(area / kPi);
  ference = 2.0 * kPi * radius;
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
