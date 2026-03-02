// Copyright 2022 UNN-CS
#include "circle.h"
#include <cstdint>

void Circle::updateFromRadius() {
  ference = 2.0 * M_PI * radius;
  area = M_PI * pow(radius, 2);
}

void Circle::updateFromFerence() {
  radius = ference / (2.0 * M_PI);
  area = M_PI * pow(radius, 2);
}

void Circle::updateFromArea() {
  radius = sqrt(area / M_PI);
  ference = 2.0 * M_PI * radius;
}

Circle::Circle(double r) : radius(r) { updateFromRadius(); }

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

double Circle::getRadius() { return radius; }

double Circle::getFerence() { return ference; }

double Circle::getArea() { return area; }