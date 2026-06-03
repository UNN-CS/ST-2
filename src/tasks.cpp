// Copyright 2024 Nazyrov A.A.


#include <cmath>

#include "tasks.h"
#include "circle.h"




namespace tasks {

static const double EARTH_RADIUS_KM = 6378.1;
static const double EARTH_RADIUS_M = EARTH_RADIUS_KM * 1000.0;

double calculateRopeGap() {
  using geometry::Circle;

  Circle earth(EARTH_RADIUS_M);
  double initialLength = earth.getCircumference();
  double newLength = initialLength + 1.0;

  Circle extendedCircle(0.0);
  extendedCircle.setCircumference(newLength);

  return extendedCircle.getRadius() - EARTH_RADIUS_M;
}

void calculatePoolCosts(double poolRadius, double pathWidth,
                        double concretePrice, double fencePrice,
                        double& concreteCost, double& fenceCost) {
  using geometry::Circle;

  Circle pool(poolRadius);
  Circle withPath(poolRadius + pathWidth);

  double poolArea = pool.getArea();
  double totalArea = withPath.getArea();
  double pathArea = totalArea - poolArea;

  double fenceLength = withPath.getCircumference();

  concreteCost = pathArea * concretePrice;
  fenceCost = fenceLength * fencePrice;
}

}  // namespace tasks
