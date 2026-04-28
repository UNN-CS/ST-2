// Copyright 2026 UNN-CS
#include "tasks.h"

#include <stdexcept>

#include "circle.h"

double earthRopeGap(double earthRadiusKm, double addedRopeMeters) {
    if (earthRadiusKm < 0.0) {
        throw std::invalid_argument("Earth radius cannot be negative");
    }
    if (addedRopeMeters < 0.0) {
        throw std::invalid_argument("Added rope length cannot be negative");
    }

    Circle earth(earthRadiusKm * 1000.0);
    const double originalFerence = earth.getFerence();

    earth.setFerence(originalFerence + addedRopeMeters);
    return earth.getRadius() - earthRadiusKm * 1000.0;
}

double poolConcreteCost(double poolRadiusMeters,
                        double pathWidthMeters,
                        double costPerSquareMeter) {
    if (poolRadiusMeters < 0.0 || pathWidthMeters < 0.0 || costPerSquareMeter < 0.0) {
        throw std::invalid_argument("Pool parameters cannot be negative");
    }

    Circle inner(poolRadiusMeters);
    Circle outer(poolRadiusMeters + pathWidthMeters);
    const double pathArea = outer.getArea() - inner.getArea();
    return pathArea * costPerSquareMeter;
}

double poolFenceCost(double poolRadiusMeters,
                     double pathWidthMeters,
                     double costPerMeter) {
    if (poolRadiusMeters < 0.0 || pathWidthMeters < 0.0 || costPerMeter < 0.0) {
        throw std::invalid_argument("Pool parameters cannot be negative");
    }

    Circle fence(poolRadiusMeters + pathWidthMeters);
    return fence.getFerence() * costPerMeter;
}
