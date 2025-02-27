// Copyright 2022 UNN-CS
#include "tasks.h"
#include <stdexcept>
#include "circle.h"

double calculateRopeGap(double earthRadius, double addedLength) {
  if (earthRadius < 0 || addedLength < 0) {
    throw std::invalid_argument("Radius and added length must be positive");
  }

  Circle earth(earthRadius * 1000);
  double initialCircumference = earth.getCircumference();

  earth.setCircumference(initialCircumference + addedLength);

  return earth.getRadius() - (earthRadius * 1000);
}

PoolResults calculatePoolCosts(double poolRadius, double pathwayWidth,
                               double pathwayCostPerSqMeter,
                               double fenceCostPerMeter) {
  if (poolRadius < 0 || pathwayWidth < 0 || pathwayCostPerSqMeter < 0 ||
      fenceCostPerMeter < 0) {
    throw std::invalid_argument("All parameters must be positive");
  }

  PoolResults results;

  Circle pool(poolRadius);

  Circle totalArea(poolRadius + pathwayWidth);

  double pathwayArea = totalArea.getArea() - pool.getArea();

  double fenceLength = totalArea.getCircumference();

  results.pathwayCost = pathwayArea * pathwayCostPerSqMeter;
  results.fenceCost = fenceLength * fenceCostPerMeter;
  results.totalCost = results.pathwayCost + results.fenceCost;

  return results;
}
