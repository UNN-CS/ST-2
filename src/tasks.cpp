// Copyright 2024 Sokolova Daria

#include "tasks.h"
#include <circle.h>
#include <stdexcept>

double ropeTask(double addedLength) {
    if (addedLength < 0) throw
        std::logic_error("invalid error");
    const double planetRadius = 6378.1;
    Circle circle(planetRadius);
    circle.setFerence(circle.getFerence() + addedLength);

    return circle.getRadius() - planetRadius;
}
double swimmingPoolTask(double poolRadius,
    double pathWidth,
    double priceCoverage,
    double priceFence) {
    if (poolRadius <= 0 || pathWidth <= 0) throw
        std::logic_error("invalid error");
    Circle pool = Circle(poolRadius);
    Circle poolWithArea = Circle(poolRadius + pathWidth);
    double Coverage = (poolWithArea.getArea() -
        pool.getArea()) * priceCoverage;
    double Fence = poolWithArea.getFerence() * priceFence;
    return Coverage + Fence;
}
