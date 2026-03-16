// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14;
const double EPS = 0.000001;

TEST(CircleTest, ConstructorRadius) {
    Circle c(2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, EPS);
}

TEST(CircleTest, FerenceFromRadius1) {
    Circle c(1.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
}

TEST(CircleTest, AreaFromRadius1) {
    Circle c(1.0);
    EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleTest, SetRadius) {
    Circle c;
    c.setRadius(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
}

TEST(CircleTest, SetRadiusUpdatesFerence) {
    Circle c;
    c.setRadius(2.0);
    EXPECT_NEAR(c.getFerence(), 4 * PI, EPS);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
    Circle c;
    c.setRadius(2.0);
    EXPECT_NEAR(c.getArea(), 4 * PI, EPS);
}

TEST(CircleTest, SetFerence) {
    Circle c;
    c.setFerence(2 * PI);
    EXPECT_NEAR(c.getRadius(), 1.0, EPS);
}

TEST(CircleTest, SetFerenceUpdatesArea) {
    Circle c;
    c.setFerence(4 * PI);
    EXPECT_NEAR(c.getArea(), 4 * PI, EPS);
}

TEST(CircleTest, SetArea) {
    Circle c;
    c.setArea(PI);
    EXPECT_NEAR(c.getRadius(), 1.0, EPS);
}

TEST(CircleTest, SetAreaUpdatesFerence) {
    Circle c;
    c.setArea(PI);
    EXPECT_NEAR(c.getFerence(), 2 * PI, EPS);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1000.0);
    EXPECT_NEAR(c.getArea(), PI * 1000000, EPS);
}

TEST(CircleTest, ResetRadius) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, EPS);
}

TEST(CircleTest, MultipleSetCalls) {
    Circle c;
    c.setRadius(1.0);
    c.setFerence(4 * PI);
    EXPECT_NEAR(c.getRadius(), 2.0, EPS);
}

TEST(CircleTest, GetFerence) {
    Circle c(3.0);
    EXPECT_NEAR(c.getFerence(), 6 * PI, EPS);
}

TEST(TaskTest, EarthRopeGapPositive) {
    EXPECT_GT(earthRopeGap(), 0.0);
}

TEST(TaskTest, EarthRopeGapCorrect) {
    EXPECT_NEAR(earthRopeGap(), 1.0 / (2 * PI), EPS);
}

TEST(TaskTest, EarthRopeGapConstant) {
    double gap = earthRopeGap();
    EXPECT_NEAR(gap, 0.1591549, 1e-4);
}

TEST(TaskTest, PoolCostPositive) {
    EXPECT_GT(poolCost(), 0.0);
}

TEST(TaskTest, PoolCostCorrect) {
    double poolRadius = 3.0;
    double pathRadius = 4.0;

    double pathArea = PI * (pathRadius * pathRadius - poolRadius * poolRadius);
    double expected =
        pathArea * 1000 +
        (2 * PI * pathRadius) * 2000;

    EXPECT_NEAR(poolCost(), expected, EPS);
}

TEST(TaskTest, PoolCostNotZero) {
    EXPECT_NE(poolCost(), 0.0);
}
