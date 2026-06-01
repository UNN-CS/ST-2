// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

static constexpr double PI = 3.14159265358979323846;

double ropeGap(double earthRadius, double addedLength) {
  // Calculate the original rope circumference around Earth
  Circle originalRope(earthRadius);
  double originalCircumference = originalRope.getFerence();
  
  // New circumference after adding length
  double newCircumference = originalCircumference + addedLength;
  
  // Create a circle with the new circumference to find the new radius
  Circle newRope(1.0);
  newRope.setFerence(newCircumference);
  double newRadius = newRope.getRadius();
  
  // The gap is the difference between the new radius and Earth's radius
  return newRadius - earthRadius;
}

double poolConcreteCost(double poolRadius, double walkwayWidth,
                        double pricePerSqm) {
  // Pool area
  Circle innerPool(poolRadius);
  double poolArea = innerPool.getArea();
  
  // Outer boundary including walkway
  double outerRadius = poolRadius + walkwayWidth;
  Circle outerBoundary(outerRadius);
  double outerArea = outerBoundary.getArea();
  
  // Walkway area (difference between outer and inner areas)
  double concreteArea = outerArea - poolArea;
  
  // Calculate cost
  return concreteArea * pricePerSqm;
}

double poolFenceCost(double poolRadius, double walkwayWidth,
                     double pricePerM) {
  // The fence is placed at the outer edge of the walkway
  double fenceRadius = poolRadius + walkwayWidth;
  
  // Calculate the circumference at this radius
  Circle fenceCircle(fenceRadius);
  double fenceLength = fenceCircle.getFerence();
  
  // Calculate total cost
  return fenceLength * pricePerM;
}
