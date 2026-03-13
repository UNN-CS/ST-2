// Copyright 2022 UNN-CS
#include <cstdint>
#include "circle.h"

const double PI = 3.14159265358979323846;

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::updateFromRadius() {
    ference_ = 2 * PI * radius_;
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromFerence() {
    radius_ = ference_ / (2 * PI);
    area_ = PI * radius_ * radius_;
}

void Circle::updateFromArea() {
    radius_ = std::sqrt(area_ / PI);
    ference_ = 2 * PI * radius_;
}

void Circle::setRadius(double r) {
    radius_ = r;
    updateFromRadius();
}

void Circle::setFerence(double f) {
    ference_ = f;
    updateFromFerence();
}

void Circle::setArea(double a) {
    area_ = a;
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
