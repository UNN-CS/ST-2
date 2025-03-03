// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double calculateGap() {
    double earthRadius = 6378100;
    Circle earth(earthRadius);
    double originalFerence = earth.getFerence();
    double newFerence = originalFerence + 1;
    earth.setFerence(newFerence);
    double newRadius = earth.getRadius();
    return newRadius - earthRadius;
}

double calculatePoolCost(double poolRadius, double pathWidth,
double concreteCostPerSquareMeter, double fenceCostPerMeter) {
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double totalConcreteCost = pathArea * concreteCostPerSquareMeter;
    double totalFenceCost = fenceLength * fenceCostPerMeter;

    return totalConcreteCost + totalFenceCost;
}
