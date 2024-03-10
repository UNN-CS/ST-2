// Copyright 2024 Filatov Maxim
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double radius) {
    if (radius <= 0.0) {
        throw std::invalid_argument("radius");
    }
    Circle::radius = radius;
    Circle::ference = 2.0 * M_PI * Circle::radius;
    Circle::area = M_PI * Circle::radius * Circle::radius;
}

double Circle::getArea() const {
    return area;
}

void Circle::setArea(double area) {
    if (area <= 0.0) {
        throw std::invalid_argument("area");
    }
    Circle::area = area;
    Circle::radius = sqrt(Circle::area * M_1_PI);
    Circle::ference = 2.0 * M_PI * Circle::radius;
}

double Circle::getFerence() const {
    return ference;
}

void Circle::setFerence(double ference) {
    if (ference <= 0.0) {
        throw std::invalid_argument("ference");
    }
    Circle::ference = ference;
    Circle::radius = Circle::ference * M_1_PI * 0.5;
    Circle::area = Circle::radius * Circle::radius * M_PI;
}

Circle::Circle(double radius) {
    setRadius(radius);
}
