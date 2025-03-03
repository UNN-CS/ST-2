// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "../include/task.h"
#include "circle.h"

const double PI = 3.141592653589793;
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
  c.setFerence(2 * PI * 8.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 8.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 8.0 * 8.0);
}

TEST(CircleTest, SetAreaUpdatesRadiusAndFerence) {
  Circle c(5.0);
  c.setArea(PI * 7.0 * 7.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 7.0);
}

TEST(CircleTest, ZeroRadius) {
  Circle c(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, LargeRadius) {
  Circle c(1e6);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 1e6);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 1e6 * 1e6);
}

TEST(CircleTest, NegativeRadius) {
  Circle c(-5.0);
  EXPECT_LT(c.getRadius(), 0);
}

TEST(CircleTest, SetNegativeRadius) {
  Circle c(5.0);
  c.setRadius(-10.0);
  EXPECT_LT(c.getRadius(), 0);
}

TEST(CircleTest, SetFerenceZero) {
  Circle c(5.0);
  c.setFerence(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
}

TEST(CircleTest, SetAreaZero) {
  Circle c(5.0);
  c.setArea(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
}

TEST(RopeTest, SmallIncrease) {
  double gap = calculateRopeGap(6378.1 * 1000, 1);
  EXPECT_NEAR(gap, 1 / (2 * PI), 1e-6);
}

TEST(RopeTest, NoIncrease) {
  double gap = calculateRopeGap(6378.1 * 1000, 0);
  EXPECT_DOUBLE_EQ(gap, 0);
}

TEST(RopeTest, LargeIncrease) {
  double gap = calculateRopeGap(6378.1 * 1000, 100);
  EXPECT_GT(gap, 10);
}

TEST(PoolTest, BasicCalculation) {
  double cost = calculatePoolCost(3, 1, 1000, 2000);
  double expectedCost = (PI * (4 * 4 - 3 * 3) * 1000) + (2 * PI * 4 * 2000);
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, NoPath) {
  double cost = calculatePoolCost(3, 0, 1000, 2000);
  double expectedCost = 2 * PI * 3 * 2000;
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, LargePool) {
  double cost = calculatePoolCost(100, 10, 500, 1500);
  double expectedCost =
    (PI * (110 * 110 - 100 * 100) * 500) + (2 * PI * 110 * 1500);
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, ZeroRadius) {
  double cost = calculatePoolCost(0, 5, 500, 1500);
  double expectedCost = (PI * 5 * 5 * 500) + (2 * PI * 5 * 1500);
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, ZeroConstructionCost) {
  double cost = calculatePoolCost(10, 5, 0, 1500);
  double expectedCost = 2 * PI * 15 * 1500;
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, ZeroBorderCost) {
  double cost = calculatePoolCost(10, 5, 1000, 0);
  double expectedCost = PI * (15 * 15 - 10 * 10) * 1000;
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}





