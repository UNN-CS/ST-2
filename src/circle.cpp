// Copyright 2022 UNN-CS

#include "circle.h"
#include <cstdint>
#include <stdexcept>

const double PI = 3.14159;

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double radius) {
    if (radius <= 0.0) {
        throw std::invalid_argument("radius");
    }
    Circle::radius = radius;
    Circle::ference = 2.0 * PI * Circle::radius;
    Circle::area = PI * Circle::radius * Circle::radius;
}

void Circle::setFerence(double newFerence) {
    if (ference <= 0.0) {
        throw std::invalid_argument("ference");
    }
    Circle::ference = newFerence;
    Circle::radius = Circle::ference / (2 * PI);
    Circle::area = Circle::radius * Circle::radius * PI;
}

double Circle::getArea() const {
    return area;
}

void Circle::setArea(double newArea) {
    if (newArea <= 0.0) {
        throw std::invalid_argument("area");
    }
    Circle::area = newArea;
    Circle::radius = sqrt(Circle::area / PI);
    Circle::ference = 2.0 * PI * Circle::radius;
}

double Circle::getFerence() const {
    return ference;
}


Circle::Circle(double radius) {
    setRadius(radius);
}
