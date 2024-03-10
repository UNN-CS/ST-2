// Copyright 2024 Stepan Morgachev
#include <stdexcept>
#include "circle.h"

double Circle::getRadius() const {
    return radius;
}

double Circle::getArea() const {
    return area;
}

double Circle::getFerence() const {
    return ference;
}

void Circle::calculateArea() {
    area = PI * radius * radius;
}

void Circle::calculateFerence() {
    ference = 2 * PI * radius;
}

void Circle::setRadius(double radius) {
    if (radius <= 0.0) {
        throw std::invalid_argument("radius is must be positive");
    }
    Circle::radius = radius;
    calculateArea();
    calculateFerence();
}

void Circle::setArea(double area) {
    if (area <= 0.0) {
        throw std::invalid_argument("area is must be positive");
    }
    Circle::area = area;
    radius = sqrt(area / PI);
    calculateFerence();
}

void Circle::setFerence(double ference) {
    if (ference <= 0.0) {
        throw std::invalid_argument("ference is must be positive");
    }
    Circle::ference = ference;
    radius = ference / (2 * PI);
    calculateArea();
}

Circle::Circle(double radius) {
    setRadius(radius);
}
