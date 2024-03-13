// Copyright 2024 Smirnov Leonid

#include "tasks.h"
#include "circle.h"

double SolveEarthAndRope(double earthRadius, double ropelength) {
    Circle circle(earthRadius);
    Circle newcircle;
    newcircle.SetFerence(circle.GetFerence() + ropelength);
    return newcircle.GetRadius() - circle.GetRadius();
}

double SolveSwimmingPool(double poolRadiusMeter,
                         double areaWidthMeter,
                         double areaPricePerSquareMeter,
                         double ferencePricePerMeter) {
    Circle pool(poolRadiusMeter);
    Circle poolwitharea(poolRadiusMeter + areaWidthMeter);
    double ferencePrice = poolwitharea.GetFerence() *
        ferencePricePerMeter;
    double areaPrice = (poolwitharea.GetArea() - pool.GetArea()) *
        areaPricePerSquareMeter;
    return ferencePrice + areaPrice;
}
