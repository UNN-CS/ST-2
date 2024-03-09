// Copyright 2024 Fedor Khodyrev
#include "tasks.h"
#include "circle.h"

double earthAndRopeTask(double extraRopeLength) {
    double earthRadius = 6378.1;
    Circle earth(earthRadius);
    double firstRopeLength = earth.getFerence();
    double secondRopeLength = (firstRopeLength * 1000.0 + 1.0) / 1000.0;
    Circle sphere;
    sphere.setFerence(secondRopeLength);
    double difference = (sphere.getRadius() - earth.getRadius()) * 1000.0;
    return difference;
}

double swimmingPoolTask(double swimmingPoolRadius, double conreteWidht,
    double concretePrice, double fencePrice) {
    Circle swimmingPool(swimmingPoolRadius);
    Circle fullArea(swimmingPoolRadius + conreteWidht);
    double areaOfConcrete = fullArea.getArea() - swimmingPool.getArea();
    double priceForFence = fullArea.getFerence() * fencePrice;
    double priceForConcrete = areaOfConcrete * concretePrice;
    return priceForConcrete + priceForFence;
}
