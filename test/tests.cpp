// Copyright 2025 Vladlen Korablev
#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

static const double pi = std::acos(-1.0);

TEST(korablev_v_circle_test, Constructor) {
  Circle c(2.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
  EXPECT_NEAR(c.getFerence(), 4.0 * pi, 1e-7);
  EXPECT_NEAR(c.getArea(), 4.0 * pi, 1e-7);
}
TEST(korablev_v_circle_test, SetRadius) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
  EXPECT_NEAR(c.getFerence(), 6.0 * pi, 1e-7);
  EXPECT_NEAR(c.getArea(), 9.0 * pi, 1e-7);
}
TEST(korablev_v_circle_test, SetFerence) {
  Circle c(1.0);
  c.setFerence(10.0);
  double r = 10.0 / (2.0 * pi);
  double a = pi * r * r;
  EXPECT_NEAR(c.getRadius(), r, 1e-7);
  EXPECT_NEAR(c.getArea(), a, 1e-7);
}
TEST(korablev_v_circle_test, SetArea) {
  Circle c(2.0);
  c.setArea(25.0);
  double r = std::sqrt(25.0 / pi);
  double f = 2.0 * pi * r;
  EXPECT_NEAR(c.getRadius(), r, 1e-7);
  EXPECT_NEAR(c.getFerence(), f, 1e-7);
  EXPECT_NEAR(c.getArea(), 25.0, 1e-7);
}
TEST(korablev_v_circle_test, ZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}
TEST(korablev_v_circle_test, NegativeRadius) {
  Circle c(-1.0);
  EXPECT_NEAR(c.getRadius(), -1.0, 1e-7);
  EXPECT_NEAR(c.getFerence(), -2.0 * pi, 1e-7);
  EXPECT_NEAR(c.getArea(), pi, 1e-7);
}
TEST(korablev_v_circle_test, MultipleSetters) {
  Circle c(1.0);
  c.setRadius(2.0);
  c.setFerence(6.0 * pi);
  c.setArea(36.0 * pi);
  EXPECT_NEAR(c.getRadius(), 6.0, 1e-7);
  EXPECT_NEAR(c.getFerence(), 12.0 * pi, 1e-7);
  EXPECT_NEAR(c.getArea(), 36.0 * pi, 1e-7);
}
TEST(korablev_v_circle_test, LargeRadius) {
  Circle c(1e6);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
  EXPECT_NEAR(c.getFerence(), 2.0 * pi * 1e6, 1e-5);
  EXPECT_NEAR(c.getArea(), pi * 1e12, 1e4);
}
TEST(korablev_v_tasks_test, RopeTaskPositive) {
  double gap = ropeTask();
  EXPECT_GT(gap, 0.0);
}

TEST(korablev_v_tasks_test, RopeTaskTheoretical) {
  double gap = ropeTask();
  double expected = 1.0 / (2.0 * pi);
  EXPECT_NEAR(gap, expected, 1e-7);
}

TEST(korablev_v_tasks_test, RopeTaskApprox) {
  double gap = ropeTask();
  EXPECT_NEAR(gap, 0.15915, 1e-5);
}

TEST(korablev_v_tasks_test, PoolCostPositive) {
  double cost = poolCost();
  EXPECT_GT(cost, 0.0);
}

TEST(korablev_v_tasks_test, PoolCostTheoretical) {
  double cost = poolCost();
  double expected = 23.0 * pi * 1000.0;
  EXPECT_NEAR(cost, expected, 1e-7);
}

TEST(korablev_v_tasks_test, PoolCostApprox) {
  double cost = poolCost();
  EXPECT_NEAR(cost, 72382.4, 1e-1);
}
