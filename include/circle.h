// Copyright 2024 Kirillov Maxim
#pragma once
#include <cstdint>

class Circle {
 private:
    double radius;
    double ference;
    double area;
 public:
    explicit Circle(double radius);
    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);
    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};
