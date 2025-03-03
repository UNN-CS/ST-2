// Copyright 2022 UNN-CS
#include "tasks.h"
#include <cmath>
#include "circle.h"
double calculateGap() {
    double earthRadius = 6378100;
    Circle earth(earthRadius);
    double ropeLength = earth.getFerence() + 1;
    earth.setFerence(ropeLength);
    double gap = earth.getRadius() - earthRadius;
    return gap;
}

double calculatePoolCost() {
    double poolRadius = 3;
    double pathWidth = 1;
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double concreteArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    double concreteCost = concreteArea * 1000;
    double fenceCost = fenceLength * 2000;
    return concreteCost + fenceCost;
}