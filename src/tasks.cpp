// Copyright 2026 UNN-CS

#include <stdexcept>

#include "circle.h"
#include "tasks.h"

double calculateEarthRopeGap(double earthRadiusMeters,
                             double addedRopeLengthMeters) {
  if (earthRadiusMeters < 0.0) {
    throw std::invalid_argument("Радиус Земли должен быть неотрицательным");
  }
  if (addedRopeLengthMeters < 0.0) {
    throw std::invalid_argument("Добавленная длина веревки должна быть неотрицательной");
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
    throw std::invalid_argument("Радиус бассейна должен быть неотрицательным");
  }
  if (pathWidthMeters < 0.0) {
    throw std::invalid_argument("Ширина дорожки должна быть неотрицательной");
  }
  if (concreteCostPerSquareMeter < 0.0) {
    throw std::invalid_argument("Стоимость бетона должна быть неотрицательной");
  }
  if (fenceCostPerMeter < 0.0) {
    throw std::invalid_argument("Стоимость ограждения должна быть неотрицательной");
  }

  Circle pool(poolRadiusMeters);
  Circle withPath(poolRadiusMeters + pathWidthMeters);

  const double concreteArea = withPath.getArea() - pool.getArea();

  PoolCosts costs{};
  costs.concreteCost = concreteArea * concreteCostPerSquareMeter;
  costs.fenceCost = withPath.getFerence() * fenceCostPerMeter;

  return costs;
}
