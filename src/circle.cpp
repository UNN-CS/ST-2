// Copyright 2022 UNN-CS

#include "circle.h"
#include <cmath>
#include <cstdint>


const double pi = 3.14;

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    radius = r;
    ference = 2*pi*radius;
    area = pi*radius*radius;
}

void Circle::setFerence(double f) {
    ference = f;
    radius = ference/(2*pi);
    area = pi*std::pow(radius, 2);
}

void Circle::setArea(double a) {
    area = a;
    radius = std::sqrt(area/pi);
    ference = 2*pi*radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
