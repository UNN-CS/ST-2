// Copyright 2025 UNN-CS Team
#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double EPSILON = 1e-10;

TEST(CircleTest, Constructor) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(5.0, c.getRadius());
  EXPECT_DOUBLE_EQ(2 * M_PI * 5.0, c.getCircumference());
  EXPECT_DOUBLE_EQ(M_PI * 25.0, c.getArea());
}

TEST(CircleTest, SetRadius) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_DOUBLE_EQ(3.0, c.getRadius());
  EXPECT_DOUBLE_EQ(2 * M_PI * 3.0, c.getCircumference());
  EXPECT_DOUBLE_EQ(M_PI * 9.0, c.getArea());
}

TEST(CircleTest, SetCircumference) {
  Circle c(1.0);
  double newCircumference = 10.0;
  c.setCircumference(newCircumference);
  EXPECT_DOUBLE_EQ(newCircumference / (2 * M_PI), c.getRadius());
  EXPECT_DOUBLE_EQ(newCircumference, c.getCircumference());
}

TEST(CircleTest, SetArea) {
  Circle c(1.0);
  double newArea = 100.0;
  c.setArea(newArea);
  EXPECT_DOUBLE_EQ(std::sqrt(newArea / M_PI), c.getRadius());
  EXPECT_DOUBLE_EQ(newArea, c.getArea());
}

TEST(CircleTest, ZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
  EXPECT_DOUBLE_EQ(0.0, c.getCircumference());
  EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(RopeTest, EarthRopeGap) {
  double gap = calculateRopeGap(6378.1, 1.0);
  EXPECT_NEAR(gap, 0.159, 0.001);
}

TEST(RopeTest, SmallRadius) {
  double gap = calculateRopeGap(1.0, 1.0);
  EXPECT_GT(gap, 0.0);
}

TEST(RopeTest, LargeAddedLength) {
  double gap = calculateRopeGap(6378.1, 1000.0);
  EXPECT_GT(gap, 159.0);
}

TEST(PoolTest, BasicCalculation) {
  PoolResults results = calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0);
  Circle innerPool(3.0);
  Circle outerPool(4.0);
  double expectedPathwayArea = outerPool.getArea() - innerPool.getArea();
  double expectedFenceLength = outerPool.getCircumference();

  EXPECT_DOUBLE_EQ(results.pathwayCost, expectedPathwayArea * 1000.0);
  EXPECT_DOUBLE_EQ(results.fenceCost, expectedFenceLength * 2000.0);
  EXPECT_DOUBLE_EQ(results.totalCost, results.pathwayCost + results.fenceCost);
}

TEST(PoolTest, ZeroPathwayWidth) {
  PoolResults results = calculatePoolCosts(3.0, 0.0, 1000.0, 2000.0);
  EXPECT_DOUBLE_EQ(results.pathwayCost, 0.0);
  Circle pool(3.0);
  EXPECT_DOUBLE_EQ(results.fenceCost, pool.getCircumference() * 2000.0);
}

TEST(PoolTest, SmallPool) {
  PoolResults results = calculatePoolCosts(1.0, 0.5, 1000.0, 2000.0);
  EXPECT_GT(results.totalCost, 0.0);
}

TEST(PoolTest, LargePool) {
  PoolResults results = calculatePoolCosts(10.0, 2.0, 1000.0, 2000.0);
  EXPECT_GT(results.totalCost, 0.0);
}

TEST(PoolTest, ExpensiveMaterials) {
  PoolResults results = calculatePoolCosts(3.0, 1.0, 5000.0, 10000.0);
  PoolResults baseResults = calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0);
  EXPECT_DOUBLE_EQ(results.pathwayCost, baseResults.pathwayCost * 5.0);
  EXPECT_DOUBLE_EQ(results.fenceCost, baseResults.fenceCost * 5.0);
}

TEST(CircleTest, NegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, LargeRadius) {
  double largeRadius = 1e6;
  Circle c(largeRadius);
  EXPECT_DOUBLE_EQ(largeRadius, c.getRadius());
  EXPECT_DOUBLE_EQ(2 * M_PI * largeRadius, c.getCircumference());
  EXPECT_DOUBLE_EQ(M_PI * largeRadius * largeRadius, c.getArea());
}

