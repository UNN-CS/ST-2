#include <cmath>
#include "circle.h"

const double PI = 3.14159265358979323846;

Circle::Circle(double r) : radius(r), ference(0.0), area(0.0) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    if (r >= 0) {
        radius = r;
        ference = 2 * PI * radius;
        area = PI * radius * radius;
    }
}

void Circle::setFerence(double f) {
    if (f >= 0) {
        ference = f;
        radius = ference / (2 * PI);
        area = PI * radius * radius;
    }
}

void Circle::setArea(double a) {
    if (a >= 0) {
        area = a;
        radius = sqrt(area / PI);
        ference = 2 * PI * radius;
    }
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
