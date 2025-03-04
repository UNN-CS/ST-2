// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, Initialization1) {
    Circle c(5);
    EXPECT_NEAR(c.getRadius(), 5, 1e-6);
}

TEST(CircleTest, Initialization2) {
    Circle c(10);
    EXPECT_NEAR(c.getRadius(), 10, 1e-6);
}

TEST(CircleTest, Initialization3) {
    Circle c(0);
    EXPECT_NEAR(c.getRadius(), 0, 1e-6);
}

TEST(CircleTest, Initialization4) {
    Circle c(15);
    EXPECT_NEAR(c.getRadius(), 15, 1e-6);
}

TEST(CircleTest, Initialization5) {
    Circle c(20);
    EXPECT_NEAR(c.getRadius(), 20, 1e-6);
}

TEST(CircleTest, SetRadius1) {
    Circle c(5);
    c.setRadius(10);
    EXPECT_NEAR(c.getRadius(), 10, 1e-6);
}

TEST(CircleTest, SetRadius2) {
    Circle c(10);
    c.setRadius(20);
    EXPECT_NEAR(c.getRadius(), 20, 1e-6);
}

TEST(CircleTest, SetRadius3) {
    Circle c(5);
    c.setRadius(0);
    EXPECT_NEAR(c.getRadius(), 0, 1e-6);
}

TEST(CircleTest, SetFerence1) {
    Circle c(5);
    c.setFerence(2 * M_PI * 10);
    EXPECT_NEAR(c.getRadius(), 10, 1e-6);
}

TEST(CircleTest, SetFerence2) {
    Circle c(10);
    c.setFerence(2 * M_PI * 20);
    EXPECT_NEAR(c.getRadius(), 20, 1e-6);
}

TEST(CircleTest, SetFerence3) {
    Circle c(5);
    c.setFerence(0);
    EXPECT_NEAR(c.getRadius(), 0, 1e-6);
}

TEST(CircleTest, SetArea1) {
    Circle c(5);
    c.setArea(M_PI * 100);
    EXPECT_NEAR(c.getRadius(), 10, 1e-6);
}

TEST(CircleTest, SetArea2) {
    Circle c(10);
    c.setArea(M_PI * 400);
    EXPECT_NEAR(c.getRadius(), 20, 1e-6);
}

TEST(CircleTest, SetArea3) {
    Circle c(5);
    c.setArea(0);
    EXPECT_NEAR(c.getRadius(), 0, 1e-6);
}

TEST(CircleTest, GetFerence1) {
    Circle c(5);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5, 1e-6);
}

TEST(CircleTest, GetFerence2) {
    Circle c(10);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 10, 1e-6);
}

TEST(CircleTest, GetArea1) {
    Circle c(5);
    EXPECT_NEAR(c.getArea(), M_PI * 25, 1e-6);
}

TEST(CircleTest, GetArea2) {
    Circle c(10);
    EXPECT_NEAR(c.getArea(), M_PI * 100, 1e-6);
}

TEST(EarthRopeTest, GapCalculation) {
    double gap = calculateEarthRopeGap();
    EXPECT_NEAR(gap, 0.159, 1e-3);
}

TEST(PoolCostTest, CostCalculation) {
    double cost = calculatePoolCost();
    double expectedCost = 1000 * (M_PI * 16 - M_PI * 9) + 2000 * 2 * M_PI * 4;
    EXPECT_NEAR(cost, expectedCost, 1e-2);
}
