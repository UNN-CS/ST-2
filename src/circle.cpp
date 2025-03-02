// Copyright 2022 UNN-CS
#include <cmath>
#include <cstdint>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double r) : radius(r) {
  calculateFerence();
  calculateArea();
}

void Circle::setRadius(double r) {
  if (r < 0) {
    throw std::invalid_argument("Radius cannot be negative");
  }
  radius = r;
  calculateFerence();
  calculateArea();
}

void Circle::setFerence(double f) {
  if (f < 0) {
    throw std::invalid_argument("Ference cannot be negative");
  }
  radius = f / (2 * M_PI);
  calculateFerence();
  calculateArea();
}

void Circle::setArea(double a) {
  if (a < 0) {
    throw std::invalid_argument("Area cannot be negative");
  }
  radius = sqrt(a / M_PI);
  calculateFerence();
  calculateArea();
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }

void Circle::calculateFerence() { ference = 2 * M_PI * radius; }

void Circle::calculateArea() { area = M_PI * radius * radius; }
