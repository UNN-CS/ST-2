// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
 private:
  double radius, ference, area;

 public:
  explicit Circle(double radius);
  void setRadius(double radius);
  void setFerence(double ference);
  void setArea(double area);
  double getRadius();
  double getFerence();
  double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
