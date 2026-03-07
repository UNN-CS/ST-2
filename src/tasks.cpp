// Copyright 2022 UNN-CS
#include <utility>

#include "tasks.h"
#include "circle.h"

double resolveEarthAndCordTask() {
  const double earth_radius = 6378.1 * 1000.0;
  Circle cord(earth_radius);
  cord.setFerence(cord.getFerence() + 1.0);
  return cord.getRadius() - earth_radius;
}

std::pair<double, double> resolvePoolTask() {
  const double concrete_path_price = 1000.0;
  const double fence_price_per_meter = 2000.0;
  const double pool_radius = 3.0;
  const double concrete_path_width = 1.0;

  Circle pool(pool_radius);
  Circle outer(pool_radius + concrete_path_width);

  double concrete_cost =
      (outer.getArea() - pool.getArea()) * concrete_path_price;
  double fence_cost = outer.getFerence() * fence_price_per_meter;

  return {concrete_cost, fence_cost};
}
