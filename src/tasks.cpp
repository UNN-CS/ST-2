// Copyright 2026 NNTU-CS
#include "tasks.h"
#include "circle.h"

double ropeGap() {
    double earthRadius = 6378100.0;
    Circle earth(earthRadius);
    Circle rope(0.0);
    rope.setFerence(earth.getFerence() + 1.0);
    return rope.getRadius() - earthRadius;
}
double poolConcreteCost() {
    Circle pool(3.0);
    Circle outer(4.0);
    double concreteArea = outer.getArea() - pool.getArea();
    return concreteArea * 1000.0;
}
double poolFenceCost() {
    Circle outer(4.0);
    return outer.getFerence() * 2000.0;
}
