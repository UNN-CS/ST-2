// Copyright 2025 shvedovav
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <cmath>
#include <cstdint>

#include "tasks.h"
#include "circle.h"

double ropeGapTask() {
  const double earthKm = 6378.1;
  const double earthRadiusM = earthKm * 1000.0;
  Circle earth(earthRadiusM);
  double oldFerence = earth.getFerence();
  earth.setFerence(oldFerence + 1.0);
  double gap = earth.getRadius() - earthRadiusM;
  return gap;
}

double poolCostTask() {
  const double radiusPool = 3.0;
  const double radiusTotal = 4.0;
  Circle pool(radiusPool);
  Circle poolWithPath(radiusTotal);
  double areaPool = pool.getArea();
  double areaPoolWithPath = poolWithPath.getArea();
  double pathArea = areaPoolWithPath - areaPool;
  double concreteCost = pathArea * 1000.0;
  double fenceCost = poolWithPath.getFerence() * 2000.0;
  double totalCost = concreteCost + fenceCost;
  return totalCost;
}
