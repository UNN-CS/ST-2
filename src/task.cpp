#include "tasks.h"
#include "circle.h"
double calculateGap(double earthRadius, double additionalLength) {
    Circle earth(earthRadius);
    double originalFerence = earth.getFerence();
    earth.setFerence(originalFerence + additionalLength);
    return earth.getRadius() - earthRadius; // Зазор между веревкой и землёй
}
double calculatePoolCost(double poolRadius, double pathWidth) {
    Circle pool(poolRadius);
    // Стоимость дорожки
    double totalRadius = poolRadius + pathWidth;
    double pathArea = pool.getFerence() * pathWidth; // Площадь дорожки
    double pathCost = pathArea * 1000; // Стоимость дорожки
    // Стоимость ограды
    double fenceCost = pool.getFerence() * 2000; // Погонная стоимость ограды
    return pathCost + fenceCost; // Общая стоимость
}
