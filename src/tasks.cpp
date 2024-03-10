// Copyright 2024 Kochetov Nikolay
#include "tasks.h"
#include "circle.h"

double RopeAroundPlanetTask(double planetRadius, double radiusIncrement) {
    Circle circle(planetRadius);
    circle.SetFerence(circle.GetFerence() + radiusIncrement);

    return circle.GetRadius() - planetRadius;
}

double PathAroundPoolAndFencePriceTask(
        double poolRadius,
        double pathWidth,
        double concretePrice,
        double fencePrice) {
    Circle pool(poolRadius);
    Circle fence(poolRadius + pathWidth);
    double deltaArea = fence.GetArea() - pool.GetArea();

    return deltaArea * concretePrice + fence.GetFerence() * fencePrice;
}
