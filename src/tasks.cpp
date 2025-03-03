// Copyright 2025 Salaev Vladislav
#include "tasks.h"
#include "circle.h"

double calculateGapAfterAddingRope(double initialRadius, double addedLength) {
    Circle earthCircle(initialRadius);
    double initialFerence = earthCircle.getFerence();
    double newFerence = initialFerence + addedLength;
    earthCircle.setFerence(newFerence);
    return earthCircle.getRadius() - initialRadius;
}

double calculateCostForPool(double poolRadius,
    double pathWidth, double concreteCost, double fenceCost) {
    Circle pool(poolRadius);
    double poolArea = pool.getArea();

    Circle outer(poolRadius + pathWidth);
    double outerArea = outer.getArea();

    double pathArea = outerArea - poolArea;
    double pathCost = pathArea * concreteCost;

    double outerFerence = outer.getFerence();
    double fenceCostTotal = outerFerence * fenceCost;

    return pathCost + fenceCostTotal;
}
