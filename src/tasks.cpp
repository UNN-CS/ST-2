// Copyright 2026 UNN-CS

#include <stdexcept>

#include "circle.h"
#include "tasks.h"

double calculateEarthRopeGap(double earthRadiusMeters,
                             double addedRopeLengthMeters) {
  if (earthRadiusMeters < 0.0) {
    throw std::invalid_argument("Earth radius must be non-negative");
  }
  if (addedRopeLengthMeters < 0.0) {
    throw std::invalid_argument("Added rope length must be non-negative");
  }

  Circle earth(earthRadiusMeters);
  Circle expanded(earthRadiusMeters);
  expanded.setFerence(earth.getFerence() + addedRopeLengthMeters);

  return expanded.getRadius() - earth.getRadius();
}

PoolCosts calculatePoolCosts(double poolRadiusMeters,
                             double pathWidthMeters,
                             double concreteCostPerSquareMeter,
                             double fenceCostPerMeter) {
  if (poolRadiusMeters < 0.0) {
    throw std::invalid_argument("Pool radius must be non-negative");
  }
  if (pathWidthMeters < 0.0) {
    throw std::invalid_argument("Path width must be non-negative");
  }
  if (concreteCostPerSquareMeter < 0.0) {
    throw std::invalid_argument("Concrete cost must be non-negative");
  }
  if (fenceCostPerMeter < 0.0) {
    throw std::invalid_argument("Fence cost must be non-negative");
  }

  Circle pool(poolRadiusMeters);
  Circle withPath(poolRadiusMeters + pathWidthMeters);

  const double concreteArea = withPath.getArea() - pool.getArea();

  PoolCosts costs{};
  costs.concreteCost = concreteArea * concreteCostPerSquareMeter;
  costs.fenceCost = withPath.getFerence() * fenceCostPerMeter;

  return costs;
}
