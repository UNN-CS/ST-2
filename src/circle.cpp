// Copyright 2024 Kashin Stepan
#include <cstdint>
#include "circle.h"

Circle::Circle() {
    defalt();
}

bool Circle::setRadius(double newRadius) {
    if (newRadius < 0 || newRadius > RADIUS_MAX) {
        defalt();
        return false;
    }

    radius = newRadius;
    ference = 2 * PI * newRadius;
    area = PI * pow(newRadius, 2);
    return true;
}

bool Circle::setFerence(double newFerence) {
    return setRadius(newFerence / (PI * 2));
}

bool Circle::setArea(double newArea) {
    if (newArea < 0) {
        defalt();
        return false;
    }
    return setRadius(std::sqrt(newArea / PI));
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

void Circle::defalt() {
    radius = -1;
    ference = -1;
    area = -1;
}

