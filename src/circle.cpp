// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include <stdexcept>

#include "circle.h"

constexpr double PI = 3.14159265358979323846;

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double r) {
    if (r < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    radius = r;
    ference = 2 * PI * radius;
    area = PI * radius * radius;
}

void Circle::setFerence(double f) {
    if (f < 0) {
        throw std::invalid_argument("Ference cannot be negative");
    }
    ference = f;
    radius = f / (2 * PI);
    area = PI * radius * radius;
}

void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    area = a;
    radius = sqrt(area / PI);
    ference = 2 * PI * radius;
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }
