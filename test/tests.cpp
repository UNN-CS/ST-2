// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

static constexpr double PI = 3.14159265358979323846;
static constexpr double EPSILON = 1e-10;


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


TEST(PoolTask, StandardPoolConcreteCost) {
  double cost = poolConcreteCost(3.0, 1.0, 1000.0);
  
  double expected = (7.0 * PI) * 1000.0;
  EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(PoolTask, StandardPoolFenceCost) {
  double cost = poolFenceCost(3.0, 1.0, 2000.0);
  
  double expected = 2.0 * PI * 4.0 * 2000.0;
  EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(PoolTask, DifferentPoolSize) {
  double cost = poolConcreteCost(5.0, 2.0, 500.0);
  
  double expected = (24.0 * PI) * 500.0;
  EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(PoolTask, ZeroWalkwayWidth) {
  double cost = poolConcreteCost(3.0, 0.0, 1000.0);
  EXPECT_NEAR(cost, 0.0, EPSILON);
}

TEST(PoolTask, SmallPool) {
  double cost = poolConcreteCost(1.0, 0.5, 5000.0);
  
  double expected = (1.25 * PI) * 5000.0;
  EXPECT_NEAR(cost, expected, 1e-5);
}

TEST(PoolTask, LargePoolFence) {
  double cost = poolFenceCost(10.0, 1.0, 1500.0);
  
  double expected = 2.0 * PI * 11.0 * 1500.0;
  EXPECT_NEAR(cost, expected, 1e-5);
}
