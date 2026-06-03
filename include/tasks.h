// Copyright 2024 Nazyrov A.A.

#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

namespace tasks {

double calculateRopeGap();

void calculatePoolCosts(double poolRadius, double pathWidth,
                        double concretePrice, double fencePrice,
                        double& concreteCost, double& fenceCost);

}  // namespace tasks

#endif  // INCLUDE_TASKS_H_
