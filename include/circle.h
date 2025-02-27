// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cmath>
#include <stdexcept>

class Circle {
 private:
  double radius;
  double ference;
  double area;

  void updateFerence() {
    ference = 2 * M_PI * radius;
  }

  void updateArea() {
    area = M_PI * radius * radius;
  }

 public:
  explicit Circle(double r) {
    if (r <= 0) throw std::invalid_argument("Radius must be positive");
    radius = r;
    updateFerence();
    updateArea();
  }

  void setRadius(double r) {
    if (r <= 0) throw std::invalid_argument("Radius must be positive");
    radius = r;
    updateFerence();
    updateArea();
  }

  void setFerence(double f) {
    if (f <= 0) throw std::invalid_argument("Ference must be positive");
    ference = f;
    radius = f / (2 * M_PI);
    updateArea();
  }

  void setArea(double a) {
    if (a <= 0) throw std::invalid_argument("Area must be positive");
    area = a;
    radius = sqrt(a / M_PI);
    updateFerence();
  }

  double getRadius() const {
    return radius;
  }

  double getFerence() const {
    return ference;
  }

  double getArea() const {
    return area;
  }
};

#endif // INCLUDE_CIRCLE_H_
