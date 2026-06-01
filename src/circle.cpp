// Copyright 2025 UNN-CS

#include "circle.h"

#include <cmath>

static const double PI = 3.14159265358979323846;

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    this->radius = radius;
    this->ference = 2 * PI * radius;
    this->area = PI * radius * radius;
}

void Circle::setFerence(double ference) {
    this->ference = ference;
    this->radius = ference / (2 * PI);
    this->area = PI * radius * radius;
}

void Circle::setArea(double area) {
    this->area = area;
    this->radius = std::sqrt(area / PI);
    this->ference = 2 * PI * radius;
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
