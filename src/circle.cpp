// Copyright 2024 Kochetov Nikolay
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

Circle::Circle(double radius) {
    SetRadius(radius);
}

double Circle::GetRadius() const {
    return _radius;
}

double Circle::GetArea() const {
    return _area;
}

double Circle::GetFerence() const {
    return _ference;
}

void Circle::SetRadius(double radius) {
    ThrowErrorIfValueIsNotPositive(radius, "radius");
    _radius = radius;
    _ference = 2.0 * M_PI * _radius;
    _area = M_PI * std::pow(_radius, 2);
}

void Circle::SetArea(double area) {
    ThrowErrorIfValueIsNotPositive(area, "area");
    _area = area;
    _radius = sqrt(_area * M_1_PI);
    _ference = 2.0 * M_PI * _radius;
}

void Circle::SetFerence(double ference) {
    ThrowErrorIfValueIsNotPositive(ference, "ference");
    _ference = ference;
    _radius = 0.5 * _ference * M_1_PI;
    _area =  M_PI * std::pow(_radius, 2);
}

void Circle::ThrowErrorIfValueIsNotPositive(
        double value,
        const std::string& nameOfVariable) {
    if (value <= 0.0) {
        throw std::invalid_argument(nameOfVariable + " must be positive");
    }
}
