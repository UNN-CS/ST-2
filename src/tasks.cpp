// Copyright 2025 UNN-CS
#include "tasks.h"
#include <cmath>
#include "circle.h"

static constexpr double PI = 3.14159265358979323846;

double ropeGap(double earthRadius, double addedLength) {
  Circle originalRope(earthRadius);
  double originalCircumference = originalRope.getFerence();
  double newCircumference = originalCircumference + addedLength;

  Circle newRope(1.0);
  newRope.setFerence(newCircumference);
  double newRadius = newRope.getRadius();

  return newRadius - earthRadius;
}

double poolConcreteCost(double poolRadius, double walkwayWidth,
                        double pricePerSqm) {
  Circle innerPool(poolRadius);
  double poolArea = innerPool.getArea();

  double outerRadius = poolRadius + walkwayWidth;
  Circle outerBoundary(outerRadius);
  double outerArea = outerBoundary.getArea();

  double concreteArea = outerArea - poolArea;

  return concreteArea * pricePerSqm;
}

double poolFenceCost(double poolRadius, double walkwayWidth,
                     double pricePerM) {
  double fenceRadius = poolRadius + walkwayWidth;

  Circle fenceCircle(fenceRadius);
  double fenceLength = fenceCircle.getFerence();

  return fenceLength * pricePerM;
}
