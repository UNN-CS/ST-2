// Copyright 2024 Filatov Maxim
#include "tasks.h"
#include "circle.h"

double ropeAroundPlanetTask(double planetRadius, double radiusIncrement) {
    Circle circle(planetRadius);
    circle.setFerence(circle.getFerence() + radiusIncrement);
    return circle.getRadius() - planetRadius;
}

double pathAroundPoolAndFencePriceTask(
        double poolRadius,
        double pathWidth,
        double concretePrice,
        double fencePrice) {
    Circle pool(poolRadius);
    Circle fence(poolRadius + pathWidth);
    return (fence.getArea() - pool.getArea()) * concretePrice
        + fence.getFerence() * fencePrice;
}
