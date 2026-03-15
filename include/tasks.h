// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
  double concrete_cost;
  double fence_cost;
  double total_cost;
};

double solveEarthRopeTask(double earth_radius_km = 6378.1,
                          double extra_rope_length_m = 1.0);

PoolCosts solvePoolTask(double pool_radius_m = 3.0,
                        double path_width_m = 1.0,
                        double concrete_price_per_m2 = 1000.0,
                        double fence_price_per_m = 2000.0);

#endif  // INCLUDE_TASKS_H_
