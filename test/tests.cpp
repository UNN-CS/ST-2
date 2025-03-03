// Copyright 2025

#include <gtest/gtest.h>

#include "circle.h"
#include "tasks.h"

TEST(CircleTest, ConstructorPositiveRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, 1e-6);
    EXPECT_NEAR(c.getArea(), PI * 25.0, 1e-6);
}

TEST(CircleTest, ConstructorZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-6);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-6);
}

TEST(CircleTest, ConstructorNegativeRadius) {
    Circle c(-5.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-6);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-6);
}

TEST(CircleTest, SetRadiusPositive) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 10.0, 1e-6);
    EXPECT_NEAR(c.getArea(), PI * 100.0, 1e-6);
}

TEST(CircleTest, SetRadiusNegative) {
    Circle c(5.0);
    c.setRadius(-1.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-6);
}

TEST(CircleTest, SetFerencePositive) {
    Circle c(1.0);
    c.setFerence(2 * PI * 2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 2.0, 1e-6);
    EXPECT_NEAR(c.getArea(), PI * 4.0, 1e-6);
}

TEST(CircleTest, SetFerenceNegative) {
    Circle c(5.0);
    c.setFerence(-10.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-6);
}

TEST(CircleTest, SetAreaPositive) {
    Circle c(1.0);
    c.setArea(PI * 25.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, 1e-6);
    EXPECT_NEAR(c.getArea(), PI * 25.0, 1e-6);
}

TEST(EarthAndRopeTest, DefaultValues) {
    double gap = earthAndRope();
    EXPECT_NEAR(gap, 1.0 / (2 * PI), 1e-6);
}

TEST(EarthAndRopeTest, ExplicitDefaultValues) {
    double gap = earthAndRope(6378.1, 1.0);
    EXPECT_NEAR(gap, 1.0 / (2 * PI), 1e-6);
}

TEST(EarthAndRopeTest, SmallRadius) {
    double gap = earthAndRope(1.0, 1.0);
    EXPECT_NEAR(gap, 1.0 / (2 * PI), 1e-6);
}

TEST(EarthAndRopeTest, ZeroRadius) {
    double gap = earthAndRope(0.0, 1.0);
    EXPECT_NEAR(gap, 1.0 / (2 * PI), 1e-6);
}

TEST(EarthAndRopeTest, LargeAddedLength) {
    double gap = earthAndRope(6378.1, 1000.0);
    EXPECT_NEAR(gap, 1000.0 / (2 * PI), 1e-6);
}

TEST(EarthAndRopeTest, ZeroAddedLength) {
    double gap = earthAndRope(6378.1, 0.0);
    EXPECT_NEAR(gap, 0.0, 1e-6);
}

TEST(EarthAndRopeTest, SmallAddedLength) {
    double gap = earthAndRope(6378.1, 0.01);
    EXPECT_NEAR(gap, 0.01 / (2 * PI), 1e-6);
}

TEST(EarthAndRopeTest, LargeRadius) {
    double gap = earthAndRope(10000.0, 1.0);
    EXPECT_NEAR(gap, 1.0 / (2 * PI), 1e-6);
}

TEST(PoolTest, DefaultValues) {
    double totalCost = pool();
    double expectedCost = (PI * 16 - PI * 9) * 1000 + (2 * PI * 4) * 2000;
    EXPECT_NEAR(totalCost, expectedCost, 1e-6);
}

TEST(PoolTest, ExplicitDefaultValues) {
    double totalCost = pool(3.0, 1.0, 1000.0, 2000.0);
    double expectedCost = (PI * 16 - PI * 9) * 1000 + (2 * PI * 4) * 2000;
    EXPECT_NEAR(totalCost, expectedCost, 1e-6);
}

TEST(PoolTest, LargerRadius) {
    double totalCost = pool(5.0, 1.0, 1000.0, 2000.0);
    double pathArea = PI * 36 - PI * 25;
    double fenceLength = 2 * PI * 6;
    double expectedCost = pathArea * 1000 + fenceLength * 2000;
    EXPECT_NEAR(totalCost, expectedCost, 1e-6);
}

TEST(PoolTest, ZeroPathWidth) {
    double totalCost = pool(3.0, 0.0, 1000.0, 2000.0);
    double fenceLength = 2 * PI * 3;
    double expectedCost = 0 + fenceLength * 2000;
    EXPECT_NEAR(totalCost, expectedCost, 1e-6);
}

TEST(PoolTest, DoubleCosts) {
    double totalCost = pool(3.0, 1.0, 2000.0, 4000.0);
    double expectedCost = (PI * 16 - PI * 9) * 2000 + (2 * PI * 4) * 4000;
    EXPECT_NEAR(totalCost, expectedCost, 1e-6);
}

TEST(PoolTest, LargerPathWidth) {
    double totalCost = pool(3.0, 2.0, 1000.0, 2000.0);
    double pathArea = PI * 25 - PI * 9;
    double fenceLength = 2 * PI * 5;
    double expectedCost = pathArea * 1000 + fenceLength * 2000;
    EXPECT_NEAR(totalCost, expectedCost, 1e-6);
}

TEST(PoolTest, SmallRadius) {
    double totalCost = pool(1.0, 0.5, 1000.0, 2000.0);
    double pathArea = PI * 2.25 - PI * 1;
    double fenceLength = 2 * PI * 1.5;
    double expectedCost = pathArea * 1000 + fenceLength * 2000;
    EXPECT_NEAR(totalCost, expectedCost, 1e-6);
}

TEST(PoolTest, ZeroCosts) {
    double totalCost = pool(3.0, 1.0, 0.0, 0.0);
    EXPECT_NEAR(totalCost, 0.0, 1e-6);
}
