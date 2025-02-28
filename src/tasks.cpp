// Copyright 2025 ovVrLFg8ks

#include "tasks.h"
#include "circle.h"

double ropeTask(double earthRadius, double gap) {
  Circle c(earthRadius);
  c.setFerence(c.getFerence() + gap);
  return c.getRadius() - earthRadius;
}

double poolTask(double poolRadius, double pathWidth, double concreteSquarePrice,
                double fenceMeterPrice) {
  Circle poolCore(poolRadius);
  if (pathWidth < 0)
    throw std::invalid_argument("the argument must have a non-negative value");
  Circle concretePath(poolRadius + pathWidth);

  double concreteArea = concretePath.getArea() - poolCore.getArea();
  double concretePrice = concreteArea * concreteSquarePrice;
  double fencePrice = concretePath.getFerence() * fenceMeterPrice;
  return concretePrice + fencePrice;
}
