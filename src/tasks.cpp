// Copyright 2024 Chuvashov Andrey
#include <stdexcept>
#include "tasks.h"

double RopeTask(double extraLength) {
    if (extraLength < 0) throw std::logic_error("invalid error");
    const double eRadius = 6378.1;
    Circle oldCircleLength = Circle(eRadius);
    Circle newCircleLength = Circle(eRadius + extraLength / 1000);
    return newCircleLength.getArea() - oldCircleLength.getArea();
}

double SwimmingPoolTask(double poolRadius, double roadWidth) {
    double roadPrice = 1000, fencePrice = 2000;
    Circle poolCircle = Circle(poolRadius);
    Circle poolAndRoadCircle = Circle(poolRadius + roadWidth);
    fencePrice *= poolAndRoadCircle.getFerence();
    roadPrice *= (poolAndRoadCircle.getArea() - poolCircle.getArea());
    return roadPrice + fencePrice;
}
