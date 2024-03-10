// Copyright 2024 Moiseev Nikita
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>


class Circle {
 private:
    double radius;
    double ference;
    double area;

 public:
    explicit Circle(double radius = 0.0);

    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
