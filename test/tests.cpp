// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

TEST(CircleTest, ConstructorAndGetters) {
    Circle c(5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 5 * 5);
}

TEST(CircleTest, SetRadius) {
    Circle c(5);
    c.setRadius(10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 10);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 10 * 10);
}

TEST(CircleTest, SetFerence) {
    Circle c(5);
    c.setFerence(31.41592653589793);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5);
    EXPECT_DOUBLE_EQ(c.getFerence(), 31.41592653589793);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 5 * 5);
}

TEST(CircleTest, SetArea) {
    Circle c(5);
    c.setArea(78.53981633974483);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5);
    EXPECT_DOUBLE_EQ(c.getArea(), 78.53981633974483);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e6 * 1e6);
}

TEST(CircleTest, ZeroFerence) {
    Circle c(5);
    c.setFerence(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, ZeroArea) {
    Circle c(5);
    c.setArea(0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(RopeTaskTest, CalculateGap) {
    double gap = calculateGap();
    EXPECT_GT(gap, 0);
    EXPECT_LT(gap, 1);
}

TEST(PoolTaskTest, CalculatePoolCost) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, ZeroPathWidth) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, LargePathWidth) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, LargePoolRadius) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0);
}

TEST(CircleTest, NegativeFerence) {
    Circle c(5);
    c.setFerence(-31.41592653589793);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0);
}

TEST(CircleTest, NegativeArea) {
    Circle c(5);
    c.setArea(-78.53981633974483);
    EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(PoolTaskTest, ZeroPoolRadius) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, NegativePoolRadius) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, ZeroMaterialCost) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, NegativeMaterialCost) {
    double cost = calculatePoolCost();
    EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, CorrectPoolCostCalculation) {
    double poolRadius = 3;
    double pathWidth = 1;
    double concreteCostPerSquareMeter = 1000;
    double fenceCostPerMeter = 2000;
    double outerRadius = poolRadius + pathWidth;
    double expectedPathArea = M_PI * (outerRadius * outerRadius - poolRadius * poolRadius);
    double expectedFenceLength = 2 * M_PI * outerRadius;
    double expectedConcreteCost = expectedPathArea * concreteCostPerSquareMeter;
    double expectedFenceCost = expectedFenceLength * fenceCostPerMeter;
    double expectedTotalCost = expectedConcreteCost + expectedFenceCost;
    double actualCost = calculatePoolCost();
    EXPECT_NEAR(actualCost, expectedTotalCost, 1e-2);
}

TEST(PoolTaskTest, PoolCostWithDifferentParameters) {
    double poolRadius = 5;
    double pathWidth = 2;
    double concreteCostPerSquareMeter = 500;
    double fenceCostPerMeter = 1500;
    double outerRadius = poolRadius + pathWidth;
    double expectedPathArea = M_PI * (outerRadius * outerRadius - poolRadius * poolRadius);
    double expectedFenceLength = 2 * M_PI * outerRadius;
    double expectedConcreteCost = expectedPathArea * concreteCostPerSquareMeter;
    double expectedFenceCost = expectedFenceLength * fenceCostPerMeter;
    double expectedTotalCost = expectedConcreteCost + expectedFenceCost;
    double actualCost = calculatePoolCost(poolRadius, pathWidth, concreteCostPerSquareMeter, fenceCostPerMeter);
    EXPECT_NEAR(actualCost, expectedTotalCost, 1e-2);
}
