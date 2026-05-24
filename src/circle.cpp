// Copyright 2026 Salykina Alena

#include "circle.h"

#include <cmath>
#include <stdexcept>

const double pi = 3.14159265358979323846;

Circle::Circle(double radius) {
    this->radius = radius;
    ference = 2 * pi * radius;
    area = pi * radius * radius;
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

void Circle::setRadius(double n_radius) {
    if (n_radius < 0) {
        throw std::invalid_argument("Radius cannot be negative");
    }

    radius = n_radius;
    ference = 2 * pi * radius;
    area = pi * radius * radius;
}

void Circle::setFerence(double n_ference) {
    if (n_ference < 0) {
        throw std::invalid_argument("Ference cannot be negative");
    }

    ference = n_ference;
    radius = ference / (2 * pi);
    area = pi * radius * radius;
}

void Circle::setArea(double n_area) {
    if (n_area < 0) {
        throw std::invalid_argument("Area cannot be negative");
    }

    area = n_area;
    radius = sqrt(n_area / pi);
    ference = 2 * pi * radius;
}

