// Copyright 2022 UNN-CS
#include "circle.h"
#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(double radius) { setRadius(radius); }

void Circle::setRadius(double value) {
  radius = value;
  ference = 2.0 * M_PI * radius;
  area = M_PI * radius * radius;
}

void Circle::setFerence(double value) {
  ference = value;
  radius = ference / (2.0 * M_PI);
  area = M_PI * radius * radius;
}

void Circle::setArea(double value) {
  area = value;
  radius = sqrt(area / M_PI);
  ference = 2.0 * M_PI * radius;
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }
