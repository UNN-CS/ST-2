// Copyright 2025 Odintsov

#include "circle.h"  // Сначала идет include заголовочного файла
#include <cstdint>    // Затем C system headers
#include <cmath>      // Потом C++ system headers

const double PI = 3.141592653589793;

void Circle::setRadius(double r) {
  if (r <= 0) {
    return;
  }
  radius = r;
  ference = 2 * PI * radius;
  area = PI * radius * radius;
}

void Circle::setFerence(double f) {
  if (f <= 0) {
    return;
  }
  ference = f;
  radius = f / (2 * PI);
  area = PI * radius * radius;
}

void Circle::setArea(double a) {
  if (a <= 0) {
    return;
  }
  area = a;
  radius = std::sqrt(a / PI);
  ference = 2 * PI * radius;
}

double Circle::getRadius() {
  return radius;
}

double Circle::getArea() {
  return area;
}

double Circle::getFerence() {
  return ference;
}
