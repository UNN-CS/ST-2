// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolResults {
  double pathwayCost;
  double fenceCost;
  double totalCost;
};

double calculateRopeGap(double earthRadius, double addedLength);

PoolResults calculatePoolCosts(double poolRadius, double pathwayWidth,
                               double pathwayCostPerSqMeter,
                               double fenceCostPerMeter);

#endif // INCLUDE_TASKS_H_
