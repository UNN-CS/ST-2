// Copyright 2025 Odintsov
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cstdint>

class Circle {
private:
  double radius;
  double ference;
  double area;

public:
  Circle(double r, double f, double a) {
    radius = r;
    ference = f;
    area = a;
  }
  Circle();

  void setRadius(double r);
  void setFerence(double f);
  void setArea(double a);

  double getRadius();
  double getFerence();
  double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
