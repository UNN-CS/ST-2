// Copyright 2024 Tushentsova Karina

#include <stdexcept>
#include "tasks.h"
#include "circle.h"

double ropeTask(double length) {
    if (length < 0.0) throw
        std::invalid_argument("radius");
    const double planetRadius = 6378.1;
    Circle circle(planetRadius);
    circle.setFerence(circle.getFerence() + length);

    return circle.getRadius() - planetRadius;
}

double poolTask(
    double radius,
    double width,
    double concretePrice,
    double fencePrice) {
    if (radius <= 0.0 || width <= 0.0) throw
        std::invalid_argument("radius");
    Circle pool(radius);
    Circle fence(radius + width);
    return (fence.getArea() - pool.getArea()) * concretePrice
        + fence.getFerence() * fencePrice;
}
