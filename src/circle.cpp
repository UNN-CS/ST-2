// Copyright 2022 UNN-CS
#include "circle.h"

#include <cmath>
#include <stdexcept>

namespace {
double Pi() {
  return std::acos(-1.0);
}
}

Circle::Circle(double radius) {
  setRadius(radius);
}

void Circle::setRadius(double radius) {
  if (radius < 0.0) {
    throw std::invalid_argument("radius must be non-negative");
  }
  radius_ = radius;
  ference_ = 2.0 * Pi() * radius_;
  area_ = Pi() * radius_ * radius_;
}

void Circle::setFerence(double ference) {
  if (ference < 0.0) {
    throw std::invalid_argument("ference must be non-negative");
  }
  ference_ = ference;
  radius_ = ference_ / (2.0 * Pi());
  area_ = Pi() * radius_ * radius_;
}

void Circle::setArea(double area) {
  if (area < 0.0) {
    throw std::invalid_argument("area must be non-negative");
  }
  area_ = area;
  radius_ = std::sqrt(area_ / Pi());
  ference_ = 2.0 * Pi() * radius_;
}

double Circle::getRadius() const {
  return radius_;
}

double Circle::getFerence() const {
  return ference_;
}

double Circle::getArea() const {
  return area_;
}

