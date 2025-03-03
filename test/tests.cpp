#include <gtest/gtest.h>
#include <cmath>
#include <cstdint>
#include <limits>

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
}

TEST(korablev_v_circle_test, SetFerence) {
  Circle c(1.0);
  c.setFerence(10.0);
  double r = 10.0 / (2.0 * pi);
  EXPECT_NEAR(c.getRadius(), r, 1e-7);
}

TEST(korablev_v_circle_test, SetArea) {
  Circle c(2.0);
  c.setArea(25.0);
  double r = std::sqrt(25.0 / pi);
  EXPECT_NEAR(c.getRadius(), r, 1e-7);
}

TEST(korablev_v_circle_test, ZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}

TEST(korablev_v_circle_test, NegativeRadius) {
  Circle c(-1.0);
  EXPECT_NEAR(c.getRadius(), -1.0, 1e-7);
}

TEST(korablev_v_circle_test, NaNRadius) {
  Circle c(std::nan(""));
  EXPECT_TRUE(std::isnan(c.getRadius()));
}

TEST(korablev_v_circle_test, InfinityRadius) {
  Circle c(std::numeric_limits<double>::infinity());
  EXPECT_TRUE(std::isinf(c.getRadius()));
}

TEST(korablev_v_circle_test, TinyRadius) {
  Circle c(1e-12);
  EXPECT_NEAR(c.getRadius(), 1e-12, 1e-20);
}

TEST(korablev_v_circle_test, HugeRadius) {
  Circle c(1e12);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1e12);
}

TEST(korablev_v_circle_test, MultipleSetRadius) {
  Circle c(1.0);
  c.setRadius(2.0);
  c.setRadius(4.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
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

TEST(korablev_v_tasks_test, PoolCostPositive) {
  double cost = poolCost();
  EXPECT_GT(cost, 0.0);
}

TEST(korablev_v_tasks_test, PoolCostTheoretical) {
  double cost = poolCost();
  double expected = 23.0 * pi * 1000.0;
  EXPECT_NEAR(cost, expected, 1e-7);
}

TEST(korablev_v_tasks_test, PoolCostDifferentPool) {
  Circle poolWithPath(7.0);
  Circle pool(5.5);
  EXPECT_GT(poolWithPath.getArea(), pool.getArea());
}

TEST(korablev_v_tasks_test, LargePoolCost) {
  Circle poolWithPath(50.0);
  Circle pool(45.0);
  EXPECT_GT(poolWithPath.getArea(), pool.getArea());
}

TEST(korablev_v_tasks_test, SmallPoolCost) {
  Circle poolWithPath(1.5);
  Circle pool(1.0);
  EXPECT_GT(poolWithPath.getArea(), pool.getArea());
}

TEST(korablev_v_circle_test, CheckFerenceCalculation) {
  Circle c(5.0);
  EXPECT_NEAR(c.getFerence(), 10.0 * pi, 1e-7);
}

TEST(korablev_v_circle_test, CheckAreaCalculation) {
  Circle c(5.0);
  EXPECT_NEAR(c.getArea(), 25.0 * pi, 1e-7);
}

TEST(korablev_v_circle_test, CheckCircumferenceAfterSet) {
  Circle c(5.0);
  c.setRadius(7.0);
  EXPECT_NEAR(c.getFerence(), 14.0 * pi, 1e-7);
}

TEST(korablev_v_circle_test, CheckAreaAfterSet) {
  Circle c(5.0);
  c.setRadius(7.0);
  EXPECT_NEAR(c.getArea(), 49.0 * pi, 1e-7);
}

TEST(korablev_v_tasks_test, RopeTaskWithLargerIncrease) {
  Circle earth(6378.1 * 1000.0);
  double oldFerence = earth.getFerence();
  earth.setFerence(oldFerence + 1000.0);
  double gap = earth.getRadius() - 6378.1 * 1000.0;
  EXPECT_NEAR(gap, 1000.0 / (2.0 * pi), 1e-7);
}
