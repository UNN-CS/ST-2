// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

#include <cstdint>

const double PI = 3.141592653589793;

void Circle::updateFromRadius() {
  ference = 2 * PI * radius;
  area = PI * radius * radius;
}

void Circle::updateFromFerence() {
  radius = ference / (2 * PI);
  area = PI * radius * radius;
}

void Circle::updateFromArea() {
  radius = sqrt(area / PI);
  ference = 2 * PI * radius;
}

Circle::Circle(double r) : radius(r) {
  updateFromRadius();
}

void Circle::setRadius(double r) {
  radius = r;
  updateFromRadius();
}

void Circle::setFerence(double f) {
  ference = f;
  updateFromFerence();
}

void Circle::setArea(double a) {
  area = a;
  updateFromArea();
}

double Circle::getRadius() {
  return radius;
}

double Circle::getFerence() {
  return ference;
}

double Circle::getArea() {
  return area;
}

