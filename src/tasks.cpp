// Copyright 2022 UNN-CS
#include "../include/tasks.h"
#include "../include/circle.h"

double calculateRopeGap() {
    double earthRadiusM = 6378.1 * 1000.0;
    Circle earth(earthRadiusM);
    double originalFerence = earth.getFerence();
    double newFerence = originalFerence + 1.0;

    Circle newEarth(earthRadiusM);

    newEarth.setFerence(newFerence);
    double gap = newEarth.getRadius() - earth.getRadius();
    return gap;
}

void calculatePoolCosts(double* concreteCost, double* fenceCost) {
    double poolRadius = 3.0;
    double walkwayWidth = 1.0;
    Circle pool(poolRadius);
    Circle poolWithWalkway(poolRadius + walkwayWidth);

    double annulusArea = poolWithWalkway.getArea() - pool.getArea();
    *concreteCost = annulusArea * 1000;

    *fenceCost = poolWithWalkway.getFerence() * 2000;
}
