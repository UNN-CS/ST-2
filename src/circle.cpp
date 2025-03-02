// Copyright 2022 UNN-CS
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
    try {
        if (radius < 0.0) {
            throw std::invalid_argument("Radius cannot be negative.");
        }
        this->radius = radius;
        this->ference = 2 * PI * radius;
        this->area = PI * radius * radius;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "setRadius error: " << e.what() << std::endl;
        throw;
    }
}

void Circle::setFerence(double ference) {
    try {
        if (radius < 0.0) {
            throw std::invalid_argument("Radius cannot be negative.");
        }
        this->ference = ference;
        this->radius = ference / (2 * PI);
        this->area = PI * radius * radius;
    }
    catch (const std::invalid_argument &e) {
        std::cerr << "setFerence error: " << e.what() << std::endl;
        throw;
    }
}

void Circle::setArea(double area) {
    try {
        if (radius < 0.0) {
            throw std::invalid_argument("Radius cannot be negative.");
        }
        this->area = area;
        this->radius = sqrt(area / PI);
        this->ference = 2 * PI * radius;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "setArea error: " << e.what() << std::endl;
        throw;
    }
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }
