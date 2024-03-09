// Copyright 2024 Kiselev_IS
#include "circle.h"

double const PI = 3.14159265358979323846;

void circle::setRadius(double rad) {
    if (rad < 0) throw "Trying to set negative radius";
    radius = rad;
    ferense = 2 * rad * PI;
    area = PI * rad * rad;
}

void circle::setFerense(double fer) {
    if (fer < 0) throw "Trying to set negative Ferense";
    ferense = fer;
    radius = fer / (2 * PI);
    area = radius * fer / 2;
}

void circle::setArea(double ar) {
    if (ar < 0) throw "Trying to set negative Area";
    area = ar;
    radius = sqrt(ar / PI);
    ferense = 2 * ar / radius;
}

double circle::getArea() {
    return area;
}

double circle::getFerense() {
    return ferense;
}

double circle::getRadius() {
    return radius;
}