TEST(CircleTest, SmallRadius) {
  double smallRadius = 1e-6;
  Circle c(smallRadius);
  EXPECT_DOUBLE_EQ(smallRadius, c.getRadius());
  EXPECT_DOUBLE_EQ(2 * M_PI * smallRadius, c.getCircumference());
  EXPECT_DOUBLE_EQ(M_PI * smallRadius * smallRadius, c.getArea());
}

TEST(RopeTest, ZeroAddedLength) {
  double gap = calculateRopeGap(6378.1, 0.0);
  EXPECT_NEAR(gap, 0.0, EPSILON);
}

TEST(PoolTest, HighPrecisionCalculation) {
  PoolResults results = calculatePoolCosts(3.14159, 1.41421, 1000.0, 2000.0);
  EXPECT_GT(results.totalCost, 0.0);
}

TEST(CircleTest, VeryLargeRadius) {
  double veryLargeRadius = 1e12;
  Circle c(veryLargeRadius);
  EXPECT_DOUBLE_EQ(veryLargeRadius, c.getRadius());
  EXPECT_DOUBLE_EQ(2 * M_PI * veryLargeRadius, c.getCircumference());
  EXPECT_DOUBLE_EQ(M_PI * veryLargeRadius * veryLargeRadius, c.getArea());
}

TEST(CircleTest, VerySmallRadius) {
  double verySmallRadius = 1e-12;
  Circle c(verySmallRadius);
  EXPECT_DOUBLE_EQ(verySmallRadius, c.getRadius());
  EXPECT_DOUBLE_EQ(2 * M_PI * verySmallRadius, c.getCircumference());
  EXPECT_DOUBLE_EQ(M_PI * verySmallRadius * verySmallRadius, c.getArea());
}

TEST(CircleTest, SetNegativeArea) {
  Circle c(1.0);
  EXPECT_THROW(c.setArea(-100.0), std::invalid_argument);
}

TEST(CircleTest, SetNegativeCircumference) {
  Circle c(1.0);
  EXPECT_THROW(c.setCircumference(-10.0), std::invalid_argument);
}

TEST(RopeTest, NegativeEarthRadius) {
  EXPECT_THROW(calculateRopeGap(-6378.1, 1.0), std::invalid_argument);
}

TEST(RopeTest, NegativeAddedLength) {
  EXPECT_THROW(calculateRopeGap(6378.1, -1.0), std::invalid_argument);
}

TEST(RopeTest, VerySmallAddedLength) {
  double gap = calculateRopeGap(6378.1, 0.001);
  EXPECT_NEAR(gap, 0.000159, 0.000001);
}

TEST(PoolTest, NegativePoolRadius) {
  EXPECT_THROW(calculatePoolCosts(-3.0, 1.0, 1000.0, 2000.0),
               std::invalid_argument);
}

TEST(PoolTest, NegativePathwayWidth) {
  EXPECT_THROW(calculatePoolCosts(3.0, -1.0, 1000.0, 2000.0),
               std::invalid_argument);
}

TEST(PoolTest, ZeroCosts) {
  PoolResults results = calculatePoolCosts(3.0, 1.0, 0.0, 0.0);
  EXPECT_DOUBLE_EQ(results.pathwayCost, 0.0);
  EXPECT_DOUBLE_EQ(results.fenceCost, 0.0);
  EXPECT_DOUBLE_EQ(results.totalCost, 0.0);
}

TEST(PoolTest, VeryExpensiveMaterials) {
  PoolResults results = calculatePoolCosts(3.0, 1.0, 1e6, 1e6);
  EXPECT_GT(results.pathwayCost, 0.0);
  EXPECT_GT(results.fenceCost, 0.0);
  EXPECT_GT(results.totalCost, 0.0);
}

TEST(PoolTest, VeryLargePool) {
  PoolResults results = calculatePoolCosts(1000.0, 10.0, 1000.0, 2000.0);
  EXPECT_GT(results.pathwayCost, 0.0);
  EXPECT_GT(results.fenceCost, 0.0);
  EXPECT_GT(results.totalCost, 0.0);
}

TEST(CircleTest, AreaFerenceRelation) {
  Circle c(10.0);
  double ratio = c.getArea() / (c.getCircumference() * c.getCircumference());
  EXPECT_NEAR(ratio, 1.0 / (4.0 * M_PI), EPSILON);
}

TEST(CircleTest, RadiusAreaRelation) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * c.getRadius() * c.getRadius());
}
