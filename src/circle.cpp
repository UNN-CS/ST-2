// Copyright 2022 UNN-CS

#include "circle.h"

#include <cmath>
#include <stdexcept>

namespace {
const double kPi = std::acos(-1.0);
}

Circle::Circle(double radius)
    : radius_(radius), length_(0.0), area_(0.0) {
    if (radius < 0) {
        throw std::invalid_argument("Negative radius");
    }

    updateFromRadius();
}

void Circle::updateFromRadius() {
    length_ = 2.0 * kPi * radius_;
    area_ = kPi * radius_ * radius_;
}

void Circle::updateFromLength() {
    radius_ = length_ / (2.0 * kPi);
    area_ = kPi * radius_ * radius_;
}

void Circle::updateFromArea() {
    radius_ = std::sqrt(area_ / kPi);
    length_ = 2.0 * kPi * radius_;
}

void Circle::setRadius(double radius) {
    if (radius < 0) {
        throw std::invalid_argument("Negative radius");
    }

    radius_ = radius;
    updateFromRadius();
}

void Circle::setFerence(double length) {
    if (length < 0) {
        throw std::invalid_argument("Negative circumference");
    }

    length_ = length;
    updateFromLength();
}

void Circle::setArea(double area) {
    if (area < 0) {
        throw std::invalid_argument("Negative area");
    }

    area_ = area;
    updateFromArea();
}

double Circle::getRadius() const {
    return radius_;
}

double Circle::getFerence() const {
    return length_;
}

double Circle::getArea() const {
    return area_;
}
