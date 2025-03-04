// Copyright 2025 Kalinin Dmitriy
#pragma once
#include <cmath>
class Circle {
 private:
    static const double PI;
    static void IsNegative(double value);
    double radius;
    double ference;
    double area;
 public:
    explicit Circle(double radius = 0);
    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);
    double getRadius();
    double getFerence();
    double getArea();
};
