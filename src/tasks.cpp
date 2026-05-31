// Copyright 2026 Klimov M.D.
#include "tasks.h"
#include "circle.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double ropeTask() {
    Circle earth(6378100.0);
    double originalFerence = earth.getFerence();
    earth.setFerence(originalFerence + 1.0);
    return earth.getRadius() - 6378100.0;
}

double poolTask() {
    Circle pool(3.0);
    Circle poolWithPath(4.0);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double concreteCost = pathArea * 1000.0;
    double fenceCost = poolWithPath.getFerence() * 2000.0;
    return concreteCost + fenceCost;
}
