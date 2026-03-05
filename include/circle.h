// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle
{
public:
    Circle(double radius);

    bool setRadius(double val);
    bool setFerence(double val);
    bool setArea(double val);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;

    static constexpr double PI = 3.14159265358979323846;
    
private:
    double radius, ference, area;
};

#endif  // INCLUDE_CIRCLE_H_
