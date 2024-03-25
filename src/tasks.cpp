// Copyright 2024 Marina Saratova
#include "tasks.h"
#include "circle.h"

double EarthAndRopeSolve(double earthRadius, double growth) {
    Circle earth(earthRadius);
    Circle rope;
    rope.setFerence(earth.getFerence() + growth);
    return rope.getRadius() - earth.getRadius();
}

double SwimmingPoolSolve(double poolRadiusMeter, double areaWidthMeter,
    double areaPricePerSquareMeter, double ferencePricePerMeter) {
    Circle pool = Circle(poolRadiusMeter);
    Circle poolAndArea = Circle(poolRadiusMeter + areaWidthMeter);
    double ferencePrice = poolAndArea.getFerence() * ferencePricePerMeter;
    double areaPrice = (poolAndArea.getArea() - pool.getArea())
        * areaPricePerSquareMeter;
    return ferencePrice + areaPrice;
}
