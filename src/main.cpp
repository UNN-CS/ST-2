// Copyright 2022 UNN-CS
#include "circle.h"
#include "tasks.h"

int main() {
    double radEarth = 6378100;

    Circle Earth(radEarth);

    double verevka = Earth.getFerence();
    double val_1 = Earth.getRadius();

    verevka += 1.0;

    Earth.setFerence(verevka);

    double val_2 = Earth.getRadius();

    double result = sub(val_1, val_2);

    const double CONCRETE_PRICE = 1000.0;
    const double FENCE_PRICE = 2000.0; 

    double bassein_rad = 3.0;
    Circle pool(bassein_rad);
    Circle poolWithPath(bassein_rad + 1.0);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double concreteCost = pathArea * CONCRETE_PRICE;
    double fenceCost = fenceLength * FENCE_PRICE;
    double totalCost = concreteCost + fenceCost;

    std::cout << result << std::endl;
    std::cout << totalCost << std::endl;
    return 0;
}
