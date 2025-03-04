// Copyright 2025 Dmitry kavtorev
#pragma once
#include <cstdint>
#include <cmath>

class Circle {
 private:
    static void ValidateNotNegative(double val);
    double radius;
    double ference;
    double area;
 public:
    static const double PI;
    explicit Circle(double radius = 0);
    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);
    double getRadius();
    double getFerence();
    double getArea();
};
