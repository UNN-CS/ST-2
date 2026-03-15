// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double kEpsilon = 1e-9;

// Circle: Constructor and getters
TEST(Circle, ConstructorRadius1) {
  Circle c(1.0);
  EXPECT_NEAR(c.getRadius(), 1.0, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI, kEpsilon);
  EXPECT_NEAR(c.getArea(), M_PI, kEpsilon);
}

TEST(Circle, ConstructorRadius5) {
  Circle c(5.0);
  EXPECT_NEAR(c.getRadius(), 5.0, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 10 * M_PI, kEpsilon);
  EXPECT_NEAR(c.getArea(), 25 * M_PI, kEpsilon);
}

TEST(Circle, ConstructorRadius0) {
  Circle c(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 0.0, kEpsilon);
  EXPECT_NEAR(c.getArea(), 0.0, kEpsilon);
}

// Circle: setRadius
TEST(Circle, SetRadius) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_NEAR(c.getRadius(), 3.0, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 6 * M_PI, kEpsilon);
  EXPECT_NEAR(c.getArea(), 9 * M_PI, kEpsilon);
}

TEST(Circle, SetRadiusSmall) {
  Circle c(100.0);
  c.setRadius(0.001);
  EXPECT_NEAR(c.getRadius(), 0.001, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 0.001, kEpsilon);
  EXPECT_NEAR(c.getArea(), M_PI * 0.001 * 0.001, kEpsilon);
}

// Circle: setFerence
TEST(Circle, SetFerence) {
  Circle c(1.0);
  c.setFerence(4 * M_PI);
  EXPECT_NEAR(c.getRadius(), 2.0, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 4 * M_PI, kEpsilon);
  EXPECT_NEAR(c.getArea(), 4 * M_PI, kEpsilon);
}

TEST(Circle, SetFerenceTo2Pi) {
  Circle c(10.0);
  c.setFerence(2 * M_PI);
  EXPECT_NEAR(c.getRadius(), 1.0, kEpsilon);
  EXPECT_NEAR(c.getArea(), M_PI, kEpsilon);
}

// Circle: setArea
TEST(Circle, SetArea) {
  Circle c(1.0);
  c.setArea(4 * M_PI);
  EXPECT_NEAR(c.getRadius(), 2.0, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 4 * M_PI, kEpsilon);
  EXPECT_NEAR(c.getArea(), 4 * M_PI, kEpsilon);
}

TEST(Circle, SetAreaToPi) {
  Circle c(10.0);
  c.setArea(M_PI);
  EXPECT_NEAR(c.getRadius(), 1.0, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI, kEpsilon);
}

// Circle: consistency after setters
TEST(Circle, ConsistencySetRadiusThenGet) {
  Circle c(0.0);
  c.setRadius(7.0);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 7.0, kEpsilon);
  EXPECT_NEAR(c.getArea(), M_PI * 49.0, kEpsilon);
}

TEST(Circle, ConsistencySetFerenceThenGet) {
  Circle c(0.0);
  double circ = 100.0;
  c.setFerence(circ);
  EXPECT_NEAR(c.getRadius(), circ / (2 * M_PI), kEpsilon);
  double r = c.getRadius();
  EXPECT_NEAR(c.getArea(), M_PI * r * r, kEpsilon);
}

TEST(Circle, ConsistencySetAreaThenGet) {
  Circle c(0.0);
  double a = 50.0;
  c.setArea(a);
  EXPECT_NEAR(c.getRadius(), std::sqrt(a / M_PI), kEpsilon);
  double r = c.getRadius();
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * r, kEpsilon);
}

// Circle: large radius
TEST(Circle, LargeRadius) {
  Circle c(1e6);
  EXPECT_NEAR(c.getRadius(), 1e6, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, kEpsilon);
  EXPECT_NEAR(c.getArea(), M_PI * 1e12, kEpsilon);
}

// Circle: chained modifications
TEST(Circle, SetRadiusThenSetFerence) {
  Circle c(1.0);
  c.setRadius(2.0);
  c.setFerence(6 * M_PI);
  EXPECT_NEAR(c.getRadius(), 3.0, kEpsilon);
  EXPECT_NEAR(c.getFerence(), 6 * M_PI, kEpsilon);
  EXPECT_NEAR(c.getArea(), 9 * M_PI, kEpsilon);
}

// Tasks: Earth and Rope
TEST(EarthAndRope, GapIsPositive) {
  double gap = solveEarthAndRope();
  EXPECT_GT(gap, 0.0);
}

TEST(EarthAndRope, GapEquals1Over2Pi) {
  double gap = solveEarthAndRope();
  double expected = 1.0 / (2 * M_PI);
  EXPECT_NEAR(gap, expected, kEpsilon);
}

TEST(EarthAndRope, GapApproximately0159Meters) {
  double gap = solveEarthAndRope();
  EXPECT_NEAR(gap, 0.159, 0.001);
}

// Tasks: Pool
TEST(Pool, ConcreteCostPositive) {
  PoolCostResult r = solvePool();
  EXPECT_GT(r.concreteCost, 0.0);
}

TEST(Pool, FenceCostPositive) {
  PoolCostResult r = solvePool();
  EXPECT_GT(r.fenceCost, 0.0);
}

TEST(Pool, ConcreteCostEquals7PiTimes1000) {
  PoolCostResult r = solvePool();
  double expected = 7 * M_PI * 1000.0;
  EXPECT_NEAR(r.concreteCost, expected, 0.01);
}

TEST(Pool, FenceCostEquals8PiTimes2000) {
  PoolCostResult r = solvePool();
  double expected = 8 * M_PI * 2000.0;
  EXPECT_NEAR(r.fenceCost, expected, 0.01);
}
