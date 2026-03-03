// Copyright 2022 UNN-CS
#include <cstdint>
#include <math.h>
#include <stdexcept>
#include "circle.h"

Circle::Circle() {
    radius = 0.0; // R 
    ference = 0.0; // pi R^2
    area = 0.0; // 2 pi R 
}

void Circle::setRadius(double _radius) {
    if (_radius < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    radius = _radius;
    ference = 2.0 * pi * radius;
    area = pi * radius * radius;
}

void Circle::setFerence(double _ference) {
    if (_ference < 0) {
        throw std::invalid_argument("Ference cannot be negative");
    }
    ference = _ference;
    radius = ference/(2.0 * pi);
    area = pi * radius * radius;
}

void Circle::setArea(double _area) {
    if (_area < 0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    area = _area;
    radius = sqrt(area/pi);
    ference = 2.0 * pi * radius;
}

double Circle::getRadius() {
    return radius;
}

double Circle::getFerence() {
    return ference;
}

double Circle::getArea() {
    return area;
}