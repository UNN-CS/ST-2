// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double ropeGap();

struct PoolCosts {
    double concreteCost;
    double fenceCost;
};

PoolCosts poolCosts(double poolRadius, double pathWidth,
                    double concretePerSqM, double fencePerM);

#endif  // INCLUDE_TASKS_H_
