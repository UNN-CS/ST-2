// Copyright 2022 UNN-CS
#include <cmath>
#include "circle.h"

const double PI = 3.14159265358979323846;

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    if (r < 0) {
        r = 0;
    }

    radius = r;
    radius = r;
    updateFerence();
    updateArea();
}

void Circle::setFerence(double f) {
    if (f < 0) {
        f = 0;
    }

    radius = f / (2 * PI);
    updateFerence();
    updateArea();
}

void Circle::setArea(double a) {
    if (a < 0) {
        a = 0;
    }
    radius = sqrt(a / PI);
    updateFerence();
    updateArea();
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
