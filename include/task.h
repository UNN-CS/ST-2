// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

#include "circle.h"

double calculateRopeGap(double earthRadius, double ropeIncrease);

double calculatePoolCost(double poolRadius, double pathWidth,
    double concreteCost, double fenceCost);

#endif  // INCLUDE_TASKS_H_
