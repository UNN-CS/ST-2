// Copyright 2024 Tushentsova Karina

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
 private:
    double radius;
    double ference;
    double area;

 public:
    explicit Circle(double radius);

    double getRadius() const;

    double getFerence() const;

    double getArea() const;

    void setRadius(double radius);

    void setFerence(double ference);

    void setArea(double area);
};


#endif  // INCLUDE_CIRCLE_H_
