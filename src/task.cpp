// Copyright 2022 UNN-CS
#include "../include/task.h"
#include <cmath>
#include "circle.h"

const double PI = 3.141592653589793;
double CalculateRopeGap(double earthRadius, double ropeIncrease) {
  double newRadius = earthRadius + (ropeIncrease / (2 * PI));
  return newRadius - earthRadius;
}

double CalculatePoolCost(double poolRadius, double pathWidth,
  double concreteCost, double fenceCost) {
  Circle pool(poolRadius);
  Circle outer(poolRadius + pathWidth);

  double pathArea = outer.GetArea() - pool.GetArea();
  double fenceLength = outer.GetFerence();

  return (pathArea * concreteCost) + (fenceLength * fenceCost);
}