// Copyright 2024 Marina Saratova
#include <cstdint>
#include <stdexcept>
#include "circle.h"

const double Circle::PI = std::atan(1.0) * 4;

void Circle::ValidateNotNegative(double val) {
    if (val < 0) throw std::logic_error("value must be not negative");
}

Circle::Circle(double radius) {
    ValidateNotNegative(radius);
    this->radius = radius;
    this->area = PI * radius * radius;
    this->ference = 2 * PI * radius;
}

void Circle::setRadius(double radius) {
    ValidateNotNegative(radius);
    this->radius = radius;
    this->area = PI * radius * radius;
    this->ference = 2 * PI * radius;
}

void Circle::setFerence(double ference) {
    ValidateNotNegative(ference);
    this->setRadius(ference / 2 / PI);
}

void Circle::setArea(double area) {
    ValidateNotNegative(area);
    this->setRadius(sqrt(area / PI));
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
