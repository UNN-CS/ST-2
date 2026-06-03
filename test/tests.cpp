// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

namespace {
const double kPi = 3.14159265358979323846;
const double kEps = 1e-6;
}  // namespace

TEST(Circle, ConstructorSetsRadius) {
  Circle c(5.0);
  EXPECT_NEAR(c.getRadius(), 5.0, kEps);
}

TEST(Circle, ConstructorSetsFerence) {
  Circle c(2.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 2.0, kEps);
}

TEST(Circle, ConstructorSetsArea) {
  Circle c(3.0);
  EXPECT_NEAR(c.getArea(), kPi * 9.0, kEps);
}

TEST(Circle, SetRadiusRecalculatesFerenceAndArea) {
  Circle c(1.0);
  c.setRadius(4.0);
  EXPECT_NEAR(c.getRadius(), 4.0, kEps);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 4.0, kEps);
  EXPECT_NEAR(c.getArea(), kPi * 16.0, kEps);
}

TEST(Circle, SetFerenceRecalculatesRadiusAndArea) {
  Circle c(1.0);
  const double newFerence = kPi * 10.0;
  c.setFerence(newFerence);
  EXPECT_NEAR(c.getFerence(), newFerence, kEps);
  EXPECT_NEAR(c.getRadius(), newFerence / (2.0 * kPi), kEps);
  EXPECT_NEAR(c.getArea(), kPi * c.getRadius() * c.getRadius(), kEps);
}

TEST(Circle, SetAreaRecalculatesRadiusAndFerence) {
  Circle c(1.0);
  const double newArea = kPi * 25.0;
  c.setArea(newArea);
  EXPECT_NEAR(c.getArea(), newArea, kEps);
  EXPECT_NEAR(c.getRadius(), 5.0, kEps);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 5.0, kEps);
}

TEST(Circle, GetRadiusAfterSetFerence) {
  Circle c(0.0);
  c.setFerence(2.0 * kPi);
  EXPECT_NEAR(c.getRadius(), 1.0, kEps);
}

TEST(Circle, GetFerenceAfterSetArea) {
  Circle c(0.0);
  c.setArea(kPi);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi, kEps);
}

TEST(Circle, SetRadiusZero) {
  Circle c(5.0);
  c.setRadius(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle, MultipleSetRadiusCalls) {
  Circle c(1.0);
  c.setRadius(2.0);
  c.setRadius(7.0);
  EXPECT_NEAR(c.getRadius(), 7.0, kEps);
  EXPECT_NEAR(c.getArea(), kPi * 49.0, kEps);
}

TEST(Circle, SetFerenceThenSetArea) {
  Circle c(1.0);
  c.setFerence(4.0 * kPi);
  c.setArea(kPi * 9.0);
  EXPECT_NEAR(c.getRadius(), 3.0, kEps);
  EXPECT_NEAR(c.getFerence(), 6.0 * kPi, kEps);
}

TEST(Circle, LargeRadius) {
  Circle c(6378100.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 6378100.0, 1e-3);
}

TEST(Circle, SmallRadius) {
  Circle c(0.001);
  EXPECT_NEAR(c.getArea(), kPi * 0.001 * 0.001, kEps);
}

TEST(Circle, RadiusFromAreaConsistency) {
  Circle c(0.0);
  c.setArea(100.0);
  Circle byRadius(c.getRadius());
  EXPECT_NEAR(byRadius.getArea(), 100.0, kEps);
}

TEST(Circle, FerenceFromRadiusConsistency) {
  Circle c(8.0);
  Circle byFerence(0.0);
  byFerence.setFerence(c.getFerence());
  EXPECT_NEAR(byFerence.getRadius(), 8.0, kEps);
}

TEST(EarthRope, GapEqualsOneOverTwoPi) {
  EXPECT_NEAR(earthRopeGap(), 1.0 / (2.0 * kPi), kEps);
}

TEST(EarthRope, GapIsPositive) {
  EXPECT_GT(earthRopeGap(), 0.0);
}

TEST(EarthRope, GapLessThanOneMeter) {
  EXPECT_LT(earthRopeGap(), 1.0);
}

TEST(Pool, PathAreaIsSevenPi) {
  Circle pool(3.0);
  Circle outer(4.0);
  EXPECT_NEAR(outer.getArea() - pool.getArea(), 7.0 * kPi, kEps);
}

TEST(Pool, FenceLengthIsEightPi) {
  Circle outer(4.0);
  EXPECT_NEAR(outer.getFerence(), 8.0 * kPi, kEps);
}

TEST(Pool, TotalMaterialsCost) {
  EXPECT_NEAR(poolMaterialsCost(), 23000.0 * kPi, kEps);
}

TEST(Pool, ConcreteCostPart) {
  Circle pool(3.0);
  Circle outer(4.0);
  const double concreteCost =
      (outer.getArea() - pool.getArea()) * 1000.0;
  EXPECT_NEAR(concreteCost, 7000.0 * kPi, kEps);
}

TEST(Pool, FenceCostPart) {
  Circle outer(4.0);
  const double fenceCost = outer.getFerence() * 2000.0;
  EXPECT_NEAR(fenceCost, 16000.0 * kPi, kEps);
}
