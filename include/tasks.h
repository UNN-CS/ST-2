// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
  double concrete_cost = 0.0;
  double fence_cost = 0.0;
  double total_cost = 0.0;
};

double earthRopeGapMeters(double earth_radius_km = 6378.1,
                          double added_length_m = 1.0);

PoolCosts poolCosts(double pool_radius_m = 3.0,
                    double track_width_m = 1.0,
                    double concrete_cost_per_m2 = 1000.0,
                    double fence_cost_per_m = 2000.0);

#endif  // INCLUDE_TASKS_H_
