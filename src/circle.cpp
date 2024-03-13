// Copyright 2024 Smirnov Leonid
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

double const Circle::PI = std::atan(1.0) * 4;

double Circle::CheckingTheInputData(double value) {
    if (value < 0) {
        throw std::invalid_argument("The value must be greater than zero");
    }
    return value;
}

Circle::Circle(double radiusValue) {
    radius = CheckingTheInputData(radiusValue);
    ference = 2 * PI * radius;
    area = PI * radius * radius;
}

double Circle::GetRadius() const {
    return radius;
}

double Circle::GetFerence() const {
    return ference;
}

double Circle::GetArea() const {
    return area;
}

void Circle::SetRadius(double value) {
    radius = CheckingTheInputData(value);
    ference = radius * 2 * PI;
    area = radius * radius * PI;
}

void Circle::SetFerence(double value) {
    ference = CheckingTheInputData(value);
    radius = ference / (2 * PI);
    area = radius * radius * PI;
}

void Circle::SetArea(double value) {
    area = CheckingTheInputData(value);
    radius = std::sqrt(area / PI);
    ference = radius * 2 * PI;
}
