#include "tasks.h"
#include "circle.h"

double solveEarthRopeProblem() {
    const double EARTH_RADIUS = 6378100.0;
    Circle earth(EARTH_RADIUS);
    double ropeLength = earth.getFerence();
    Circle newCircle(0);
    newCircle.setFerence(ropeLength + 1.0);
    return newCircle.getRadius() - earth.getRadius();
}

PoolResult solvePoolProblem() {
    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    const double CONCRETE_COST = 1000.0;
    const double FENCE_COST = 2000.0;

    Circle pool(POOL_RADIUS);
    Circle outer(POOL_RADIUS + PATH_WIDTH);

    double pathArea = outer.getArea() - pool.getArea();
    double pathCost = pathArea * CONCRETE_COST;
    double fenceCost = outer.getFerence() * FENCE_COST;

    PoolResult result;
    result.pathCost = pathCost;
    result.fenceCost = fenceCost;
    result.totalCost = pathCost + fenceCost;

    return result;
}