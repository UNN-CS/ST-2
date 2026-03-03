// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(double _radius) {
    if (_radius <= 0) {
        throw std::invalid_argument("Radius must be positive");
    }

    radius = _radius;
    ference = 2.0 * PI * radius;
    area = PI * radius * radius;
}

void Circle::setRadius(double _radius) {
    if (_radius <= 0) {
        throw std::invalid_argument("Radius must be positive");
    }

    radius = _radius;
    ference = 2.0 * PI * radius;
    area = PI * radius * radius;
}

void Circle::setFerence(double _ference) {
    if (_ference <= 0) {
        throw std::invalid_argument("Circumference must be positive");
    }

    ference = _ference;
    radius = ference / (2.0 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double _area) {
    if (_area <= 0) {
        throw std::invalid_argument("Area must be positive");
    }

    area = _area;
    radius = std::sqrt(area / PI);
    ference = 2.0 * PI * radius;
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
