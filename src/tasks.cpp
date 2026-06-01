// Copyright 2025 UNN-CS

#include "tasks.h"

#include "circle.h"

double earthRopeGap() {
    const double earthRadius = 6378.1 * 1000;
    const double addedLength = 1.0;

    Circle earth(earthRadius);

    double newFerence = earth.getFerence() + addedLength;
    Circle rope(earthRadius);
    rope.setFerence(newFerence);

    return rope.getRadius() - earth.getRadius();
}

double poolConcreteCost() {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;
    const double concretePrice = 1000.0;

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();

    return pathArea * concretePrice;
}

double poolFenceCost() {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;
    const double fencePrice = 2000.0;

    Circle poolWithPath(poolRadius + pathWidth);

    return poolWithPath.getFerence() * fencePrice;
}

double poolTotalCost() {
    return poolConcreteCost() + poolFenceCost();
}
