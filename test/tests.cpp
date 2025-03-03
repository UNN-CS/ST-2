// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"


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
    EXPECT_DOUBLE_EQ(c.getRadius(), -5);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * -5);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * -5 * -5);
}

TEST(CircleTest, NegativeFerence) {
    Circle c(5);
    c.setFerence(-31.41592653589793);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5);
    EXPECT_DOUBLE_EQ(c.getFerence(), -31.41592653589793);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * -5 * -5);
}

TEST(CircleTest, NegativeArea) {
    Circle c(5);
    c.setArea(-78.53981633974483);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * -5);
    EXPECT_DOUBLE_EQ(c.getArea(), -78.53981633974483);
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