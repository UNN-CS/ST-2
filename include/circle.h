// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
private:
    double radius; 
    double ference;
    double area;
    const double pi = 3.1415926535;
public:
    Circle();

    void setRadius(double _radius);
    void setFerence(double _ference);
    void setArea(double _area);
    double getRadius();
    double getFerence();
    double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
