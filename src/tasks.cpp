// Copyright 2022 UNN-CS
#include "tasks.h"

#include <stdexcept>

#include "circle.h"

double GetRopeGapAfterAddingLength(double added_length_m) {
  if (added_length_m < 0.0) {
    throw std::invalid_argument("added_length_m must be non-negative");
  }
  Circle earth(6378100.0);
  const double old_ference = earth.getFerence();
  earth.setFerence(old_ference + added_length_m);
  return earth.getRadius() - 6378100.0;
}

double GetPoolConcreteCost(double pool_radius_m,
                           double path_width_m,
                           double cost_per_square_meter) {
  if (pool_radius_m < 0.0 || path_width_m < 0.0 ||
      cost_per_square_meter < 0.0) {
    throw std::invalid_argument("all arguments must be non-negative");
  }
  Circle inner(pool_radius_m);
  Circle outer(pool_radius_m + path_width_m);
  const double path_area = outer.getArea() - inner.getArea();
  return path_area * cost_per_square_meter;
}

double GetPoolFenceCost(double pool_radius_m,
                        double path_width_m,
                        double cost_per_meter) {
  if (pool_radius_m < 0.0 || path_width_m < 0.0 || cost_per_meter < 0.0) {
    throw std::invalid_argument("all arguments must be non-negative");
  }
  Circle outer(pool_radius_m + path_width_m);
  return outer.getFerence() * cost_per_meter;
}
