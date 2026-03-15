// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

static const double EARTH_RADIUS_M = 6378100.0;

double ropeGap() {
    Circle earth(EARTH_RADIUS_M);
    double originalFerence = earth.getFerence();
    Circle newCircle(0.0);
    newCircle.setFerence(originalFerence + 1.0);
    return newCircle.getRadius() - earth.getRadius();
}

PoolCosts poolCosts(double poolRadius, double pathWidth,
                    double concretePerSqM, double fencePerM) {
    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    double pathArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getFerence();

    PoolCosts costs;
    costs.concreteCost = pathArea * concretePerSqM;
    costs.fenceCost = fenceLength * fencePerM;
    return costs;
}
