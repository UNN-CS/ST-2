// Copyright 2025 UNN-CS

#include "tasks.h"
#include <cmath>
#include "circle.h"


const double pi = 3.14;

double earthRopeGap() {
    double earthRadius = 6378.1*1000;

    Circle earth(earthRadius);

    double newFerence = earth.getFerence()+1.0;

    Circle newEarth;
    newEarth.setFerence(newFerence);

    return newEarth.getRadius()-earth.getRadius();
}

double poolCost() {
    double poolRadius = 3.0;
    double pathWidth = 1.0;

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius+pathWidth);

    double pathArea = poolWithPath.getArea()-pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    double pathCost = pathArea*1000.0;
    double fenceCost = fenceLength*2000.0;

    return pathCost+fenceCost;
}
