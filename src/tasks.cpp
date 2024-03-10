// Copyright 2024 Kashin Stepan
#include "tasks.h"

double taskEarthAndRope(double earthRadius, double extraRopeLength) {
    earthRadius = earthRadius * 1000;//convert km -> m
    Circle earth, rope;

    earth.setRadius(earthRadius);
    rope.setFerence(earth.getFerence() + extraRopeLength);

    return rope.getRadius() - earth.getRadius();
}

double taskSwimmingPool(
    double swimmingPoolRadius,
    double conreteWidht,
    double concretePrice,
    double fencePrice) {
    double concreteArea;
    Circle swimmingPool, fence;

    swimmingPool.setRadius(swimmingPoolRadius);
    fence.setRadius(swimmingPool.getRadius() + conreteWidht);

    concreteArea = fence.getArea() - swimmingPool.getArea();

    return concreteArea * concretePrice + fence.getFerence() * fencePrice;
}
