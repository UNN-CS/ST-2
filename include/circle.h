// Copyright 2024 Kashin Stepan
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cstdint>
#include <cmath>
#include <cfloat>

#define PI 3.14159
#define RADIUS_MAX std::sqrt(DBL_MAX / PI)
#define FERENCE_MAX 2 * PI * RADIUS_MAX
#define AREA_MAX PI * pow(RADIUS_MAX, 2)

class Circle {
 private:
    double radius, ference, area;
    void defalt();
 public:
    Circle();
    bool setRadius(double newRadius);
    bool setFerence(double newFerence);
    bool setArea(double newArea);
    double getRadius();
    double getFerence();
    double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
