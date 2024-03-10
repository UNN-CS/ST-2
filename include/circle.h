// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <math.h>
#include <cstdint>
#include <cmath>
#include <stdexcept>

class Circle{
 private:
    double radius;
    double ference;
    double area;

 public:
    explicit Circle(double radius);
    double getRadius();
    double getFerence();
    double getArea();
    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);
};
#endif  // INCLUDE_CIRCLE_H_
