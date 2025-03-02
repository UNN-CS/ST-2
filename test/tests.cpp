// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"
#include <cmath>
#include <stdexcept>

const double PI = 3.14159265358979323846;

TEST(CircleTest, PositiveRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 5.0 * 5.0);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, NegativeRadiusThrowsException) {
    EXPECT_THROW(Circle(-5.0), std::invalid_argument);
}
TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 7.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 7.0 * 7.0);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    c.setFerence(2 * PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 3.0 * 3.0);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    c.setArea(PI * 4.0 * 4.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 4.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 4.0 * 4.0);
}

TEST(CircleTest, ZeroArea) {
    Circle c(1.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetNegativeAreaThrowsException) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-5.0), std::invalid_argument);
}

TEST(CircleTest, SetNegativeFerenceThrowsException) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-5.0), std::invalid_argument);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1000.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1000.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 1000.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 1000.0 * 1000.0);
}

TEST(CircleTest, SmallRadius) {
    Circle c(0.001);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.001);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 0.001);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 0.001 * 0.001);
}

TEST(GapTest, EarthAndRope) {
    double gap = calculateGap(6378100, 1);
    ASSERT_NEAR(gap, 1.59154943e-7, 1e-13);
}

TEST(PoolCostTest, BasicPool) {
    double totalCost = calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0);
    ASSERT_NEAR(totalCost, 50265.48, 0.1);
}

TEST(PoolCostTest, ZeroWidthPath) {
    double totalCost = calculatePoolCosts(5.0, 0.0, 1000.0, 2000.0);
    ASSERT_NEAR(totalCost, 62831.85, 0.1);
}

TEST(PoolCostTest, ZeroPoolRadius) {
    double total_cost = calculatePoolCosts(0.0, 1.0, 1000.0, 2000.0);
    ASSERT_NEAR(total_cost, 18849.55, 0.1);
}

TEST(PoolCostTest, HighCosts) {
    double totalCost = calculatePoolCosts(2.0, 0.5, 5000.0, 10000.0);
    ASSERT_NEAR(totalCost, 188495.55, 0.1);
}

TEST(GapTest, SmallEarthRadius) {
    double gap = calculateGap(1.0, 0.1);
    ASSERT_NEAR(gap, 0.015915494309189535, 1e-12);
}

TEST(PoolCostTest, PoolRadiusEqualsPathWidth) {
    double totalCost = calculatePoolCosts(1.0, 1.0, 1000.0, 2000.0);
    ASSERT_NEAR(totalCost, 25132.74, 0.1);
}

TEST(PoolCostTest, NoPathWidth) {
    double total_cost = calculatePoolCosts(5.0, 0.0, 1000.0, 2000.0);
    ASSERT_NEAR(total_cost, 62831.85, 0.01);
}

TEST(GapTest, ZeroAddedLength) {
    double gap = calculateGap(5.0, 0.0);
    ASSERT_NEAR(gap, 0, 0.01);
}
