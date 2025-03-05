// Copyright 2025 UNN-CS
#include "circle.h"
#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept>

const double PI = 3.14159265358979323846;

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    if (radius < 0.0) {
        throw std::invalid_argument("Radius cannot be negative.");
    }
    this->radius = radius;
    this->ference = 2 * PI * radius;
    this->area = PI * radius * radius;
}

void Circle::setFerence(double ference) {
    if (ference < 0.0) {
        throw std::invalid_argument("Ference cannot be negative.");
    }
    this->ference = ference;
    this->radius = ference / (2 * PI);
    this->area = PI * radius * radius;
}

void Circle::setArea(double area) {
    if (area < 0.0) {
        throw std::invalid_argument("Area cannot be negative.");
    }
    this->area = area;
    this->radius = sqrt(area / PI);
    this->ference = 2 * PI * radius;
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }
