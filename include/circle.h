// Copyright 2024 Stepan Morgachev
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cstdint>
#include <cmath>

class Circle {
 private:
    double radius;
    double area;
    double ference;
    const double PI = 3.14159;

 public:
    explicit Circle(double radius);

    double getRadius() const;

    double getArea() const;

    double getFerence() const;

    void setRadius(double radius);

    void setArea(double area);

    void setFerence(double ference);

 private:
    void calculateArea();

    void calculateFerence();
};

#endif  // INCLUDE_CIRCLE_H_
