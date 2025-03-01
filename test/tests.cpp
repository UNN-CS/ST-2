#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "../include/task.h"
#include "circle.h"

const double PI = 3.141592653589793;
TEST(CircleTest, RadiusInitialization) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.GetRadius(), 5.0);
}

TEST(CircleTest, SetRadiusUpdatesFerenceAndArea) {
  Circle c(5.0);
  c.SetRadius(10.0);
  EXPECT_DOUBLE_EQ(c.GetRadius(), 10.0);
  EXPECT_DOUBLE_EQ(c.GetFerence(), 2 * PI * 10.0);
  EXPECT_DOUBLE_EQ(c.GetArea(), PI * 10.0 * 10.0);
}

TEST(CircleTest, SetFerenceUpdatesRadiusAndArea) {
  Circle c(5.0);
  c.SetFerence(2 * PI * 8.0);
  EXPECT_DOUBLE_EQ(c.GetRadius(), 8.0);
  EXPECT_DOUBLE_EQ(c.GetArea(), PI * 8.0 * 8.0);
}

TEST(CircleTest, SetAreaUpdatesRadiusAndFerence) {
  Circle c(5.0);
  c.SetArea(PI * 7.0 * 7.0);
  EXPECT_DOUBLE_EQ(c.GetRadius(), 7.0);
  EXPECT_DOUBLE_EQ(c.GetFerence(), 2 * PI * 7.0);
}

TEST(CircleTest, ZeroRadius) {
  Circle c(0);
  EXPECT_DOUBLE_EQ(c.GetRadius(), 0);
  EXPECT_DOUBLE_EQ(c.GetFerence(), 0);
  EXPECT_DOUBLE_EQ(c.GetArea(), 0);
}

TEST(CircleTest, LargeRadius) {
  Circle c(1e6);
  EXPECT_DOUBLE_EQ(c.GetFerence(), 2 * PI * 1e6);
  EXPECT_DOUBLE_EQ(c.GetArea(), PI * 1e6 * 1e6);
}

TEST(RopeTest, SmallIncrease) {
  double gap = CalculateRopeGap(6378.1 * 1000, 1);
  EXPECT_NEAR(gap, 1 / (2 * PI), 1e-6);
}

TEST(RopeTest, NoIncrease) {
  double gap = CalculateRopeGap(6378.1 * 1000, 0);
  EXPECT_DOUBLE_EQ(gap, 0);
}

TEST(PoolTest, BasicCalculation) {
  double cost = CalculatePoolCost(3, 1, 1000, 2000);
  double expectedCost = (PI * (4 * 4 - 3 * 3) * 1000) + (2 * PI * 4 * 2000);
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, NoPath) {
  double cost = CalculatePoolCost(3, 0, 1000, 2000);
  double expectedCost = 2 * PI * 3 * 2000;
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, LargePool) {
  double cost = CalculatePoolCost(100, 10, 500, 1500);
  double expectedCost =
    (PI * (110 * 110 - 100 * 100) * 500) + (2 * PI * 110 * 1500);
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

TEST(PoolTest, ZeroRadius) {
  double cost = CalculatePoolCost(0, 5, 500, 1500);
  double expectedCost = (PI * 5 * 5 * 500) + (2 * PI * 5 * 1500);
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}

