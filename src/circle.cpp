// Copyright 2022 UNN-CS
#include "circle.h"

#include <cmath>
#include <stdexcept>

namespace {
constexpr double kPi = 3.14159265358979323846;
}

Circle::Circle(double radius) : radius_(0.0), ference_(0.0), area_(0.0) {
    setRadius(radius);
}

void Circle::updateFromRadius() {
    ference_ = 2.0 * kPi * radius_;
    area_ = kPi * radius_ * radius_;
}

void Circle::updateFromFerence() {
    radius_ = ference_ / (2.0 * kPi);
    area_ = kPi * radius_ * radius_;
}

void Circle::updateFromArea() {
    radius_ = std::sqrt(area_ / kPi);
    ference_ = 2.0 * kPi * radius_;
}

void Circle::setRadius(double radius) {
    if (radius < 0.0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    radius_ = radius;
    updateFromRadius();
}

void Circle::setFerence(double ference) {
    if (ference < 0.0) {
        throw std::invalid_argument("Ference cannot be negative");
    }
    ference_ = ference;
    updateFromFerence();
}

void Circle::setArea(double area) {
    if (area < 0.0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    area_ = area;
    updateFromArea();
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
