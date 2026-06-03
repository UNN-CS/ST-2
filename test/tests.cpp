// Copyright 2024 Nazyrov A.A.

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

// ============ Тесты для класса Circle ============

TEST(CircleTest, ConstructorSetsCorrectRadius) {
  geometry::Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, ConstructorCalculatesCircumference) {
  geometry::Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * 3.141592653589793 * 5.0);
}

TEST(CircleTest, ConstructorCalculatesArea) {
  geometry::Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * 25.0);
}

TEST(CircleTest, SetRadiusUpdatesCircumference) {
  geometry::Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * 3.141592653589793 * 10.0);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
  geometry::Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * 100.0);
}

TEST(CircleTest, SetCircumferenceUpdatesRadius) {
  geometry::Circle c(1.0);
  c.setCircumference(2.0 * 3.141592653589793 * 5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, SetCircumferenceUpdatesArea) {
  geometry::Circle c(1.0);
  double expectedArea = 3.141592653589793 * 25.0;
  c.setCircumference(2.0 * 3.141592653589793 * 5.0);
  EXPECT_DOUBLE_EQ(c.getArea(), expectedArea);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
  geometry::Circle c(1.0);
  c.setArea(3.141592653589793 * 100.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

TEST(CircleTest, SetAreaUpdatesCircumference) {
  geometry::Circle c(1.0);
  c.setArea(3.141592653589793 * 100.0);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 2.0 * 3.141592653589793 * 10.0);
}

TEST(CircleTest, ZeroRadius) {
  geometry::Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getCircumference(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, NegativeRadiusIgnored) {
  geometry::Circle c(5.0);
  c.setRadius(-10.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, NegativeCircumferenceIgnored) {
  geometry::Circle c(5.0);
  double origRadius = c.getRadius();
  c.setCircumference(-100.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), origRadius);
}

// ============ Тесты для задачи "Земля и верёвка" ============

TEST(RopeGapTest, GapIsPositive) {
  double gap = tasks::calculateRopeGap();
  EXPECT_GT(gap, 0.0);
}

TEST(RopeGapTest, GapAboutFifteenCentimeters) {
  double gap = tasks::calculateRopeGap();
  EXPECT_NEAR(gap, 0.159, 0.01);
}

// ============ Тесты для задачи "Бассейн" ============

TEST(PoolCostTest, ConcreteCostCalculation) {
  double concreteCost = 0.0, fenceCost = 0.0;
  tasks::calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0,
                            concreteCost, fenceCost);
  EXPECT_NEAR(concreteCost, 21991.0, 10.0);
}

TEST(PoolCostTest, FenceCostCalculation) {
  double concreteCost = 0.0, fenceCost = 0.0;
  tasks::calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0,
                            concreteCost, fenceCost);
  EXPECT_NEAR(fenceCost, 50265.0, 10.0);
}

TEST(PoolCostTest, TotalCostPositive) {
  double concreteCost = 0.0, fenceCost = 0.0;
  tasks::calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0,
                            concreteCost, fenceCost);
  EXPECT_GT(concreteCost + fenceCost, 0.0);
}

TEST(PoolCostTest, ZeroPathWidth) {
  double concreteCost = 0.0, fenceCost = 0.0;
  tasks::calculatePoolCosts(3.0, 0.0, 1000.0, 2000.0,
                            concreteCost, fenceCost);
  EXPECT_NEAR(concreteCost, 0.0, 1.0);
  EXPECT_NEAR(fenceCost, 2.0 * 3.141592653589793 * 3.0 * 2000.0, 10.0);
}

TEST(PoolCostTest, DifferentPrices) {
  double concreteCost1 = 0.0, fenceCost1 = 0.0;
  double concreteCost2 = 0.0, fenceCost2 = 0.0;
  tasks::calculatePoolCosts(3.0, 1.0, 500.0, 1000.0,
                            concreteCost1, fenceCost1);
  tasks::calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0,
                            concreteCost2, fenceCost2);
  EXPECT_DOUBLE_EQ(concreteCost2, concreteCost1 * 2.0);
  EXPECT_DOUBLE_EQ(fenceCost2, fenceCost1 * 2.0);
}

TEST(PoolCostTest, DifferentRadius) {
  double concreteCost1 = 0.0, fenceCost1 = 0.0;
  double concreteCost2 = 0.0, fenceCost2 = 0.0;
  tasks::calculatePoolCosts(5.0, 1.0, 1000.0, 2000.0,
                            concreteCost1, fenceCost1);
  tasks::calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0,
                            concreteCost2, fenceCost2);
  EXPECT_GT(concreteCost1, concreteCost2);
  EXPECT_GT(fenceCost1, fenceCost2);
}
