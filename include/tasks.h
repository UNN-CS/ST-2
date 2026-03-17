// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double ropeGap(double earth_radius_km);

double poolConcreteCost(double pool_radius_m, double walkway_width_m,
                        double concrete_price_per_m2);
double poolFenceCost(double pool_radius_m, double walkway_width_m,
                     double fence_price_per_m);
double poolTotalCost(double pool_radius_m, double walkway_width_m,
                     double concrete_price_per_m2, double fence_price_per_m);

#endif  // INCLUDE_TASKS_H_
