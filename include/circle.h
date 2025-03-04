// Copyright 2025 Odintsov_M

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cstdint>

class Circle {
  private:
    double radius;
    double ference;
    double area;

  public:
    Circle();
    Circle(double r, double f, double a);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius();
    double getFerence();
    double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
