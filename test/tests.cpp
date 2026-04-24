// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
double Pi() {
  return std::acos(-1.0);
}
}

TEST(CircleConstructor, ZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleConstructor, PositiveRadiusComputesValues) {
  Circle c(2.5);
  EXPECT_DOUBLE_EQ(c.getRadius(), 2.5);
  EXPECT_NEAR(c.getFerence(), 2.0 * Pi() * 2.5, 1e-12);
  EXPECT_NEAR(c.getArea(), Pi() * 2.5 * 2.5, 1e-12);
}

TEST(CircleConstructor, NegativeRadiusThrows) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleSetRadius, UpdatesFerenceAndArea) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * Pi() * 3.0, 1e-12);
  EXPECT_NEAR(c.getArea(), Pi() * 9.0, 1e-12);
}

TEST(CircleSetRadius, SettingZeroResetsValues) {
  Circle c(5.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleSetRadius, NegativeThrows) {
  Circle c(1.0);
  EXPECT_THROW(c.setRadius(-0.0001), std::invalid_argument);
}

TEST(CircleSetFerence, ComputesRadiusAndArea) {
  Circle c(1.0);
  c.setFerence(10.0);
  EXPECT_NEAR(c.getRadius(), 10.0 / (2.0 * Pi()), 1e-12);
  EXPECT_NEAR(c.getArea(), Pi() * c.getRadius() * c.getRadius(), 1e-12);
  EXPECT_DOUBLE_EQ(c.getFerence(), 10.0);
}

TEST(CircleSetFerence, ZeroSetsRadiusZero) {
  Circle c(4.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleSetFerence, NegativeThrows) {
  Circle c(1.0);
  EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleSetArea, ComputesRadiusAndFerence) {
  Circle c(1.0);
  c.setArea(12.0);
  EXPECT_NEAR(c.getRadius(), std::sqrt(12.0 / Pi()), 1e-12);
  EXPECT_NEAR(c.getFerence(), 2.0 * Pi() * c.getRadius(), 1e-12);
  EXPECT_DOUBLE_EQ(c.getArea(), 12.0);
}

TEST(CircleSetArea, ZeroSetsRadiusZero) {
  Circle c(4.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleSetArea, NegativeThrows) {
  Circle c(1.0);
  EXPECT_THROW(c.setArea(-0.5), std::invalid_argument);
}

TEST(CircleConsistency, SetRadiusThenSetFerence) {
  Circle c(2.0);
  c.setRadius(7.0);
  c.setFerence(c.getFerence());
  EXPECT_NEAR(c.getRadius(), 7.0, 1e-12);
  EXPECT_NEAR(c.getArea(), Pi() * 49.0, 1e-12);
}

TEST(CircleConsistency, SetRadiusThenSetArea) {
  Circle c(2.0);
  c.setRadius(4.0);
  c.setArea(c.getArea());
  EXPECT_NEAR(c.getRadius(), 4.0, 1e-12);
  EXPECT_NEAR(c.getFerence(), 2.0 * Pi() * 4.0, 1e-12);
}

TEST(CircleConsistency, SetFerenceThenSetArea) {
  Circle c(1.0);
  c.setFerence(2.0 * Pi() * 3.5);
  c.setArea(c.getArea());
  EXPECT_NEAR(c.getRadius(), 3.5, 1e-12);
  EXPECT_NEAR(c.getFerence(), 2.0 * Pi() * 3.5, 1e-12);
}

TEST(CircleConsistency, SetAreaThenSetFerence) {
  Circle c(1.0);
  c.setArea(Pi() * 8.0 * 8.0);
  c.setFerence(c.getFerence());
  EXPECT_NEAR(c.getRadius(), 8.0, 1e-12);
  EXPECT_NEAR(c.getArea(), Pi() * 64.0, 1e-10);
}

TEST(TasksRopeGap, OneMeterGapValue) {
  const double gap = GetRopeGapAfterAddingLength(1.0);
  EXPECT_NEAR(gap, 1.0 / (2.0 * Pi()), 1e-9);
}

TEST(TasksRopeGap, DependsOnlyOnAddedLength) {
  const double g1 = GetRopeGapAfterAddingLength(1.0);
  const double g2 = GetRopeGapAfterAddingLength(2.0);
  EXPECT_NEAR(g2, 2.0 * g1, 1e-12);
}

TEST(TasksRopeGap, ZeroAddedLengthGivesZeroGap) {
  EXPECT_DOUBLE_EQ(GetRopeGapAfterAddingLength(0.0), 0.0);
}

TEST(TasksRopeGap, NegativeAddedLengthThrows) {
  EXPECT_THROW(GetRopeGapAfterAddingLength(-1.0), std::invalid_argument);
}

TEST(TasksPool, ConcreteCostExample) {
  const double cost = GetPoolConcreteCost(3.0, 1.0, 1000.0);
  EXPECT_NEAR(cost, (Pi() * (16.0 - 9.0)) * 1000.0, 1e-9);
}

TEST(TasksPool, FenceCostExample) {
  const double cost = GetPoolFenceCost(3.0, 1.0, 2000.0);
  EXPECT_NEAR(cost, (2.0 * Pi() * 4.0) * 2000.0, 1e-9);
}

TEST(TasksPool, ZeroPathWidthConcreteZero) {
  const double cost = GetPoolConcreteCost(3.0, 0.0, 1000.0);
  EXPECT_NEAR(cost, 0.0, 1e-12);
}

TEST(TasksPool, ZeroCostRatesYieldZero) {
  EXPECT_DOUBLE_EQ(GetPoolConcreteCost(3.0, 1.0, 0.0), 0.0);
  EXPECT_DOUBLE_EQ(GetPoolFenceCost(3.0, 1.0, 0.0), 0.0);
}

TEST(TasksPool, NegativeArgumentsThrow) {
  EXPECT_THROW(GetPoolConcreteCost(-1.0, 1.0, 1000.0), std::invalid_argument);
  EXPECT_THROW(GetPoolConcreteCost(1.0, -1.0, 1000.0), std::invalid_argument);
  EXPECT_THROW(GetPoolConcreteCost(1.0, 1.0, -1.0), std::invalid_argument);
  EXPECT_THROW(GetPoolFenceCost(-1.0, 1.0, 2000.0), std::invalid_argument);
  EXPECT_THROW(GetPoolFenceCost(1.0, -1.0, 2000.0), std::invalid_argument);
  EXPECT_THROW(GetPoolFenceCost(1.0, 1.0, -1.0), std::invalid_argument);
}


