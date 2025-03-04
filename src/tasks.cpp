//copyright

#include "tasks.h"
#include "circle.h"

double calculateGap() {
  const double earthRadius = 6378.1 * 1000;
  Circle earthCircle(earthRadius);

  double initialFerence = earthCircle.getFerence();
  earthCircle.setFerence(initialFerence + 1);
  return earthCircle.getRadius() - earthRadius;
}

double calculatePoolCost() {
  const double poolRadius = 3.0;
  const double roadWidth = 1.0;

  Circle pool(poolRadius);
  double outerRadius = poolRadius + roadWidth;

  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * poolRadius * poolRadius;
  double roadCost = roadArea * 1000;

  pool.setRadius(outerRadius);
  double fenceLength = pool.getFerence();
  double fenceCost = fenceLength * 2000;

  return roadCost + fenceCost;
}
