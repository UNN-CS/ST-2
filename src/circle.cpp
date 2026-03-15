// Copyright 2022 UNN-CS

#include <cmath>
#include <stdexcept>

#include "circle.h"

Circle::Circle(double radius) : radius_(0.0), ference_(0.0), area_(0.0) {
    setRadius(radius);
}

void Circle::updateFromRadius() {
    ference_ = 2.0 * kPi * radius_;
    area_ = kPi * radius_ * radius_;
}

void Circle::setRadius(double radius) {
    if (radius < 0.0) {
        throw std::invalid_argument("Radius must be non-negative");
    }

    radius_ = radius;
    updateFromRadius();
}

void Circle::setFerence(double ference) {
    if (ference < 0.0) {
        throw std::invalid_argument("Ference must be non-negative");
    }

    radius_ = ference / (2.0 * kPi);
    updateFromRadius();
}

void Circle::setArea(double area) {
    if (area < 0.0) {
        throw std::invalid_argument("Area must be non-negative");
    }

    radius_ = std::sqrt(area / kPi);
    updateFromRadius();
}

double Circle::getRadius() const {
    return radius_;
}

double Circle::getFerence() const {
    return ference_;
}

double Circle::getArea() const {
    return area_;
}

