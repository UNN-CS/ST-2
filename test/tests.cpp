// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

static constexpr double PI = 3.14159265358979323846;
static constexpr double EPSILON = 1e-10;

// ============ Basic Circle Constructor Tests ============

TEST(CircleConstructor, RadiusSetCorrectly) {
  Circle circle(7.0);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 7.0);
}

TEST(CircleConstructor, CircumferenceCalculatedAtConstruction) {
  Circle circle(3.5);
  double expected = 2.0 * PI * 3.5;
  EXPECT_DOUBLE_EQ(circle.getFerence(), expected);
}

TEST(CircleConstructor, AreaCalculatedAtConstruction) {
  Circle circle(2.0);
  double expected = PI * 4.0;
  EXPECT_DOUBLE_EQ(circle.getArea(), expected);
}

// ============ Set Radius Tests ============

TEST(CircleSetRadius, ChangesRadiusValue) {
  Circle circle(1.0);
  circle.setRadius(5.0);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 5.0);
}

TEST(CircleSetRadius, UpdatesCircumference) {
  Circle circle(2.0);
  circle.setRadius(6.0);
  double expected = 2.0 * PI * 6.0;
  EXPECT_DOUBLE_EQ(circle.getFerence(), expected);
}

TEST(CircleSetRadius, UpdatesArea) {
  Circle circle(1.0);
  circle.setRadius(4.0);
  double expected = PI * 16.0;
  EXPECT_DOUBLE_EQ(circle.getArea(), expected);
}

TEST(CircleSetRadius, MultipleUpdates) {
  Circle circle(1.0);
  circle.setRadius(2.0);
  circle.setRadius(3.0);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 3.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 2.0 * PI * 3.0);
  EXPECT_DOUBLE_EQ(circle.getArea(), PI * 9.0);
}

// ============ Set Circumference Tests ============

TEST(CircleSetFerence, ChangesCircumferenceValue) {
  Circle circle(1.0);
  double newFerence = 2.0 * PI * 5.0;
  circle.setFerence(newFerence);
  EXPECT_NEAR(circle.getFerence(), newFerence, EPSILON);
}

TEST(CircleSetFerence, CalculatesRadiusCorrectly) {
  Circle circle(1.0);
  double newFerence = 2.0 * PI * 8.0;
  circle.setFerence(newFerence);
  EXPECT_NEAR(circle.getRadius(), 8.0, EPSILON);
}

TEST(CircleSetFerence, UpdatesAreaCorrectly) {
  Circle circle(1.0);
  double newFerence = 2.0 * PI * 3.0;
  circle.setFerence(newFerence);
  EXPECT_NEAR(circle.getArea(), PI * 9.0, EPSILON);
}

// ============ Set Area Tests ============

TEST(CircleSetArea, ChangesAreaValue) {
  Circle circle(1.0);
  double newArea = PI * 25.0;
  circle.setArea(newArea);
  EXPECT_NEAR(circle.getArea(), newArea, EPSILON);
}

TEST(CircleSetArea, CalculatesRadiusCorrectly) {
  Circle circle(1.0);
  double newArea = PI * 36.0;
  circle.setArea(newArea);
  EXPECT_NEAR(circle.getRadius(), 6.0, EPSILON);
}

TEST(CircleSetArea, UpdatesCircumferenceCorrectly) {
  Circle circle(1.0);
  double newArea = PI * 16.0;
  circle.setArea(newArea);
  EXPECT_NEAR(circle.getFerence(), 2.0 * PI * 4.0, EPSILON);
}

// ============ Special Cases ============

TEST(CircleSpecial, VerySmallRadius) {
  Circle circle(0.0001);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 0.0001);
  EXPECT_NEAR(circle.getFerence(), 2.0 * PI * 0.0001, 1e-14);
}

TEST(CircleSpecial, VeryLargeRadius) {
  Circle circle(1e6);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 1e6);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 2.0 * PI * 1e6);
}

TEST(CircleSpecial, UnitCircle) {
  Circle circle(1.0);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 1.0);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 2.0 * PI);
  EXPECT_DOUBLE_EQ(circle.getArea(), PI);
}

// ============ Earth and Rope Task Tests ============

TEST(RopeTask, EarthExampleGap) {
  double gap = ropeGap(6378100.0, 1.0);
  double expected = 1.0 / (2.0 * PI);
  EXPECT_NEAR(gap, expected, 1e-8);
}

TEST(RopeTask, SmallPlanetAddOneUnit) {
  double gap = ropeGap(100.0, 1.0);
  double expected = 1.0 / (2.0 * PI);
  EXPECT_NEAR(gap, expected, EPSILON);
}

TEST(RopeTask, NoAddedLengthGivesZeroGap) {
  double gap = ropeGap(50.0, 0.0);
  EXPECT_NEAR(gap, 0.0, EPSILON);
}

TEST(RopeTask, LargerAddedLength) {
  double gap = ropeGap(1000.0, 10.0);
  double expected = 10.0 / (2.0 * PI);
  EXPECT_NEAR(gap, expected, EPSILON);
}

TEST(RopeTask, GapIndependentOfPlanetSize) {
  double gap1 = ropeGap(100.0, 5.0);
  double gap2 = ropeGap(10000.0, 5.0);
  EXPECT_NEAR(gap1, gap2, EPSILON);
}

// ============ Pool Task Tests ============

TEST(PoolTask, StandardPoolConcreteCost) {
  // Pool radius 3m, walkway width 1m, price 1000 per sqm
  double cost = poolConcreteCost(3.0, 1.0, 1000.0);
  
  // Expected: (pi * 4^2 - pi * 3^2) * 1000 = (16pi - 9pi) * 1000 = 7pi * 1000
  double expected = (7.0 * PI) * 1000.0;
  EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(PoolTask, StandardPoolFenceCost) {
  // Fence at outer radius (3 + 1 = 4m), price 2000 per meter
  double cost = poolFenceCost(3.0, 1.0, 2000.0);
  
  // Expected: 2 * pi * 4 * 2000 = 16000 * pi
  double expected = 2.0 * PI * 4.0 * 2000.0;
  EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(PoolTask, DifferentPoolSize) {
  // Pool radius 5m, walkway 2m, price 500 per sqm
  double cost = poolConcreteCost(5.0, 2.0, 500.0);
  
  // Expected: (pi * 7^2 - pi * 5^2) * 500 = (49pi - 25pi) * 500 = 24pi * 500
  double expected = (24.0 * PI) * 500.0;
  EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(PoolTask, ZeroWalkwayWidth) {
  // No walkway means no concrete cost
  double cost = poolConcreteCost(3.0, 0.0, 1000.0);
  EXPECT_NEAR(cost, 0.0, EPSILON);
}

TEST(PoolTask, SmallPool) {
  // Small pool with larger price
  double cost = poolConcreteCost(1.0, 0.5, 5000.0);
  
  // Expected: (pi * 1.5^2 - pi * 1.0^2) * 5000 = (2.25pi - pi) * 5000 = 1.25pi * 5000
  double expected = (1.25 * PI) * 5000.0;
  EXPECT_NEAR(cost, expected, 1e-5);
}

TEST(PoolTask, LargePoolFence) {
  // Large pool fence calculation
  double cost = poolFenceCost(10.0, 1.0, 1500.0);
  
  // Expected: 2 * pi * 11 * 1500
  double expected = 2.0 * PI * 11.0 * 1500.0;
  EXPECT_NEAR(cost, expected, 1e-5);
}
