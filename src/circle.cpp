// Copyright 2026 NNTU-CS
#include "circle.h"
#include <cmath>

static const double PI = acos(-1.0);

Circle::Circle(double r) {
    setRadius(r);
}
void Circle::setRadius(double r) {
    radius = r;
    ference = 2.0 * PI * r;
    area = PI * r * r;
}
void Circle::setFerence(double f) {
    ference = f;
    radius = f / (2.0 * PI);
    area = PI * radius * radius;
}
void Circle::setArea(double a) {
    area = a;
    radius = sqrt(a / PI);
    ference = 2.0 * PI * radius;
}
double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }
