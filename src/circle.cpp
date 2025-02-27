// Copyright 2022 UNN-CS
#define _USE_MATH_DEFINES

#include "circle.h"

#include <cmath>
#include <cstdint>
#include <stdexcept>

Circle::Circle(double radius) : radius(radius) {
  if (radius < 0) {
    throw std::invalid_argument("Radius cannot be negative");
  }
  calculateFromRadius();
}

void Circle::calculateFromRadius() {
  circumference = 2 * M_PI * radius;
  area = M_PI * radius * radius;
}

void Circle::calculateFromCircumference() {
  radius = circumference / (2 * M_PI);
  area = M_PI * radius * radius;
}

void Circle::calculateFromArea() {
  radius = std::sqrt(area / M_PI);
  circumference = 2 * M_PI * radius;
}

void Circle::setRadius(double radius) {
  if (radius < 0) {
    throw std::invalid_argument("Radius cannot be negative");
  }

  this->radius = radius;
  calculateFromRadius();
}

void Circle::setCircumference(double circumference) {
  if (circumference < 0) {
    throw std::invalid_argument("Circumference cannot be negative");
  }

  this->circumference = circumference;
  calculateFromCircumference();
}

void Circle::setArea(double area) {
  if (area < 0) {
    throw std::invalid_argument("Area cannot be negative");
  }

  this->area = area;
  calculateFromArea();
}

double Circle::getRadius() const { return radius; }

double Circle::getCircumference() const { return circumference; }

double Circle::getArea() const { return area; }
