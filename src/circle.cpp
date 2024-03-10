// Copyright 2022 UNN-CS
#include "../include/circle.h"

Circle::Circle(double radius) {
    if (radius <= 0.0) {
        throw std::invalid_argument("Radius cannot be negative or zero");
    }
    this->radius = radius;
    ference = 2 * M_PI * this->radius;
    area = M_PI * this->radius * this->radius;
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
void Circle::setRadius(double radius) {
    if (radius <= 0.0) {
        throw std::invalid_argument("Radius cannot be negative or zero");
    }
    this->radius = radius;
    this->ference = 2 * M_PI * this->radius;
    this->area = M_PI * this->radius * this->radius;
}

void Circle::setFerence(double ference) {
    if (ference <= 0.0) {
        throw std::invalid_argument("Ference cannot be negative or zero");
    }
    this->ference = ference;
    this->radius = ference / (2 * M_PI);
    this->area = M_PI * this->radius * this->radius;
}

void Circle::setArea(double area) {
    if (area <= 0.0) {
        throw std::invalid_argument("Area cannot be negative or zero");
    }
    this->area = area;
    this->radius = std::sqrt(area/M_PI);
    this->ference = 2 * M_PI * this->radius;
}
