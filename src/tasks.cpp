// Copyright 2022 UNN-CS
#include "tasks.h"
const double PI = 3.14159265358979323846;

double findGap() {
    const double radiusEarth = 6378100.0;
    const double rope = 1.0;
    Circle earth(radiusEarth);
    earth.setFerence(earth.getFerence() + rope);
    return earth.getRadius() - radiusEarth;
}

double findCost() {
    const double radiusPool = 3.0;
    const double widthTrack = 1.0;
    const double costConcrete = 1000.0;
    const double costFence = 2000.0;

    Circle pool(radiusPool);
    Circle track(radiusPool + widthTrack);
    
    double pathArea = track.getArea() - pool.getArea();
    double fenceLength = track.getFerence();

    return costConcrete * pathArea + costFence * fenceLength;
}
