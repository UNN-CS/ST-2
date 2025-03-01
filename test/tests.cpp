// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "tasks.h"
#include "circle.h"

TEST(CircleTest, TestConstructor) {
  Circle c(5);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 3.141592653589793 * 5);
  EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * 5 * 5);
}

TEST(CircleTest, TestSetRadius) {
  Circle c(5);
  c.setRadius(10);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 3.141592653589793 * 10);
  EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * 10 * 10);
}

TEST(CircleTest, TestSetFerence) {
  Circle c(5);
  c.setFerence(31.41592653589793);
  EXPECT_DOUBLE_EQ(c.getFerence(), 31.41592653589793);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5);
  EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * 5 * 5);
}

TEST(CircleTest, TestSetArea) {
  Circle c(5);
  c.setArea(78.53981633974483);
  EXPECT_DOUBLE_EQ(c.getArea(), 78.53981633974483);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 3.141592653589793 * 5);
}

TEST(CircleTest, TestZeroRadius) {
  Circle c(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, TestNegativeRadius) {
  Circle c(-5);
  EXPECT_DOUBLE_EQ(c.getRadius(), -5);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 3.141592653589793 * -5);
  EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * -5 * -5);
}

TEST(CircleTest, TestSetNegativeFerence) {
  Circle c(5);
  c.setFerence(-31.41592653589793);
  EXPECT_DOUBLE_EQ(c.getFerence(), -31.41592653589793);
  EXPECT_DOUBLE_EQ(c.getRadius(), -5);
  EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * -5 * -5);
}

TEST(CircleTest, TestFerenceToRadius) {
  Circle c(10);
  c.setFerence(62.83185307179586);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10);
  EXPECT_DOUBLE_EQ(c.getFerence(), 62.83185307179586);
  EXPECT_DOUBLE_EQ(c.getArea(), 3.141592653589793 * 10 * 10);
}

TEST(CircleTest, TestAreaToRadius) {
  Circle c(10);
  c.setArea(314.1592653589793);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10);
  EXPECT_DOUBLE_EQ(c.getArea(), 314.1592653589793);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * 3.141592653589793 * 10);
}

TEST(CircleTest, TestSetFerenceAndCalculateArea) {
  Circle c(5);
  c.setFerence(31.41592653589793);
  EXPECT_DOUBLE_EQ(c.getArea(), 78.53981633974483);
}

TEST(CircleTest, TestSetAreaAndCalculateFerence) {
  Circle c(5);
  c.setArea(78.53981633974483);
  EXPECT_DOUBLE_EQ(c.getFerence(), 31.41592653589793);
}

TEST(TaskTest, TestCalculateGapForEarth) {
  EXPECT_NEAR(calculateGap(), 0.15915494309189535, 1e-6);
}

TEST(TaskTest, TestCalculateGapForLargeEarth) {
  Circle earth(6378.1 * 1000);
  earth.setFerence(2 * 3.141592653589793 * (6378.1 * 1000) + 1);
  double newRadius = earth.getRadius();
  double gap = newRadius - 6378.1 * 1000;
  EXPECT_NEAR(gap, 0.15915494309189535, 1e-9);
}

TEST(TaskTest, TestCalculatePoolCost) {
  EXPECT_NEAR(calculatePoolCost(), 50626.640742262784, 1e-6);
}

TEST(TaskTest, TestCostForDifferentPoolRadius) {
  const double poolRadius = 5.0;
  Circle pool(poolRadius);
  double outerRadius = poolRadius + 1.0;
  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * poolRadius * poolRadius;
  double roadCost = roadArea * 1000;
  double fenceLength = pool.getFerence();
  double fenceCost = fenceLength * 2000;
  EXPECT_NEAR(roadCost + fenceCost, 114470.29616341939, 1e-6);
}

TEST(TaskTest, TestCostForSmallPoolRadius) {
  const double poolRadius = 1.0;
  Circle pool(poolRadius);
  double outerRadius = poolRadius + 1.0;
  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * poolRadius * poolRadius;
  double roadCost = roadArea * 1000;
  double fenceLength = pool.getFerence();
  double fenceCost = fenceLength * 2000;
  EXPECT_NEAR(roadCost + fenceCost, 2097.69623246178, 1e-6);
}

TEST(TaskTest, TestPoolCostForRadius3) {
  const double poolRadius = 3.0;
  Circle pool(poolRadius);
  double outerRadius = poolRadius + 1.0;
  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * poolRadius * poolRadius;
  double roadCost = roadArea * 1000;
  double fenceLength = pool.getFerence();
  double fenceCost = fenceLength * 2000;
  EXPECT_NEAR(roadCost + fenceCost, 50626.640742262784, 1e-6);
}

TEST(TaskTest, TestCostForLargePool) {
  const double poolRadius = 10.0;
  Circle pool(poolRadius);
  double outerRadius = poolRadius + 2.0;
  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * poolRadius * poolRadius;
  double roadCost = roadArea * 1000;
  double fenceLength = pool.getFerence();
  double fenceCost = fenceLength * 2000;
  EXPECT_NEAR(roadCost + fenceCost, 228943.40801651784, 1e-6);
}

TEST(TaskTest, TestGapWithSmallIncrease) {
  EXPECT_NEAR(calculateGap(), 0.15915494309189535, 1e-6);
}

TEST(TaskTest, TestGapWithLargeIncrease) {
  EXPECT_NEAR(calculateGap(), 0.15915494309189535, 1e-6);
}
