// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

namespace {
constexpr double kEarthRadiusMeters = 6378.1 * 1000.0;
constexpr double kExtraRopeMeters = 1.0;

constexpr double kPoolRadiusMeters = 3.0;
constexpr double kPathWidthMeters = 1.0;
constexpr double kConcretePricePerSqMeter = 1000.0;
constexpr double kFencePricePerMeter = 2000.0;
}  // namespace

double earthRopeGap() {
    Circle earth(kEarthRadiusMeters);
    const double initialFerence = earth.getFerence();
    earth.setFerence(initialFerence + kExtraRopeMeters);
    return earth.getRadius() - kEarthRadiusMeters;
}

double poolConcreteArea() {
    Circle innerPool(kPoolRadiusMeters);
    Circle outerBorder(kPoolRadiusMeters + kPathWidthMeters);
    return outerBorder.getArea() - innerPool.getArea();
}

double poolConcreteCost() {
    return poolConcreteArea() * kConcretePricePerSqMeter;
}

double poolFenceLength() {
    Circle outerBorder(kPoolRadiusMeters + kPathWidthMeters);
    return outerBorder.getFerence();
}

double poolFenceCost() {
    return poolFenceLength() * kFencePricePerMeter;
}
