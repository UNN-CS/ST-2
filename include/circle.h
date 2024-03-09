// Copyright 2024 Chuvashov Andrey
#pragma once
#include <cmath>

class Circle {
 private:
    const double PI = 3.14159;
    double radius;
    double ference;
    double area;
    void checkOnNegative(double value);
    void countFerence();
    void countArea();
 public:
    explicit Circle(double r);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius();
    double getFerence();
    double getArea();
};
