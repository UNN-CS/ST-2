// Copyright 2024 Timofey Vinichuk
#include <cstdint>
#include <stdexcept>
#include "tasks.h"
#include "circle.h"

double EarthAndRope(double gap) {
    if (gap < 0)
        throw std::invalid_argument("gap cant be negative or null");
    circle c = circle(EARTH_RADIUS);
    c.setFerence(c.getFerence() + gap);
    return c.getRadius() - EARTH_RADIUS;
}

double SwimmingPoolRoad(double radius, double width, double capRoad) {
    if (radius <= 0 || width <= 0 || capRoad <= 0)
        throw std::invalid_argument("argument isnt wrong");
    circle c = circle(radius);
    double internalArea = c.getArea();
    c.setRadius(radius + width);
    return (c.getArea() - internalArea) * capRoad;
}

double SwimmingPoolFence(double radius, double capFence) {
    if (radius <= 0 || capFence <= 0)
        throw std::invalid_argument("argument isnt wrong");
    circle c = circle(radius);
    return c.getFerence() * capFence;
}
