// Copyright 2022 UNN-CS
#include "circle.h"
#include "tasks.h"

double earthRopeGap() {
  const double kEarthRadiusKm = 6378.1;
  const double kAddedRopeM = 1.0;

  Circle earth(kEarthRadiusKm * 1000.0);
  const double originalRadius = earth.getRadius();

  Circle longerRope(0.0);
  longerRope.setFerence(earth.getFerence() + kAddedRopeM);

  return longerRope.getRadius() - originalRadius;
}

double poolMaterialsCost() {
  const double kPoolRadiusM = 3.0;
  const double kPathWidthM = 1.0;
  const double kConcreteCostPerM2 = 1000.0;
  const double kFenceCostPerM = 2000.0;

  Circle pool(kPoolRadiusM);
  Circle outerRing(kPoolRadiusM + kPathWidthM);

  const double pathArea = outerRing.getArea() - pool.getArea();
  const double fenceLength = outerRing.getFerence();

  return pathArea * kConcreteCostPerM2 + fenceLength * kFenceCostPerM;
}
