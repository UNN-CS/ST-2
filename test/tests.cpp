// Copyright 2025 UNN-CS Team

#include "circle.h"
#include <cmath>
#include <cstdint>
#include <gtest/gtest.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <tasks.h>
const double EPS = 1e-9;

TEST(Circle, DefaultConstructor) {
  Circle c;
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, ZeroRadiusConstructor) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
}

TEST(Circle, HalfRadiusConstructor) {
  Circle c(0.5);
  EXPECT_DOUBLE_EQ(0.5, c.getRadius());
  EXPECT_NEAR(M_PI, c.getFerence(), EPS);
  EXPECT_NEAR(0.25 * M_PI, c.getArea(), EPS);
}

TEST(Circle, OneRadiusConstructor) {
  Circle c(1.0);
  EXPECT_DOUBLE_EQ(1.0, c.getRadius());
}

TEST(Circle, FiveRadiusConstructor) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(5.0, c.getRadius());
}

TEST(Circle, ThousandRadiusConstructor) {
  Circle c(1000.0);
  EXPECT_DOUBLE_EQ(1000.0, c.getRadius());
}

TEST(Circle, MillionRadiusConstructor) {
  Circle c(1000000.0);
  EXPECT_DOUBLE_EQ(1000000.0, c.getRadius());
}

