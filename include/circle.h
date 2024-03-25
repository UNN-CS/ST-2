// Copyright 2024 Marina Saratova
#pragma once
#include <cstdint>
#include <cmath>

class Circle {
 private:
    static const double PI;
    static void ValidateNotNegative(double val);
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
