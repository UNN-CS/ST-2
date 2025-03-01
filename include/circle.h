// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
#include <cmath>

const double PI = 3.14159265358979323846264;

class Circle {

private:
    double radius;
    double ference;
    double area;

public:
    void setRadius(double _r);
    void setFerence(double _f);
    void setArea(double _a);
    double getRadius();
    double getFerence();
    double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