TEST(Circle, SetRadiusZeroUpdateRadius) {
  Circle c(1.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
}

TEST(Circle, SetRadius10UpdateRadius) {
  Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(10.0, c.getRadius());
}

TEST(Circle, SetRadius55UpdateRadius) {
  Circle c(0.0);
  c.setRadius(55.0);
  EXPECT_DOUBLE_EQ(55.0, c.getRadius());
}

TEST(Circle, SetRadius4849UpdateRadius) {
  Circle c(0.0);
  c.setRadius(4849.0);
  EXPECT_DOUBLE_EQ(4849.0, c.getRadius());
}

TEST(Circle, SetFerence10UpdateFerence) {
  Circle c(1.0);
  c.setFerence(10.0);
  EXPECT_DOUBLE_EQ(10.0, c.getFerence());
}

TEST(Circle, SetFerence55UpdateFerence) {
  Circle c(0.0);
  c.setFerence(55.0);
  EXPECT_DOUBLE_EQ(55.0, c.getFerence());
}

TEST(Circle, SetFerence4849UpdateFerence) {
  Circle c(0.0);
  c.setFerence(4849.0);
  EXPECT_DOUBLE_EQ(4849.0, c.getFerence());
}

TEST(Circle, SetArea25UpdateArea) {
  Circle c(1.0);
  c.setArea(25.0);
  EXPECT_DOUBLE_EQ(25.0, c.getArea());
}

TEST(Circle, SetArea49UpdateArea) {
  Circle c(0.0);
  c.setArea(49.0);
  EXPECT_DOUBLE_EQ(49.0, c.getArea());
}

TEST(Circle, SetArea324UpdateArea) {
  Circle c(0.0);
  c.setArea(324.0);
  EXPECT_DOUBLE_EQ(324.0, c.getArea());
}

TEST(Circle, SetRadiusZeroUpdateAll) {
  Circle c(1.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, SetRadius10UpdateAll) {
  Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(10.0, c.getRadius());
  EXPECT_NEAR(20.0 * M_PI, c.getFerence(), EPS);
  EXPECT_NEAR(100.0 * M_PI, c.getArea(), EPS);
}

TEST(Circle, SetRadius55UpdateAll) {
  Circle c(0.0);
  c.setRadius(55.0);
  EXPECT_DOUBLE_EQ(55.0, c.getRadius());
  EXPECT_NEAR(110.0 * M_PI, c.getFerence(), EPS);
  EXPECT_NEAR(3025.0 * M_PI, c.getArea(), EPS);
}

TEST(Circle, SetRadius4849UpdateAll) {
  Circle c(0.0);
  c.setRadius(4849.0);
  EXPECT_DOUBLE_EQ(4849.0, c.getRadius());
  EXPECT_NEAR(9698.0 * M_PI, c.getFerence(), EPS);
  EXPECT_NEAR(23512801.0 * M_PI, c.getArea(), EPS);
}

TEST(Circle, SetRadiusSeveralTimes) {
  Circle c(0.0);
  c.setRadius(2.0);
  c.setRadius(3.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(10.0, c.getRadius());
  EXPECT_NEAR(20.0 * M_PI, c.getFerence(), EPS);
  EXPECT_NEAR(100.0 * M_PI, c.getArea(), EPS);
}

TEST(Circle, SetFerenceZero) {
  Circle c(1.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, SetFerenceUpdatesAreaRadius) {
  Circle c(1.0);
  c.setFerence(24.0);
  EXPECT_DOUBLE_EQ(10.0, c.getRadius());
  EXPECT_NEAR(20.0 * M_PI, c.getFerence(), EPS);
  EXPECT_NEAR(100.0 * M_PI, c.getArea(), EPS);
}

TEST(Circle, SetFerenceUpdatesRadiusAndArea) {
  Circle c;
  c.setFerence(2.0 * M_PI);
  EXPECT_NEAR(1.0, c.getRadius(), EPS);
  EXPECT_NEAR(2.0 * M_PI, c.getFerence(), EPS);
  EXPECT_NEAR(M_PI, c.getArea(), EPS);
}

TEST(Circle, SetAreaZero) {
  Circle c(1.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(Circle, SetAreaUpdatesRadiusAndFerence) {
  Circle c;
  c.setArea(M_PI);
  EXPECT_NEAR(1.0, c.getRadius(), EPS);
  EXPECT_NEAR(2.0 * M_PI, c.getFerence(), EPS);
  EXPECT_NEAR(M_PI, c.getArea(), EPS);
}

TEST(Circle, VerySmallRadius) {
  Circle c(1e-10);
  EXPECT_NEAR(1e-10, c.getRadius(), 1e-20);
  EXPECT_NEAR(2 * M_PI * 1e-10, c.getFerence(), 1e-20);
  EXPECT_NEAR(M_PI * 1e-20, c.getArea(), 1e-30);
}

TEST(Circle, VeryLargeRadius) {
  Circle c(1e10);
  EXPECT_DOUBLE_EQ(1e10, c.getRadius());
  EXPECT_NEAR(2 * M_PI * 1e10, c.getFerence(), 1e-5);
  EXPECT_NEAR(M_PI * 1e20, c.getArea(), 1e10);
}

TEST(Circle, NegativeRadiusConstructor) {
  Circle c(-5.0);
  EXPECT_DOUBLE_EQ(-5.0, c.getRadius());
  EXPECT_NEAR(2 * M_PI * (-5.0), c.getFerence(), EPS);
  EXPECT_NEAR(M_PI * 25.0, c.getArea(), EPS);
}

TEST(Circle, SetNegativeRadius) {
  Circle c(1.0);
  c.setRadius(-3.0);
  EXPECT_DOUBLE_EQ(-3.0, c.getRadius());
  EXPECT_NEAR(2 * M_PI * (-3.0), c.getFerence(), EPS);
  EXPECT_NEAR(M_PI * 9.0, c.getArea(), EPS);
}

TEST(Circle, SetFerenceAndGetRadius) {
  Circle c;
  c.setFerence(2 * M_PI * 5.0);
  EXPECT_NEAR(5.0, c.getRadius(), EPS);
  EXPECT_NEAR(M_PI * 25.0, c.getArea(), EPS);
}

TEST(Circle, SetAreaAndGetRadius) {
  Circle c;
  c.setArea(M_PI * 9.0);
  EXPECT_NEAR(3.0, c.getRadius(), EPS);
  EXPECT_NEAR(2 * M_PI * 3.0, c.getFerence(), EPS);
}

TEST(Circle, SetRadiusThenSetFerence) {
  Circle c(5.0);
  c.setFerence(2 * M_PI * 10.0);
  EXPECT_NEAR(10.0, c.getRadius(), EPS);
  EXPECT_NEAR(M_PI * 100.0, c.getArea(), EPS);
}

TEST(Circle, SetRadiusThenSetArea) {
  Circle c(5.0);
  c.setArea(M_PI * 16.0);
  EXPECT_NEAR(4.0, c.getRadius(), EPS);
  EXPECT_NEAR(2 * M_PI * 4.0, c.getFerence(), EPS);
}

TEST(Tasks, EarthAndRope) {
  double earthRadius = 6378.1;
  double addedLength = 1.0;

  double gap = earthAndRope(earthRadius, addedLength);

  double expectedGap = addedLength / (2 * M_PI);

  EXPECT_NEAR(expectedGap, gap, 1e-6);
}

TEST(Tasks, EarthAndRopeZeroAdded) {
  double earthRadius = 6378.1;
  double addedLength = 0.0;

  double gap = earthAndRope(earthRadius, addedLength);

  EXPECT_NEAR(0.0, gap, 1e-6);
}

TEST(Tasks, EarthAndRopeNegativeAdded) {
  double earthRadius = 6378.1;
  double addedLength = -1.0;

  double gap = earthAndRope(earthRadius, addedLength);

  EXPECT_NEAR(-1.0 / (2 * M_PI), gap, 1e-6);
}

TEST(Tasks, EarthAndRopeDifferentRadius) {

  double gap1 = earthAndRope(1000.0, 1.0);
  double gap2 = earthAndRope(10000.0, 1.0);

  EXPECT_NEAR(gap1, gap2, 1e-6);
}

TEST(Tasks, Pool) {
  double poolRadius = 3.0;
  double pathWidth = 1.0;
  double concreteCost = 1000.0;
  double fenceCost = 2000.0;

  double totalCost = pool(poolRadius, pathWidth, concreteCost, fenceCost);

  double poolArea = M_PI * poolRadius * poolRadius;
  double outerArea = M_PI * (poolRadius + pathWidth) * (poolRadius + pathWidth);
  double pathArea = outerArea - poolArea;
  double fenceLength = 2 * M_PI * (poolRadius + pathWidth);

  double expectedCost = pathArea * concreteCost + fenceLength * fenceCost;

  EXPECT_NEAR(expectedCost, totalCost, 1e-6);
}

TEST(Tasks, PoolZeroWidth) {
  double poolRadius = 3.0;
  double pathWidth = 0.0;
  double concreteCost = 1000.0;
  double fenceCost = 2000.0;

  double totalCost = pool(poolRadius, pathWidth, concreteCost, fenceCost);

  double expectedCost = 0.0 + (2 * M_PI * poolRadius) * fenceCost;

  EXPECT_NEAR(expectedCost, totalCost, 1e-6);
}

TEST(Tasks, PoolZeroCosts) {
  double poolRadius = 3.0;
  double pathWidth = 1.0;
  double concreteCost = 0.0;
  double fenceCost = 0.0;

  double totalCost = pool(poolRadius, pathWidth, concreteCost, fenceCost);

  EXPECT_NEAR(0.0, totalCost, 1e-6);
}

TEST(Tasks, PoolNegativeWidth) {
  double poolRadius = 3.0;
  double pathWidth = -1.0;

  double totalCost = pool(poolRadius, pathWidth, 1000.0, 2000.0);

  EXPECT_TRUE(std::isfinite(totalCost));
}

TEST(Tasks, PoolVeryLargeRadius) {
  double poolRadius = 1e6;
  double pathWidth = 1.0;
  double concreteCost = 1000.0;
  double fenceCost = 2000.0;

  double totalCost = pool(poolRadius, pathWidth, concreteCost, fenceCost);

  EXPECT_TRUE(std::isfinite(totalCost));
  EXPECT_GT(totalCost, 0.0);
}