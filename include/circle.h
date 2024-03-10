// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
#include <cmath>

class Circle {
 private:
    double radius;
    double ference;
    double area;
 public:
    explicit Circle(double radius);

    double getRadius() const;

    void setRadius(double radius);

    double getArea() const;

    void setArea(double area);

    double getFerence() const;

    void setFerence(double ference);
};

#endif  // INCLUDE_CIRCLE_H_
