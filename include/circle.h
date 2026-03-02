// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cmath>
#include <cstdint>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Circle {
  double radius, ference, area;
  void updateFromRadius();
  void updateFromFerence();
  void updateFromArea();

public:
  explicit Circle(double radius = 0.0);
  void setRadius(double r);
  void setFerence(double f);
  void setArea(double a);
  double getRadius();
  double getFerence();
  double getArea();
};

#endif // INCLUDE_CIRCLE_H_
