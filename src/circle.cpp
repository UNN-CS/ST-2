// Copyright 2024 Nazyrov A.A.

#include "circle.h"
#include <cmath>

namespace geometry {

static const double PI = 3.14159265358979323846;

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::updateFromRadius() {
    circumference_ = 2.0 * PI * radius_;
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromCircumference() {
    radius_ = circumference_ / (2.0 * PI);
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromArea() {
    radius_ = std::sqrt(area_ / PI);
    circumference_ = 2.0 * PI * radius_;
}

void Circle::setRadius(double radius) {
    if (radius >= 0.0) {
        radius_ = radius;
        updateFromRadius();
    }
}

void Circle::setCircumference(double circumference) {
    if (circumference >= 0.0) {
        circumference_ = circumference;
        updateFromCircumference();
    }
}

void Circle::setArea(double area) {
    if (area >= 0.0) {
        area_ = area;
        updateFromArea();
    }
}

double Circle::getRadius() const {
    return radius_;
}

double Circle::getCircumference() const {
    return circumference_;
}

double Circle::getArea() const {
    return area_;
}

}  // namespace geometry
