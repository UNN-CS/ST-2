// Copyright 2025 Artem Tyshkevich
#include <gtest/gtest.h>
#include <cstdint>
#include <cassert>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;

TEST(CircleTest, RadiusInitialization) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, SetRadiusUpdatesFerenceAndArea) {
  Circle c(5.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 10.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 10.0 * 10.0);
}

TEST(CircleTest, SetFerenceUpdatesRadiusAndArea) {
  Circle c(5.0);
  c.setFerence(2 * PI * 15.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 15.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 15.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 15.0 * 15.0);
}

TEST(CircleTest, SetAreaUpdatesRadiusAndFerence) {
  Circle c(5.0);
  c.setArea(PI * 20.0 * 20.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 20.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 20.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 20.0 * 20.0);
}

TEST(CircleTest, FerenceCalculation) {
  Circle c(7.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 7.0);
}

TEST(CircleTest, AreaCalculation) {
  Circle c(3.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 3.0 * 3.0);
}

TEST(CircleTest, ZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, NegativeRadius) {
  Circle c(-5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * -5.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * -5.0 * -5.0);
}

TEST(CircleTest, LargeRadius) {
  Circle c(1e6);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 1e6);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 1e6 * 1e6);
}

TEST(CircleTest, SmallRadius) {
  Circle c(1e-6);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1e-6);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 1e-6);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 1e-6 * 1e-6);
}

TEST(CircleTest, ZeroArea) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ZeroFerence) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, NegativeArea) {
  Circle c(-5.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 25.0);
}

TEST(CircleTest, NegativeFerence) {
  Circle c(-5.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 5.0);
}

TEST(CircleTest, LargeArea) {
  Circle c(1e6);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 1e12);
}

TEST(CircleTest, LargeFerence) {
  Circle c(1e6);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 1e6);
}

TEST(EarthRopeTest, CalculateGap) {
  double gap = calculateGap();
  EXPECT_NEAR(gap, 0.159154943, 1e-6);
}

TEST(EarthRopeTest, GapWithIncreasedRope) {
  double earthRadius = 6378.1;
  Circle earth(earthRadius);
  double ropeLength = earth.getFerence() + 0.01;
  earth.setFerence(ropeLength);
  double newRadius = earth.getRadius();
  double gap = newRadius - earthRadius;
  EXPECT_NEAR(gap, 0.159154943, 1e-6);
}

TEST(PoolTest, CalculatePoolCost) {
  double cost = calculatePoolCost();
  double expectedCost = (PI * (16 - 9) * 1000) + (2 * PI * 4 * 2000);
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, PathAreaCalculation) {
  double poolRadius = 3.0;
  double pathWidth = 1.0;
  Circle pool(poolRadius);
  Circle poolWithPath(poolRadius + pathWidth);
  double pathArea = poolWithPath.getArea() - pool.getArea();
  EXPECT_NEAR(pathArea, PI * (16 - 9), 1e-6);
}

TEST(PoolTest, FenceLengthCalculation) {
  double poolRadius = 3.0;
  double pathWidth = 1.0;
  Circle poolWithPath(poolRadius + pathWidth);
  double fenceLength = poolWithPath.getFerence();
  EXPECT_NEAR(fenceLength, 2 * PI * 4, 1e-6);
}
