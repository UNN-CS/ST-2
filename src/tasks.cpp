//
// Created by Андрей Юрин on 08.03.2024.
//

#include "circle.h"

double ropeAroundPlanetTask(double planetRadius, double radiusIncrement) {
    Circle circle(planetRadius);
    circle.SetFerence(circle.GetFerence() + radiusIncrement);

    return circle.GetRadius() - planetRadius;
}

double pathAroundPoolAndFencePriceTask(
        double poolRadius,
        double pathWidth,
        double concretePrice,
        double fencePrice) {
    Circle pool(poolRadius);
    Circle fence(poolRadius + pathWidth);
    double deltaArea = fence.GetArea() - pool.GetArea();

    return deltaArea * concretePrice + fence.GetFerence() * fencePrice;
}
