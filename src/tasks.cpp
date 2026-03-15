// Copyright 2022 UNN-CS
#include "tasks.h"
#include <cmath>
#include "circle.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double solveEarthAndRope() {
  const double EarthRadiusM = 6378.1 * 1000;  // 6378.1 km in meters
  Circle earth(EarthRadiusM);
  double originalRopeLength = earth.getFerence();
  double newRopeLength = originalRopeLength + 1.0;

  Circle newCircle(0);
  newCircle.setFerence(newRopeLength);
  double newRadius = newCircle.getRadius();

  return newRadius - EarthRadiusM;
}

PoolCostResult solvePool() {
  const double poolRadius = 3.0;
  const double pathWidth = 1.0;
  const double outerRadius = poolRadius + pathWidth;
  const double concreteCostPerSqm = 1000.0;
  const double fenceCostPerMeter = 2000.0;

  Circle pool(poolRadius);
  Circle outer(outerRadius);

  double pathArea = outer.getArea() - pool.getArea();
  double fenceLength = outer.getFerence();

  PoolCostResult result;
  result.concreteCost = pathArea * concreteCostPerSqm;
  result.fenceCost = fenceLength * fenceCostPerMeter;
  return result;
}
