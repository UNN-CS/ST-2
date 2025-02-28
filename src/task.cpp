// Copyright 2025 Vladlen Korablev
#include "tasks.h"

static const double pi = std::acos(-1.0);

double ropeTask() {
  double earthRadiusM = 6378.1 * 1000.0;
  Circle earth(earthRadiusM);
  double oldFerence = earth.getFerence();
  earth.setFerence(oldFerence + 1.0);
  double gap = earth.getRadius() - earthRadiusM;
  return gap;
}

double poolCost() {
  Circle pool(3.0);
  double areaPool = pool.getArea();
  Circle poolWithPath(4.0);
  double areaPoolWithPath = poolWithPath.getArea();
  double pathArea = areaPoolWithPath - areaPool;
  double concreteCost = pathArea * 1000.0;
  double ferencePoolWithPath = poolWithPath.getFerence();
  double fenceCost = ferencePoolWithPath * 2000.0;
  double totalCost = concreteCost + fenceCost;
  return totalCost;
}

