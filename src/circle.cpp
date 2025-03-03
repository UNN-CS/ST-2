// Copyright 2025

#include "circle.h"
#include <cmath>


Circle::Circle(double r) {
    if (r >= 0) {
        radius = r;
        recalculateFromRadius();
	}
    else {
        radius = 0;
        ference = 0;
        area = 0;
	}
}

void Circle::recalculateFromRadius() {
    ference = 2 * PI * radius;
    area = PI * radius * radius;
}

void Circle::recalculateFromFerence() {
    radius = ference / (2 * PI);
    area = PI * radius * radius;
}

void Circle::recalculateFromArea() {
    radius = sqrt(area / PI);
    ference = 2 * PI * radius;
}

void Circle::setRadius(double r) {
    if (r >= 0) {
        radius = r;
        recalculateFromRadius();
	}
}

void Circle::setFerence(double f) {
    if (f >= 0) {
        ference = f;
        recalculateFromFerence();
	}
}

void Circle::setArea(double a) {
    if (a >= 0) {
        area = a;
        recalculateFromArea();
	}
}

double Circle::getRadius() { return radius; }

double Circle::getFerence() { return ference; }

double Circle::getArea() { return area; }
