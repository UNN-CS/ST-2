// Copyright 2026 UNN-CS

#include <stdexcept>

#include "circle.h"
#include "tasks.h"

double solveEarthRopeTask(double earth_radius_km,
                          double extra_rope_length_m) {
  if (earth_radius_km < 0.0) {
    throw std::invalid_argument("Earth radius must be non-negative");
  }
  if (extra_rope_length_m < 0.0) {
    throw std::invalid_argument("Extra rope length must be non-negative");
  }

  // Gap depends only on added rope length: dR = dL / (2 * pi).
  Circle delta(0.0);
  delta.setFerence(extra_rope_length_m);
  return delta.getRadius();
}

PoolCosts solvePoolTask(double pool_radius_m,
                        double path_width_m,
                        double concrete_price_per_m2,
                        double fence_price_per_m) {
  if (pool_radius_m < 0.0) {
    throw std::invalid_argument("Pool radius must be non-negative");
  }
  if (path_width_m < 0.0) {
    throw std::invalid_argument("Path width must be non-negative");
  }
  if (concrete_price_per_m2 < 0.0) {
    throw std::invalid_argument("Concrete price must be non-negative");
  }
  if (fence_price_per_m < 0.0) {
    throw std::invalid_argument("Fence price must be non-negative");
  }

  Circle pool(pool_radius_m);
  Circle outer(pool_radius_m + path_width_m);

  const double path_area = outer.getArea() - pool.getArea();
  const double concrete_cost = path_area * concrete_price_per_m2;
  const double fence_cost = outer.getFerence() * fence_price_per_m;

  return PoolCosts{concrete_cost, fence_cost, concrete_cost + fence_cost};
}
