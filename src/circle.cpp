// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include "circle.h"
Circle::Circle(double r) : radius(r) {
    calculateFerence();
    calculateArea();
}
void Circle::calculateFerence() {
    ference = 2 * M_PI * radius;
}
void Circle::calculateArea() {
    area = M_PI * radius * radius;
}
void Circle::setRadius(double r) {
    radius = r;
    calculateFerence();
    calculateArea();
}
void Circle::setFerence(double f) {
    ference = f;
    radius = ference / (2 * M_PI);
    calculateArea();
}
void Circle::setArea(double a) {
    area = a;
    radius = sqrt(area / M_PI);
    calculateFerence();
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
