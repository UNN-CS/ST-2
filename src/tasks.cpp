// Copyright 2022 UNN-CS
#include "tasks.h"

double earthAndRope(double earthRadius, double addedLength) {
  Circle earth(earthRadius * 1000);
  double originalFerence = earth.getFerence();
  earth.setFerence(originalFerence + addedLength);

  double gap = earth.getRadius() - (earthRadius * 1000);
  return gap;
}

double pool(double poolRadius, double pathWidth, double concreteCost,
            double fenceCost) {
  Circle pool(poolRadius);
  double poolArea = pool.getArea();

  Circle outer(poolRadius + pathWidth);
  double outerArea = outer.getArea();
  double outerFerence = outer.getFerence();

  double finalRoadCost = (outerArea - poolArea) * concreteCost;
  double finalFenceCost = outerFerence * fenceCost;
  double finalCost = finalRoadCost + finalFenceCost;

  return finalCost;
}