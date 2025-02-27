// Copyright 2022 UNN-CS
#include "../include/task.h"
#include <cmath>
#include "circle.h"

const double PI = 3.141592653589793;
double calculateRopeGap(double earthRadius, double ropeIncrease) {
    double newRadius = earthRadius + (ropeIncrease / (2 * PI));
    return newRadius - earthRadius;
}

double calculatePoolCost(double poolRadius, double pathWidth,
    double concreteCost, double fenceCost) {
    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    double pathArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getFerence();

    return (pathArea * concreteCost) + (fenceLength * fenceCost);
}
