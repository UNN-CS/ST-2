// Copyright 2025 Salaev Vladislav
#include "circle.h"
#include <cmath>

#define PI 3.14159265358979323846

Circle::Circle(double r) : radius(r) {
    updateFerence();
    updateArea();
}

void Circle::setRadius(double r) {
    radius = r;
    updateFerence();
    updateArea();
}

void Circle::setFerence(double f) {
    ference = f;
    updateRadiusFromFerence();
    updateArea();
}

void Circle::setArea(double a) {
    area = a;
    updateRadiusFromArea();
    updateFerence();
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

void Circle::updateFerence() {
    ference = 2 * PI * radius;
}

void Circle::updateArea() {
    area = PI * radius * radius;
}

void Circle::updateRadiusFromFerence() {
    radius = ference / (2 * PI);
}

void Circle::updateRadiusFromArea() {
    radius = std::sqrt(area / PI);
}
