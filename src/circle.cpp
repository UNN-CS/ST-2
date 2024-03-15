// Copyright 2024 Tushentsova Karina

#include <cstdint>
#include <stdexcept>
#include <cmath>
#include "circle.h"

const double PI = 3.14159;

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

void Circle::setRadius(double radius) {
    if (radius <= 0.0) {
        throw std::invalid_argument("radius");
    }
    Circle::radius = radius;
    Circle::ference = 2.0 * PI * Circle::radius;
    Circle::area = PI * Circle::radius * Circle::radius;
}

void Circle::setFerence(double ference) {
    if (ference <= 0.0) {
        throw std::invalid_argument("ference");
    }
    Circle::ference = ference;
    Circle::radius = Circle::ference / (PI * 2);
    Circle::area = Circle::radius * Circle::radius * PI;
}

void Circle::setArea(double area) {
    if (area <= 0.0) {
        throw std::invalid_argument("area");
    }
    Circle::area = area;
    Circle::radius = sqrt(Circle::area / PI);
    Circle::ference = 2.0 * PI * Circle::radius;
}

Circle::Circle(double radius) {
    setRadius(radius);
}
