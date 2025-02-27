// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
#include <cmath>

class Circle {
private:
  double radius;
  double ference;
  double area;

  void updateFerence() {
    ference = 2 * 3.14159265358979323846 * radius;
  }

  void updateArea() {
    area = 3.14159265358979323846 * radius * radius;
  }

public:
  Circle(double r) : radius(r) {
    updateFerence();
    updateArea();
  }

  void setRadius(double r) {
    radius = r;
    updateFerence();
    updateArea();
  }

  void setFerence(double f) {
    ference = f;
    radius = f / (2 * 3.14159265358979323846);
    updateArea();
  }

  void setArea(double a) {
    area = a;
    radius = sqrt(a / 3.14159265358979323846);
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

#endif  // INCLUDE_CIRCLE_H_
