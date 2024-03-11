// Copyright 2024 Kirillov Maxim
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include "../include/circle.h"

const double PI = 3.14159265358979323846264;

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    if (radius <= 0)
        throw std::invalid_argument("Radius must be greater than 0");
    this->radius = radius;
    ference = 2 * PI * radius;
    area = PI * radius * radius;
}

void Circle::setFerence(double ference) {
    if (ference <= 0)
        throw std::invalid_argument("Ference must be greater than 0");
    this->ference = ference;
    radius = ference / (2 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double area) {
    if (area <= 0)
        throw std::invalid_argument("Area must be greater than 0");
    this->area = area;
    radius = sqrt(area / PI);
    ference = 2 * PI * radius;
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


