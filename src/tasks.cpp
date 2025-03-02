// Copyright 2022 UNN-CS

#include <stdexcept>
#include "tasks.h"
#include "circle.h"

double calculateGap(double earthRadius, double addedLength) {
  if (earthRadius <= 0 || addedLength < 0) {
    throw std::invalid_argument("Invalid input values");
  }
  Circle earth(earthRadius);
  double newFerence = earth.getFerence() + addedLength;
  earth.setFerence(newFerence);
  return earth.getRadius() - earthRadius;
}

double calculateCost(double poolRadius, double pathWidth) {
  if (poolRadius <= 0 || pathWidth <= 0) {
    return 0;
  }
  Circle pool(poolRadius);
  Circle outer(poolRadius + pathWidth);
  double pathArea = outer.getArea() - pool.getArea();
  double fenceLength = outer.getFerence();
  return pathArea * 1000 + fenceLength * 2000;
}
