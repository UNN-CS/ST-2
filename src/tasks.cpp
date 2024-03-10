// Copyright 2024 Stepan Morgachev
#include "tasks.h"
#include "circle.h"

double solvePlanetAndRopeTask(double planetRadius, double radiusIncrement) {
    Circle circle(planetRadius);
    circle.setFerence(circle.getFerence() + radiusIncrement);

    return circle.getRadius() - planetRadius;
}

double solveSwimmingPoolTask(double poolRadius,
                             double pathWidth,
                             double costOfCoverage,
                             double fencePrice) {
    auto pool = Circle(poolRadius);
    auto poolWithArea = Circle(poolRadius + pathWidth);

    return (poolWithArea.getArea() - pool.getArea()) * costOfCoverage
           + poolWithArea.getFerence() * fencePrice;
}
