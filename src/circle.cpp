// Copyright 2024 Chuvashov Andrey
#include <cstdint>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double r) {
    checkOnNegative(r);
    this->radius = r;
    countFerence();
    countArea();
}

void Circle::checkOnNegative(double value) {
    if (value < 0) throw std::logic_error("invalid value");
}

void Circle::countFerence() {
    this->ference = 2 * PI * radius;
}

void Circle::countArea() {
    this->area = PI * radius * radius;
}

void Circle::setRadius(double r) {
    checkOnNegative(r);
    this->radius = r;
    countFerence();
    countArea();
}

void Circle::setFerence(double f) {
    checkOnNegative(f);
    this->ference = f;
    this->radius = f / (2 * PI);
    countArea();
}

void Circle::setArea(double a) {
    checkOnNegative(a);
    this->area = a;
    this->radius = sqrt(a / PI);
    countFerence();
}

double Circle::getRadius() {
    return radius;
}

double Circle::getFerence() {
    return ference;
}

double Circle::getArea() {
    return area;
}
