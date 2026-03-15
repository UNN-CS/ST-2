// Copyright 2026 UNN-CS
#include "tasks.h"

#include "circle.h"

namespace {

constexpr double kEarthRadiusMeters = 6'378'100.0;
constexpr double kRopeDeltaLength = 1.0;
constexpr double kPoolRadiusMeters = 3.0;
constexpr double kPathWidthMeters = 1.0;
constexpr double kConcretePricePerSquareMeter = 1000.0;
constexpr double kFencePricePerMeter = 2000.0;

}  // namespace

double computeRopeGap() {
  Circle earth(kEarthRadiusMeters);
  const double originalFerence = earth.getFerence();
  const double newFerence = originalFerence + kRopeDeltaLength;

  Circle extended;
  extended.setFerence(newFerence);

  return extended.getRadius() - kEarthRadiusMeters;
}

double computePoolConcreteCost() {
  const Circle inner(kPoolRadiusMeters);
  const double innerArea = inner.getArea();

  const double outerRadius = kPoolRadiusMeters + kPathWidthMeters;
  const Circle outer(outerRadius);
  const double outerArea = outer.getArea();

  const double pathArea = outerArea - innerArea;
  return pathArea * kConcretePricePerSquareMeter;
}

double computePoolFenceCost() {
  const double outerRadius = kPoolRadiusMeters + kPathWidthMeters;
  const Circle outer(outerRadius);
  const double fenceLength = outer.getFerence();
  return fenceLength * kFencePricePerMeter;
}
