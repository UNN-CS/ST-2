// Copyright 2025 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_
#include "circle.h"

double calculateGap(double earthRadius, double addedLength);

double calculatePoolCosts(double poolRadius,
    double pathWidth,
    double concreteCostPerSqMeter,
    double fenceCostPerMeter);

#endif // INCLUDE_TASKS_H_
