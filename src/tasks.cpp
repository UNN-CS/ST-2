// Copyright 2025 Mikhail Burykin
#include "tasks.h"
#include "circle.h"

double calculateRopeGap() {
    const double earthRadiusKm = 6378.1;
    double earthRadiusMeters = earthRadiusKm * 1000;
    Circle earth(earthRadiusMeters);
    double newFerence = earth.getFerence() + 1.0;
    earth.setFerence(newFerence);
    return earth.getRadius() - earthRadiusMeters;
}

double calculatePoolCost() {
    Circle pool(3.0);
    Circle outer(4.0); // 3m + 1m дорожка
    double concreteArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getFerence();
    return concreteArea * 1000 + fenceLength * 2000;
}
