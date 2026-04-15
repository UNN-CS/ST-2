#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolResult {
    double pathCost;
    double fenceCost;
    double totalCost;
};

double solveEarthRopeProblem();
PoolResult solvePoolProblem();

#endif