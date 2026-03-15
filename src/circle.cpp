// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double r) : radius(r) {
  ference = 2 * M_PI * radius;
  area = M_PI * radius * radius;
}

void Circle::setRadius(double r) {
  radius = r;
  ference = 2 * M_PI * radius;
  area = M_PI * radius * radius;
}

void Circle::setFerence(double c) {
  ference = c;
  radius = c / (2 * M_PI);
  area = M_PI * radius * radius;
}

void Circle::setArea(double a) {
  area = a;
  radius = std::sqrt(a / M_PI);
  ference = 2 * M_PI * radius;
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
