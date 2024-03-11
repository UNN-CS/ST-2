// Copyright 2024 Kirillov Maxim
#include <stdexcept>
#include "../include/tasks.h"
#include "../include/circle.h"

const double EARTH_RADIUS = 6378100;

double SolveEarthAndRope(double ropeLength) {
    if (ropeLength < 0)
        throw std::invalid_argument(
                "Rope's length must be greater than 0");
    Circle earth(EARTH_RADIUS);
    earth.setFerence(earth.getFerence() + ropeLength);
    return earth.getRadius() - EARTH_RADIUS;
}

double SolvePool(double poolRadius, double trackWidth,
                 double concreteCost, double fenceCost) {
    if (poolRadius <= 0 || trackWidth <= 0)
        throw std::invalid_argument("Values must be greater than 0");
    Circle pool(poolRadius);
    Circle poolWithTrack(poolRadius+trackWidth);
    double trackPrice = (poolWithTrack.getArea() - pool.getArea())
            * concreteCost;
    double fencePrice = poolWithTrack.getFerence() * fenceCost;
    return trackPrice + fencePrice;
}
