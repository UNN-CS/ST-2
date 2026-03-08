// Copyright 2025 UNN-CS
#include "tasks.h"

#include "circle.h"

namespace {
constexpr double kEarthRadiusMeters = 6378.1 * 1000.0;
constexpr double kAddedRopeLength = 1.0;

constexpr double kPoolRadius = 3.0;
constexpr double kPathWidth = 1.0;
constexpr double kConcretePricePerSquareMeter = 1000.0;
constexpr double kFencePricePerMeter = 2000.0;
}  // namespace

double earthRopeGap() {
    Circle earth(kEarthRadiusMeters);
    double oldRadius = earth.getRadius();

    earth.setFerence(earth.getFerence() + kAddedRopeLength);
    double newRadius = earth.getRadius();

    return newRadius - oldRadius;
}

double poolConcreteCost() {
    Circle pool(kPoolRadius);
    Circle outer(kPoolRadius + kPathWidth);

    double pathArea = outer.getArea() - pool.getArea();
    return pathArea * kConcretePricePerSquareMeter;
}

double poolFenceCost() {
    Circle outer(kPoolRadius + kPathWidth);
    return outer.getFerence() * kFencePricePerMeter;
}
