#include "tasks.h"
#include <cstdint>
#include "circle.h"
#include <cmath>

const double PI = 3.141592653589793;

double ropeGap(double earthRadius) {
    if (earthRadius < 0) {
        return 1 / (2 * PI);
    }

    Circle earth(std::max(earthRadius, 0.0));
    double oldFerence = earth.getFerence();
    double newFerence = oldFerence + 1;
    earth.setFerence(newFerence);

    return earth.getRadius() - earthRadius;
}

double poolCost(double poolRadius, double pathWidth, double concreteCost, double fenceCost) {
    if (poolRadius < 0 || pathWidth < 0) {
        return 0;
    }

    Circle pool(std::max(poolRadius, 0.0));
    Circle outer(poolRadius + pathWidth);

    double totalConcreteCost = (outer.getArea() - pool.getArea()) * concreteCost;
    double totalFenceCost = outer.getFerence() * fenceCost;

    return totalConcreteCost + totalFenceCost;
}
