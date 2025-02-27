#include "tasks.h"

double calculateGap(double additionalLength) {
  Circle earth(6378.1);
  double originalFerence = earth.getFerence();
  earth.setFerence(originalFerence + additionalLength);
  return earth.getRadius() - 6378.1;
}

double calculatePoolCost(double radius, double pathWidth) {
  Circle pool(radius + pathWidth);
  double pathArea = pool.getArea() - Circle(radius).getArea();
  double fenceLength = pool.getFerence();
  
  double pathCost = pathArea * 1000;
  double fenceCost = fenceLength * 2000;
  
  return pathCost + fenceCost;
}
