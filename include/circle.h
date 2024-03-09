// Copyright 2024 Fedor Khodyrev
#pragma once
#include <cstdint>
#include <cmath>

class Circle {
 private:
    double radius;
    double ference;
    double area;
    const double PI = 3.14159;

 public:
    Circle();
    explicit Circle(double radius);
    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius();
    double getFerence();
    double getArea();

 private:
    void calculateFerence();
    void calculateArea();
};
