// Copyright 2025 Kalinin Dmitriy
#include "tasks.h"

double earthRadius = 6378100;

double EarthAndRopeTask(double rope_length) {
    Circle earth(earthRadius);
    Circle rope;
    rope.setFerence(earth.getFerence() + rope_length);
    return rope.getRadius() - earth.getRadius();
}

double SwimmingPoolTask(double pool_radius_meter,
    double road_width_meter,
    double concrete_price,
    double fence_price_per_meter) {
    Circle pool = Circle(pool_radius_meter);
    Circle poolAndArea = Circle(pool_radius_meter + road_width_meter);

    double ference_price = poolAndArea.getFerence() * fence_price_per_meter;

    double areaPrice = (poolAndArea.getArea() - pool.getArea())
     * concrete_price;

    return ference_price + areaPrice;
}