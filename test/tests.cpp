// Copyright 2025 shvedovav
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

TEST(CircleTests, ConstructorTest) {
  Circle c(2.5);
  EXPECT_DOUBLE_EQ(c.getRadius(), 2.5);
  EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 2.5, 1e-9);
  EXPECT_NEAR(c.getArea(), M_PI * 2.5 * 2.5, 1e-9);
}

TEST(CircleTests, SetRadiusTest) {
  Circle c(1.0);
  c.setRadius(4.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
  EXPECT_NEAR(c.getFerence(), 8.0 * M_PI, 1e-9);
  EXPECT_NEAR(c.getArea(), 16.0 * M_PI, 1e-9);
}

TEST(CircleTests, SetFerenceTest) {
  Circle c(1.0);
  c.setFerence(31.4159265);
  EXPECT_NEAR(c.getRadius(), 5.0, 1e-6);
  EXPECT_NEAR(c.getArea(), 25.0 * M_PI, 1e-6);
}

TEST(CircleTests, SetAreaTest) {
  Circle c(1.0);
  c.setArea(100.0 * M_PI);
  EXPECT_NEAR(c.getRadius(), 10.0, 1e-7);
  EXPECT_NEAR(c.getFerence(), 20.0 * M_PI, 1e-7);
}

TEST(CircleTests, ZeroRadiusTest) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, NegativeRadiusTest) {
  Circle c(-2.0);
  EXPECT_NEAR(c.getRadius(), -2.0, 1e-9);
  EXPECT_NEAR(c.getFerence(), -4.0 * M_PI, 1e-9);
  EXPECT_NEAR(c.getArea(), 4.0 * M_PI, 1e-9);
}

TEST(CircleTests, SmallRadiusTest) {
  Circle c(0.001);
  EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 0.001, 1e-12);
  EXPECT_NEAR(c.getArea(), M_PI * 0.001 * 0.001, 1e-15);
}

TEST(CircleTests, LargeRadiusTest) {
  Circle c(1e7);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1e7);
  EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 1e7, 1e-1);
  EXPECT_NEAR(c.getArea(), M_PI * 1e14, 1e6);
}

TEST(CircleTests, MultipleSettersTest) {
  Circle c(3.0);
  c.setFerence(100.0);
  c.setArea(400.0 * M_PI);
  EXPECT_NEAR(c.getRadius(), 20.0, 1e-7);
  EXPECT_NEAR(c.getFerence(), 40.0 * M_PI, 1e-7);
  EXPECT_NEAR(c.getArea(), 400.0 * M_PI, 1e-9);
}

TEST(CircleTests, SetterSequenceTest) {
  Circle c(5.0);
  c.setFerence(15.70796327);
  c.setRadius(4.0);
  c.setArea(36.0 * M_PI);
  EXPECT_NEAR(c.getRadius(), 6.0, 1e-7);
  EXPECT_NEAR(c.getFerence(), 12.0 * M_PI, 1e-7);
  EXPECT_NEAR(c.getArea(), 36.0 * M_PI, 1e-7);
}

TEST(CircleTests, InfinityRadiusTest) {
  Circle c(std::numeric_limits<double>::infinity());
  EXPECT_TRUE(std::isinf(c.getRadius()));
  EXPECT_TRUE(std::isinf(c.getFerence()));
  EXPECT_TRUE(std::isinf(c.getArea()));
}

TEST(CircleTests, VerySmallFerenceTest) {
  Circle c(10.0);
  c.setFerence(1e-9);
  EXPECT_NEAR(c.getRadius(), 1e-9 / (2.0 * M_PI), 1e-15);
  EXPECT_NEAR(c.getArea(), M_PI * c.getRadius() * c.getRadius(), 1e-20);
}

TEST(CircleTests, AreaFerenceBackAndForthTest) {
  Circle c(1.0);
  c.setArea(50.0 * M_PI);
  double r1 = std::sqrt((50.0 * M_PI) / M_PI);
  double f1 = 2.0 * M_PI * r1;
  EXPECT_NEAR(c.getRadius(), r1, 1e-7);
  EXPECT_NEAR(c.getFerence(), f1, 1e-7);
  c.setFerence(40.0 * M_PI);
  double r2 = (40.0 * M_PI) / (2.0 * M_PI);
  double a2 = M_PI * r2 * r2;
  EXPECT_NEAR(c.getRadius(), r2, 1e-7);
  EXPECT_NEAR(c.getArea(), a2, 1e-7);
}

TEST(CircleTests, ExtremelyCloseToZeroRadiusTest) {
  Circle c(1e-15);
  EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 1e-15, 1e-22);
  EXPECT_NEAR(c.getArea(), M_PI * 1e-30, 1e-35);
}

TEST(RopeGapTests, StandardEarthGap) {
  double gap = ropeGapTask();
  EXPECT_NEAR(gap, 1.0 / (2.0 * M_PI), 1e-6);
}

TEST(RopeGapTests, CompareWithCalculatedValue) {
  double gap = ropeGapTask();
  EXPECT_NEAR(gap, 0.15915, 1e-5);
}

TEST(RopeGapTests, IsPositiveGap) {
  double gap = ropeGapTask();
  EXPECT_GT(gap, 0.0);
}

TEST(RopeGapTests, RepeatedCallsConsistency) {
  double gap1 = ropeGapTask();
  double gap2 = ropeGapTask();
  EXPECT_NEAR(gap1, gap2, 1e-12);
}

TEST(RopeGapTests, WithinExpectedBounds) {
  double gap = ropeGapTask();
  EXPECT_GT(gap, 0.15);
  EXPECT_LT(gap, 0.17);
}

TEST(PoolCostTests, CorrectValue) {
  double cost = poolCostTask();
  double expected = 23000.0 * M_PI;
  EXPECT_NEAR(cost, expected, 1e-5);
}

TEST(PoolCostTests, IsPositiveCost) {
  double cost = poolCostTask();
  EXPECT_GT(cost, 0.0);
}

TEST(PoolCostTests, RepeatedCallsConsistency) {
  double cost1 = poolCostTask();
  double cost2 = poolCostTask();
  EXPECT_NEAR(cost1, cost2, 1e-12);
}

TEST(PoolCostTests, CompareWithManualCalculation) {
  double cost = poolCostTask();
  double manual = 23000.0 * M_PI;
  EXPECT_NEAR(cost, manual, 1e-7);
}

TEST(PoolCostTests, NoUnexpectedDeviation) {
  double cost = poolCostTask();
  double expected = 23000.0 * M_PI;
  EXPECT_NEAR(cost, expected, 1e-5);
}
