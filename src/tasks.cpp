// Copyright 2024 Karagodin Andrey
#ifndef ST_2_SRC_TASKS_CPP_
#define ST_2_SRC_TASKS_CPP_

#include "../include/tasks.h"

double task_1(double planetRadius, double newRadius) {
    Circle rope(planetRadius);
    rope.setFerence(rope.getFerence() + newRadius);
    return rope.getRadius() - planetRadius;
}

double task_2(double poolRadius,
    double pathWidth,
    double concretePrice,
    double fencePrice) {
    Circle pool(poolRadius);
    Circle fence(poolRadius + pathWidth);
    return (fence.getArea() - pool.getArea()) *
    concretePrice + fence.getFerence() * fencePrice;
}

#endif  // ST_2_SRC_TASKS_CPP_
