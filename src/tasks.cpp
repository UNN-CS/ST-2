#include "tasks.h"
#include <cmath>
#include <cstdint>

double calculateGap(double earthRadius, double addedLength)
{
    Circle earth(earthRadius);
    double originalFerence = earth.getFerence();
    earth.setFerence(originalFerence + addedLength);
    double newRadius = earth.getRadius();
    return newRadius - earthRadius;
}

double calculatePoolCosts(double poolRadius, double pathWidth, double concreteCostPerSqMeter, double fenceCostPerMeter)
{
    Circle pool(poolRadius);
    double poolArea = pool.getArea();

    Circle outer(poolRadius + pathWidth);
    double outerArea = outer.getArea();
    double pathArea = outerArea - poolArea;

    double concreteCost = pathArea * concreteCostPerSqMeter;
    double fenceCost = outer.getFerence() * fenceCostPerMeter;

    return concreteCost + fenceCost;
}