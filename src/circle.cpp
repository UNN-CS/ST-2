// Copyright 2024 Fedor Khodyrev
#include <cstdint>
#include <stdexcept>
#include "circle.h"

Circle::Circle() {
    radius = 0.0;
    ference = 0.0;
    area = 0.0;
}

Circle::Circle(double r) {
    if (r < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
    radius = r;
    calculateArea();
    calculateFerence();
}

void Circle::setRadius(double r) {
    if (r < 0) {
        throw std::invalid_argument("Радиус не может быть отрицательным");
    }
    radius = r;
    calculateArea();
    calculateFerence();
}

void Circle::setFerence(double f) {
    if (f < 0) {
        throw std::invalid_argument
        ("Длина окружности не может быть отрицательной");
    }
    ference = f;
    radius = ference / (2 * PI);
    calculateArea();
}

void Circle::setArea(double a) {
    if (a < 0) {
        throw std::invalid_argument("Площадь не может быть отрицательной");
    }
    area = a;
    radius = sqrt(area / PI);
    calculateFerence();
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

void Circle::calculateArea() {
    area = PI * radius * radius;
}

void Circle::calculateFerence() {
    ference = 2 * PI * radius;
}
