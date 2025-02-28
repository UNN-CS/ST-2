// Copyright 2025 ovVrLFg8ks

#include "circle.h"

void Circle::setRadius(double r) {
  if (r < 0)
    throw std::invalid_argument("the argument must have a non-negative value");
  radius = r;
  ference = 2 * M_PI * r;
  area = M_PI * r * r;
}

void Circle::setFerence(double f) {
  if (f < 0)
    throw std::invalid_argument("the argument must have a non-negative value");
  ference = f;
  radius = f / (2 * M_PI);
  area = M_PI * radius * radius;
}

void Circle::setArea(double a) {
  if (a < 0)
    throw std::invalid_argument("the argument must have a non-negative value");
  area = a;
  radius = std::sqrt(a / M_PI);
  ference = 2 * M_PI * radius;
}

double Circle::getRadius() { return radius; }

double Circle::getFerence() { return ference; }

double Circle::getArea() { return area; }
