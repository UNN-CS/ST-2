// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASK_H_
#define INCLUDE_TASK_H_

#include "circle.h"

double calculateRopeGap(double earthRadius, double ropeIncrease);

double calculatePoolCost(double poolRadius, double pathWidth,
    double concreteCost, double fenceCost);

#endif  // INCLUDE_TASK_H_
