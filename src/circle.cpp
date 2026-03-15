// Copyright 2022 UNN-CS
#include <cmath>
#include <cstdint>
#include <stdexcept>
#include "circle.h"

const double PI = 3.14159265358979323846;

Circle::Circle(double radius){
    setRadius(radius);
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getArea() const {
    return area;
}

double Circle::getFerence() const {
    return ference;
}

void Circle::setRadius(double radius) {
    if (radius < 0.0) {
        throw std::invalid_argument("radius can't be < 0");
    }
    this->radius = radius;
    this->ference = 2*PI*radius;
    this->area = PI * radius * radius;
}

void Circle::setArea(double area) {
    if (area < 0.0) {
        throw std::invalid_argument("area can't be < 0");
    }
    this->area = area;
    this->radius = std::sqrt(area/PI);
    this->ference = 2*PI*radius;
}

void Circle::setFerence(double ference) {
    if (ference < 0.0) {
        throw std::invalid_argument("ference can't be < 0");
    }
    this->ference = ference;
    this->radius = ference/(2*PI);
    this->area = PI * radius * radius;
}

