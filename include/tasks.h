// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double calculateEarthRopeGap(double earth_radius_km = 6378.1,
                             double rope_extra_meters = 1.0);

double calculateConcreteCost(double pool_radius_m = 3.0,
                             double path_width_m = 1.0,
                             double concrete_cost_per_sq_m = 1000.0);

double calculateFenceCost(double pool_radius_m = 3.0,
                          double path_width_m = 1.0,
                          double fence_cost_per_m = 2000.0);

#endif  // INCLUDE_TASKS_H_
