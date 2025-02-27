// Copyright 2022 UNN-CS
#include "tasks.h"

double Rope(double radius) {
    radius *= 1000;
    Circle earth(radius);
    double new_ference = earth.getFerence() + 1;
    earth.setFerence(new_ference);
    return earth.getRadius() - radius;
}

double SwimmingPool(double radius, double width, int cost1, int cost2) {
    Circle pool(radius);
    Circle road(radius + width);
    double road_area = road.getArea() - pool.getArea();
    double fence = road.getFerence();
    return road_area * cost1 + fence * cost2;
}
