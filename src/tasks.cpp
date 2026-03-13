#include "tasks.h"
#include "circle.h"

double calculateEarthGap() {
    double earthRadiusInMeters = 6378.1 * 1000;
    Circle earth(earthRadiusInMeters);
    double initialRadius = earth.getRadius();
    earth.setFerence(earth.getFerence() + 1.0);
    return earth.getRadius() - initialRadius;
}

double calculatePoolConcreteCost() {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double pricePerSqMeter = 1000.0;

    Circle pool(poolRadius);
    Circle total(poolRadius + pathWidth);

    double concreteArea = total.getArea() - pool.getArea();
    return concreteArea * pricePerSqMeter;
}

double calculatePoolFenceCost() {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double pricePerMeter = 2000.0;

    Circle total(poolRadius + pathWidth);
    return total.getFerence() * pricePerMeter;
}
