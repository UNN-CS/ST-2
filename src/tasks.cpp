// Copyright 2025 UNN-CS
#include "tasks.h"
#include <cmath>
#include <cstdint>

const double PI = 3.14159265358979323846;

double calculateGap(double earthRadius, double addedLength) {
    double newRadius = earthRadius + (addedLength / (2 * PI));
    return newRadius - earthRadius;
}
double calculatePoolCosts(double poolRadius, double pathWidth,
    double concreteCostPerSqMeter, double fenceCostPerMeter) {
    Circle pool(poolRadius);
    double poolArea = pool.getArea();

    Circle outer(poolRadius + pathWidth);
    double outerArea = outer.getArea();
    double pathArea = outerArea - poolArea;

    double concreteCost = pathArea * concreteCostPerSqMeter;
    double fenceCost = outer.getFerence() * fenceCostPerMeter;

    return concreteCost + fenceCost;
}
