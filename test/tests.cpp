// Copyright 2026 Klimov M.D.
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

TEST(CircleTest, Constructor) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 10.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 100.0, 1e-9);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    c.setFerence(2 * M_PI * 5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 25.0, 1e-9);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    c.setArea(M_PI * 16.0);
    EXPECT_NEAR(c.getRadius(), 4.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 4.0, 1e-9);
}

TEST(CircleTest, GetRadius) {
    Circle c(7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
}

TEST(CircleTest, GetFerence) {
    Circle c(7.0);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 7.0, 1e-9);
}

TEST(CircleTest, GetArea) {
    Circle c(7.0);
    EXPECT_NEAR(c.getArea(), M_PI * 49.0, 1e-9);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, UpdateRadiusUpdatesOthers) {
    Circle c(2.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 3.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 9.0, 1e-9);
}

TEST(CircleTest, UpdateFerenceUpdatesOthers) {
    Circle c(2.0);
    c.setFerence(4 * M_PI);
    EXPECT_NEAR(c.getRadius(), 2.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 4.0, 1e-9);
}

TEST(CircleTest, UpdateAreaUpdatesOthers) {
    Circle c(2.0);
    c.setArea(9 * M_PI);
    EXPECT_NEAR(c.getRadius(), 3.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 6 * M_PI, 1e-9);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1000000.0);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1000000.0, 1e-5);
}

TEST(CircleTest, FractionalRadius) {
    Circle c(0.5);
    EXPECT_NEAR(c.getArea(), M_PI * 0.25, 1e-9);
}

TEST(CircleTest, NegativeAreaSet) {
    Circle c(1.0);
    c.setArea(-M_PI);
    EXPECT_TRUE(std::isnan(c.getRadius()));
}

TEST(CircleTest, RopeTaskGap) {
    double gap = ropeTask();
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-9);
}

TEST(CircleTest, PoolTaskCost) {
    double cost = poolTask();
    double expectedPathArea = M_PI * (16.0 - 9.0);
    double expectedFence = 2 * M_PI * 4.0;
    double expectedCost = expectedPathArea * 1000.0 + expectedFence * 2000.0;
    EXPECT_NEAR(cost, expectedCost, 1e-5);
}

TEST(CircleTest, PoolTaskConcreteOnly) {
    Circle pool(3.0);
    Circle outer(4.0);
    double area = outer.getArea() - pool.getArea();
    EXPECT_NEAR(area, 7 * M_PI, 1e-9);
}

TEST(CircleTest, PoolTaskFenceOnly) {
    Circle outer(4.0);
    EXPECT_NEAR(outer.getFerence(), 8 * M_PI, 1e-9);
}

TEST(CircleTest, RopeTaskOriginal) {
    Circle earth(6378100.0);
    EXPECT_NEAR(earth.getFerence(), 2 * M_PI * 6378100.0, 1e-5);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}
