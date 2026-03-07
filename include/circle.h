// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cstdint>

#define PI 3.1415926535897932384626433832795028841971693

class Circle {
  double radius;
  double ference;
  double area;

 public:
  Circle();
  explicit Circle(double getR);
  void setRadius(double getR);
  void setFerence(double getF);
  void setArea(double getA);
  double getRadius();
  double getFerence();
  double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
