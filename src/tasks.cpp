// Copyright 2025

#include "circle.h"
#include "tasks.h"

double earthAndRope(double earthRadius, double addedLength) {
    Circle earth(earthRadius * 1000); // converting km to m

    double initialFerence = earth.getFerence();
    earth.setFerence(initialFerence + addedLength);

    double gap = earth.getRadius() - (earthRadius * 1000); // gap value in meters
    return gap;
}

double pool(double poolRadius, double walkwayWidth, 
    double concreteCostPerM2, double fenceCostPerM) {
    Circle pool(poolRadius);
    double poolArea = pool.getArea();

    // outer circle (pool + walkway)
    Circle outer(poolRadius + walkwayWidth);
    double outerArea = outer.getArea();
    double outerFerence = outer.getFerence();

    double walkwayArea = outerArea - poolArea;

    double walkwayCost = walkwayArea * concreteCostPerM2;
    double fenceCost = outerFerence * fenceCostPerM;

    // total cost of materials
    return walkwayCost + fenceCost;
}
