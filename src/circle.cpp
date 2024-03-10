// Copyright 2024 Khramov Ivan
#include "../include/circle.h"

const double Circle::PI = std::acos(-1.0);

Circle::Circle(double radius) {
    this->radius = CheckValueError(radius);
    ComputeFerence();
    ComputeArea();
}

void Circle::SetFerence(double ference) {
    this->ference = CheckValueError(ference);
    this->radius = this->ference / (2 * PI);
    ComputeArea();
}

void Circle::SetRadius(double radius) {
    this->radius = CheckValueError(radius);
    ComputeFerence();
    ComputeArea();
}

void Circle::SetArea(double area) {
    this->area = CheckValueError(area);
    this->radius = sqrt(this->area / PI);
    ComputeFerence();
}

double Circle::GetRadius() const {
    return this->radius;
}

double Circle::GetFerence() const {
    return this->ference;
}

double Circle::GetArea() const {
    return this->area;
}

void Circle::ComputeFerence() {
    this->ference = 2 * PI * this->radius;
}

void Circle::ComputeArea() {
    this->area = pow(this->radius, 2) * PI;
}

double Circle::CheckValueError(double value) {
    if (value < 0)
        throw std::invalid_argument("value must be greater than or equal to 0");

    return value;
}
