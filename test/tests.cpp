// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.14159265358979323846;
constexpr double kEps = 1e-9;
}

TEST(Circle, ConstructorSetsRadius) {
  Circle c(5.0);
  EXPECT_NEAR(c.getRadius(), 5.0, kEps);
}

TEST(Circle, ConstructorCalculatesFerence) {
  Circle c(5.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 5.0, kEps);
}

TEST(Circle, ConstructorCalculatesArea) {
  Circle c(5.0);
  EXPECT_NEAR(c.getArea(), kPi * 25.0, kEps);
}

TEST(Circle, ConstructorThrowsOnNegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(Circle, SetRadiusUpdatesAllFields) {
  Circle c(1.0);
  c.setRadius(2.0);

  EXPECT_NEAR(c.getRadius(), 2.0, kEps);
  EXPECT_NEAR(c.getFerence(), 4.0 * kPi, kEps);
  EXPECT_NEAR(c.getArea(), 4.0 * kPi, kEps);
}

TEST(Circle, SetRadiusToZeroWorks) {
  Circle c(2.0);
  c.setRadius(0.0);

  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle, SetRadiusThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setRadius(-0.1), std::invalid_argument);
}

TEST(Circle, SetFerenceUpdatesRadius) {
  Circle c(1.0);
  c.setFerence(10.0);
  EXPECT_NEAR(c.getRadius(), 10.0 / (2.0 * kPi), kEps);
}

TEST(Circle, SetFerenceUpdatesArea) {
  Circle c(1.0);
  c.setFerence(10.0);
  const double expected_radius = 10.0 / (2.0 * kPi);
  EXPECT_NEAR(c.getArea(), kPi * expected_radius * expected_radius, kEps);
}

TEST(Circle, SetFerenceToZeroWorks) {
  Circle c(1.0);
  c.setFerence(0.0);

  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle, SetFerenceThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(Circle, SetAreaUpdatesRadius) {
  Circle c(1.0);
  c.setArea(9.0 * kPi);
  EXPECT_NEAR(c.getRadius(), 3.0, kEps);
}

TEST(Circle, SetAreaUpdatesFerence) {
  Circle c(1.0);
  c.setArea(9.0 * kPi);
  EXPECT_NEAR(c.getFerence(), 6.0 * kPi, kEps);
}

TEST(Circle, SetAreaToZeroWorks) {
  Circle c(1.0);
  c.setArea(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
}

TEST(Circle, SetAreaThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
}

TEST(Circle, ChainedSettersKeepConsistency) {
  Circle c(2.0);
  c.setFerence(20.0);
  c.setArea(16.0 * kPi);
  c.setRadius(1.5);

  EXPECT_NEAR(c.getFerence(), 3.0 * kPi, kEps);
  EXPECT_NEAR(c.getArea(), 2.25 * kPi, kEps);
}

TEST(Tasks, EarthRopeGapForOneMeter) {
  const double gap = solveEarthRopeTask();
  EXPECT_NEAR(gap, 1.0 / (2.0 * kPi), 1e-12);
}

TEST(Tasks, EarthRopeGapIndependentFromRadius) {
  const double gap_small = solveEarthRopeTask(1.0, 1.0);
  const double gap_large = solveEarthRopeTask(6378.1, 1.0);
  EXPECT_NEAR(gap_small, gap_large, 1e-12);
}

TEST(Tasks, EarthRopeTaskThrowsOnNegativeRadius) {
  EXPECT_THROW(solveEarthRopeTask(-1.0, 1.0), std::invalid_argument);
}

TEST(Tasks, EarthRopeTaskThrowsOnNegativeExtraLength) {
  EXPECT_THROW(solveEarthRopeTask(1.0, -1.0), std::invalid_argument);
}

TEST(Tasks, EarthRopeTaskZeroExtraLengthReturnsZeroGap) {
  EXPECT_NEAR(solveEarthRopeTask(6378.1, 0.0), 0.0, kEps);
}

TEST(Tasks, PoolConcreteCostDefaultInput) {
  const PoolCosts costs = solvePoolTask();
  EXPECT_NEAR(costs.concrete_cost, 7000.0 * kPi, kEps);
}

TEST(Tasks, PoolFenceCostDefaultInput) {
  const PoolCosts costs = solvePoolTask();
  EXPECT_NEAR(costs.fence_cost, 16000.0 * kPi, kEps);
}

TEST(Tasks, PoolTotalCostIsSumOfParts) {
  const PoolCosts costs = solvePoolTask();
  EXPECT_NEAR(costs.total_cost, costs.concrete_cost + costs.fence_cost, kEps);
}

TEST(Tasks, PoolTaskWorksWithCustomValues) {
  const PoolCosts costs = solvePoolTask(2.0, 0.5, 1200.0, 2500.0);
  const double outer_radius = 2.5;
  const double concrete =
      (kPi * outer_radius * outer_radius - kPi * 4.0) * 1200.0;
  const double fence = (2.0 * kPi * outer_radius) * 2500.0;

  EXPECT_NEAR(costs.concrete_cost, concrete, kEps);
  EXPECT_NEAR(costs.fence_cost, fence, kEps);
  EXPECT_NEAR(costs.total_cost, concrete + fence, kEps);
}

TEST(Tasks, PoolTaskThrowsOnNegativePoolRadius) {
  EXPECT_THROW(solvePoolTask(-1.0, 1.0, 1000.0, 2000.0), std::invalid_argument);
}

TEST(Tasks, PoolTaskThrowsOnNegativePathWidth) {
  EXPECT_THROW(solvePoolTask(3.0, -1.0, 1000.0, 2000.0), std::invalid_argument);
}

TEST(Tasks, PoolTaskThrowsOnNegativeConcretePrice) {
  EXPECT_THROW(solvePoolTask(3.0, 1.0, -1000.0, 2000.0), std::invalid_argument);
}

TEST(Tasks, PoolTaskThrowsOnNegativeFencePrice) {
  EXPECT_THROW(solvePoolTask(3.0, 1.0, 1000.0, -2000.0), std::invalid_argument);
}

TEST(Tasks, PoolTaskZeroPathWidthMeansZeroConcreteCost) {
  const PoolCosts costs = solvePoolTask(3.0, 0.0, 1000.0, 2000.0);
  EXPECT_NEAR(costs.concrete_cost, 0.0, kEps);
}


