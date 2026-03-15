// Copyright 2026 UNN-CS
#include "circle.h"

#include <cmath>
#include <stdexcept>

namespace {

constexpr double kPi() noexcept {
  return 3.14159265358979323846264338327950288;
}

}  // namespace

Circle::Circle(double radius) {
  setRadius(radius);
}

void Circle::recalcFromRadius() {
  ference_ = 2.0 * kPi() * radius_;
  area_ = kPi() * radius_ * radius_;
}

void Circle::recalcFromFerence() {
  radius_ = ference_ / (2.0 * kPi());
  recalcFromRadius();
}

void Circle::recalcFromArea() {
  radius_ = std::sqrt(area_ / kPi());
  recalcFromRadius();
}

void Circle::setRadius(double radius) {
  if (radius < 0.0) {
    throw std::invalid_argument("Radius must be non-negative");
  }
  radius_ = radius;
  recalcFromRadius();
}

void Circle::setFerence(double ference) {
  if (ference < 0.0) {
    throw std::invalid_argument("Ference must be non-negative");
  }
  ference_ = ference;
  recalcFromFerence();
}

void Circle::setArea(double area) {
  if (area < 0.0) {
    throw std::invalid_argument("Area must be non-negative");
  }
  area_ = area;
  recalcFromArea();
}

double Circle::getRadius() const noexcept {
  return radius_;
}

double Circle::getFerence() const noexcept {
  return ference_;
}

double Circle::getArea() const noexcept {
  return area_;
}
