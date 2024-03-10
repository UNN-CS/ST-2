// Copyright 2024 Moiseev Nikita
#include "circle.h"
#include <cmath>
#include <cstdint>


Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double radius) {
    this->radius = radius;
    ference = 2 * M_PI * radius;
    area = M_PI * radius * radius;
}

void Circle::setFerence(double ference) {
    this->ference = ference;
    radius = ference / (2 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::setArea(double area) {
    this->area = area;
    radius = sqrt(area / M_PI);
    ference = 2 * M_PI * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
