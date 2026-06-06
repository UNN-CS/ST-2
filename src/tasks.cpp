// Copyright 2022 UNN-CS

#include "tasks.h"
#include "circle.h"

double ropeGap(double earth_radius_km) {
    Circle earth(earth_radius_km * 1000.0);

    Circle biggerEarth(0);
    biggerEarth.setFerence(earth.getFerence() + 1.0);

    return biggerEarth.getRadius() - earth.getRadius();
}

double poolConcreteCost(double pool_radius_m,
                        double walkway_width_m,
                        double concrete_price_per_m2) {
    Circle pool(pool_radius_m);
    Circle outer(pool_radius_m + walkway_width_m);

    double pathArea = outer.getArea() - pool.getArea();

    return pathArea * concrete_price_per_m2;
}

double poolFenceCost(double pool_radius_m,
                     double walkway_width_m,
                     double fence_price_per_m) {
    Circle outer(pool_radius_m + walkway_width_m);

    return outer.getFerence() * fence_price_per_m;
}

double poolTotalCost(double pool_radius_m,
                     double walkway_width_m,
                     double concrete_price_per_m2,
                     double fence_price_per_m) {
    return poolConcreteCost(pool_radius_m,
                            walkway_width_m,
                            concrete_price_per_m2)
         + poolFenceCost(pool_radius_m,
                         walkway_width_m,
                         fence_price_per_m);
}
