// Copyright 2025 UNN-CS
#include "circle.h"
#include <cmath>

static constexpr double PI = 3.14159265358979323846;

void Circle::updateCircumference() {
  circumference = 2 * PI * radius;
}

void Circle::updateArea() {
  areaValue = PI * radius * radius;
}

Circle::Circle(double initialRadius) : radius(initialRadius) {
  updateCircumference();
  updateArea();
}

void Circle::setRadius(double newRadius) {
  radius = newRadius;
  updateCircumference();
  updateArea();
}

void Circle::setFerence(double newCircumference) {
  circumference = newCircumference;
  radius = circumference / (2 * PI);
  updateArea();
}

void Circle::setArea(double newArea) {
  areaValue = newArea;
  radius = std::sqrt(areaValue / PI);
  updateCircumference();
}

double Circle::getRadius() const {
  return radius;
}

double Circle::getFerence() const {
  return circumference;
}

double Circle::getArea() const {
  return areaValue;
}
