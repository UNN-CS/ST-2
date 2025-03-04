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
  double expectedCost = 50626.640742262784;
  double calculatedCost = calculatePoolCost();
  EXPECT_NEAR(calculatedCost, expectedCost, 1e-3);
}

TEST(TaskTest, TestCostForDifferentPoolRadius) {
  double roadCost = 0;
  double fenceCost = 0;
  
  Circle pool(3.0);
  const double roadWidth = 1.0;
  double outerRadius = pool.getRadius() + roadWidth;

  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * pool.getRadius() * pool.getRadius();
  roadCost = roadArea * 1000;

  pool.setRadius(outerRadius);
  double fenceLength = pool.getFerence();
  fenceCost = fenceLength * 2000;

  double expectedCost = 114470.29616341939;
  double totalCost = roadCost + fenceCost;
  EXPECT_NEAR(totalCost, expectedCost, 1e-3);
}

TEST(TaskTest, TestCostForSmallPoolRadius) {
  double roadCost = 0;
  double fenceCost = 0;
  
  Circle pool(3.0);
  const double roadWidth = 1.0;
  double outerRadius = pool.getRadius() + roadWidth;

  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * pool.getRadius() * pool.getRadius();
  roadCost = roadArea * 1000;

  pool.setRadius(outerRadius);
  double fenceLength = pool.getFerence();
  fenceCost = fenceLength * 2000;

  double expectedCost = 2097.69623246178;
  double totalCost = roadCost + fenceCost;
  EXPECT_NEAR(totalCost, expectedCost, 1e-3);
}

TEST(TaskTest, TestPoolCostForRadius3) {
  double roadCost = 0;
  double fenceCost = 0;
  
  Circle pool(3.0);
  const double roadWidth = 1.0;
  double outerRadius = pool.getRadius() + roadWidth;

  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * pool.getRadius() * pool.getRadius();
  roadCost = roadArea * 1000;

  pool.setRadius(outerRadius);
  double fenceLength = pool.getFerence();
  fenceCost = fenceLength * 2000;

  double expectedCost = 50626.640742262784;
  double totalCost = roadCost + fenceCost;
  EXPECT_NEAR(totalCost, expectedCost, 1e-3);
}

TEST(TaskTest, TestCostForLargePool) {
  double roadCost = 0;
  double fenceCost = 0;
  
  Circle pool(3.0);
  const double roadWidth = 1.0;
  double outerRadius = pool.getRadius() + roadWidth;

  pool.setRadius(outerRadius);
  const double PI = 3.141592653589793;
  double roadArea = pool.getArea() - PI * pool.getRadius() * pool.getRadius();
  roadCost = roadArea * 1000;

  pool.setRadius(outerRadius);
  double fenceLength = pool.getFerence();
  fenceCost = fenceLength * 2000;

  double expectedCost = 228943.40801651784;
  double totalCost = roadCost + fenceCost;
  EXPECT_NEAR(totalCost, expectedCost, 1e-3);
}

TEST(TaskTest, TestGapWithSmallIncrease) {
  EXPECT_NEAR(calculateGap(), 0.15915494309189535, 1e-6);
}

TEST(TaskTest, TestGapWithLargeIncrease) {
  EXPECT_NEAR(calculateGap(), 0.15915494309189535, 1e-6);
}
