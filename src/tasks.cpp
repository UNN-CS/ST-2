// Copyright 2025 UNN-CS
#include <iostream>
#include <cstdint>
#include <math.h>
#include "circle.h"
#include "tasks.h"

double sub(double a, double b) {
    return a - b;
}

double calculatePoolCost(double poolRadius, double pathWidth, 
                        double concretePrice, double fencePrice) {
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();
    
    return pathArea * concretePrice + fenceLength * fencePrice;
}