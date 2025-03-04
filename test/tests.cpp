// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "tasks.h"
#include "circle.h"

TEST(circle, ctor) {
  Circle c(5);
  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, setRadius) {
  Circle c(1);
  c.setRadius(5);
  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, setFerence) {
  Circle c(1);
  c.setFerence(31.415926);
  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, setArea) {
  Circle c(1);
  c.setArea(78.539818);
  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, ctor2) {
  Circle c(33.33);
  EXPECT_FLOAT_EQ(c.getRadius(), 33.33);
  EXPECT_FLOAT_EQ(c.getFerence(), 209.418566);
  EXPECT_FLOAT_EQ(c.getArea(), 3489.960407);
}

TEST(circle, setRadius2) {
  Circle c(1);
  c.setRadius(33.33);
  EXPECT_FLOAT_EQ(c.getRadius(), 33.33);
  EXPECT_FLOAT_EQ(c.getFerence(), 209.418566);
  EXPECT_FLOAT_EQ(c.getArea(), 3489.960407);
}

TEST(circle, setFerence2) {
  Circle c(1);
  c.setFerence(209.418566);
  EXPECT_FLOAT_EQ(c.getRadius(), 33.33);
  EXPECT_FLOAT_EQ(c.getFerence(), 209.418566);
  EXPECT_FLOAT_EQ(c.getArea(), 3489.960407);
}

TEST(circle, setArea2) {
  Circle c(1);
  c.setArea(3489.960407);
  EXPECT_FLOAT_EQ(c.getRadius(), 33.33);
  EXPECT_FLOAT_EQ(c.getFerence(), 209.418566);
  EXPECT_FLOAT_EQ(c.getArea(), 3489.960407);
}

TEST(circle, negative_radius) {
  Circle c(-5);
  EXPECT_FLOAT_EQ(c.getRadius(), -5);
  EXPECT_FLOAT_EQ(c.getFerence(), -31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, zero_radius) {
  Circle c(0);
  EXPECT_FLOAT_EQ(c.getRadius(), 0);
  EXPECT_FLOAT_EQ(c.getFerence(), 0);
  EXPECT_FLOAT_EQ(c.getArea(), 0);
}

TEST(circle, chain_setters) {
  Circle c(5);
  c.setArea(78.539818);
  c.setRadius(5);
  c.setFerence(31.415926);
  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, multiple_updates) {
  Circle c(10);
  c.setRadius(20);
  EXPECT_FLOAT_EQ(c.getRadius(), 20);
  c.setArea(314.159265);
  EXPECT_FLOAT_EQ(c.getRadius(), 10);
}

TEST(circle, area_consistency) {
  Circle c(7);
  float expected = 3.141592653589793f * 7 * 7;
  EXPECT_FLOAT_EQ(c.getArea(), expected);
}

TEST(task1, gives_correct_answer) {
  EXPECT_FLOAT_EQ(calculateGap(), 0.15915494);
}

TEST(task1, consistent_gap) {
  float g1 = calculateGap();
  float g2 = calculateGap();
  EXPECT_FLOAT_EQ(g1, g2);
}

TEST(task2, gives_correct_answer) {
  EXPECT_FLOAT_EQ(calculatePoolCost(), 72256.633);
}

TEST(task2, pool_cost_manual_vs_function) {
  double poolRadius = 3.0;
  double roadWidth = 1.0;
  Circle pool(poolRadius);
  double outerRadius = poolRadius + roadWidth;
  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * poolRadius * poolRadius;
  double roadCost = roadArea * 1000;
  pool.setRadius(outerRadius);
  double fenceLength = pool.getFerence();
  double fenceCost = fenceLength * 2000;
  double manualCost = roadCost + fenceCost;
  EXPECT_FLOAT_EQ(manualCost, calculatePoolCost());
}

TEST(task2, pool_cost_value_precision) {
  EXPECT_FLOAT_EQ(calculatePoolCost(), 72256.633);
}

TEST(TaskTest, TestGapWithSmallIncrease) {
  EXPECT_NEAR(calculateGap(), 0.15915494309189535, 1e-6);
}

TEST(TaskTest, TestGapWithLargeIncrease) {
  EXPECT_NEAR(calculateGap(), 0.15915494309189535, 1e-6);
}
