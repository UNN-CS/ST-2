// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

#include <cstdint>

const double PI = 3.141592653589793;

void Circle::UpdateFromRadius() {
  ference = 2 * PI * radius;
  area = PI * radius * radius;
}

void Circle::UpdateFromFerence() {
  radius = ference / (2 * PI);
  area = PI * radius * radius;
}

void Circle::UpdateFromArea() {
  radius = sqrt(area / PI);
  ference = 2 * PI * radius;
}

Circle::Circle(double r) : radius(r) {
  UpdateFromRadius();
}

void Circle::SetRadius(double r) {
  radius = r;
  UpdateFromRadius();
}

void Circle::SetFerence(double f) {
  ference = f;
  UpdateFromFerence();
}

void Circle::SetArea(double a) {
  area = a;
  UpdateFromArea();
}

double Circle::GetRadius() {
  return radius;
}

double Circle::GetFerence() {
  return ference;
}

double Circle::GetArea() {
  return area;
}
