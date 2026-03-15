// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
  double concreteCost;
  double fenceCost;
};

double calculateEarthRopeGap(double earthRadiusMeters = 6378100.0,
                             double addedRopeLengthMeters = 1.0);

PoolCosts calculatePoolCosts(double poolRadiusMeters = 3.0,
                             double pathWidthMeters = 1.0,
                             double concreteCostPerSquareMeter = 1000.0,
                             double fenceCostPerMeter = 2000.0);

#endif  // INCLUDE_TASKS_H_
