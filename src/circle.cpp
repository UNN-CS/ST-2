// Copyright 2024 Timofey Vinichuk
#include <cmath>
#include <stdexcept>

#include "circle.h"

circle::circle(double radius) {
    if (radius <= 0)
        throw std::invalid_argument("radius cant be negative or null");
    this->_radius = radius;
    this->_ference = 2 * M_PI * radius;
    this->_area = M_PI * radius * radius;
}

void circle::setRadius(double radius) {
    if (radius <= 0)
        throw std::invalid_argument("radius cant be negative or null");
    this->_radius = radius;
    this->_ference = 2 * M_PI * radius;
    this->_area = M_PI * radius * radius;
}

void circle::setFerence(double ference) {
    if (ference <= 0)
        throw std::invalid_argument("ference cant be negative or null");
    this->_ference = ference;
    this->_radius = ference / (2 * M_PI);
    this->_area = M_PI * this->_radius * this->_radius;
}

void circle::setArea(double area) {
    if (area <= 0)
        throw std::invalid_argument("area cant be negative or null");
    this->_area = area;
    this->_radius = sqrt(area / (M_PI));
    this->_ference = 2 * M_PI * this->_radius;
}

double circle::getRadius() {
    return this->_radius;
}

double circle::getFerence() {
    return this->_ference;
}

double circle::getArea() {
    return this->_area;
}
