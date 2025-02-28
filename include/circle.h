// Copyright 2025 ovVrLFg8ks
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept>

class Circle {
 private:
  double radius, ference, area;

 public:
  Circle(double radius) { this->setRadius(radius); };

  void setRadius(double r);
  void setFerence(double f);
  void setArea(double a);

  double getRadius(void);
  double getFerence(void);
  double getArea(void);
};

#endif  // INCLUDE_CIRCLE_H_
