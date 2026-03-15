// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCostResult {
  double concreteCost;
  double fenceCost;
};

double solveEarthAndRope();
PoolCostResult solvePool();

#endif  // INCLUDE_TASKS_H_
