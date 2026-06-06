// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>

#include "circle.h"
#include "tasks.h"

const double PI = std::acos(-1.0);
const double EPS = 0.01;

TEST(CircleTest, RadiusStoredCorrectlyAfterConstruction) {
    Circle c(5);

    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleTest, AreaCalculatedForRadiusTwo) {
    Circle c(2);

    EXPECT_NEAR(c.getArea(), PI * 4, EPS);
}

TEST(CircleTest, LengthCalculatedForRadiusThree) {
    Circle c(3);

    EXPECT_NEAR(c.getFerence(), 2 * PI * 3, EPS);
}

TEST(CircleTest, RadiusCanBeChanged) {
    Circle c(1);

    c.setRadius(4);

    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
}

TEST(CircleTest, AreaChangesAfterRadiusChange) {
    Circle c(1);

    c.setRadius(4);

    EXPECT_NEAR(c.getArea(), PI * 16, EPS);
}

TEST(CircleTest, LengthChangesAfterRadiusChange) {
    Circle c(1);

    c.setRadius(4);

    EXPECT_NEAR(c.getFerence(), 2 * PI * 4, EPS);
}

TEST(CircleTest, RadiusCalculatedFromLength) {
    Circle c(0);

    c.setFerence(2 * PI * 5);

    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleTest, AreaCalculatedFromLength) {
    Circle c(0);

    c.setFerence(2 * PI * 5);

    EXPECT_NEAR(c.getArea(), PI * 25, EPS);
}

TEST(CircleTest, RadiusCalculatedFromArea) {
    Circle c(0);

    c.setArea(PI * 9);

    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
}

TEST(CircleTest, LengthCalculatedFromArea) {
    Circle c(0);

    c.setArea(PI * 9);

    EXPECT_NEAR(c.getFerence(), 2 * PI * 3, EPS);
}

TEST(CircleTest, ZeroRadiusProducesZeroArea) {
    Circle c(0);

    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleTest, ZeroRadiusProducesZeroLength) {
    Circle c(0);

    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
}

TEST(CircleTest, RadiusRemainsSameAfterAreaConversion) {
    Circle c(7);

    double area = c.getArea();

    c.setArea(area);

    EXPECT_NEAR(c.getRadius(), 7.0, EPS);
}

TEST(CircleTest, RadiusRemainsSameAfterLengthConversion) {
    Circle c(7);

    double length = c.getFerence();

    c.setFerence(length);

    EXPECT_NEAR(c.getRadius(), 7.0, EPS);
}

TEST(RopeTaskTest, GapIsPositive) {
    EXPECT_GT(ropeGap(6378.1), 0.0);
}

TEST(RopeTaskTest, GapForEarth) {
    EXPECT_NEAR(ropeGap(6378.1), 1.0 / (2.0 * PI), EPS);
}

TEST(RopeTaskTest, GapDoesNotDependOnRadius) {
    EXPECT_NEAR(
        ropeGap(1.0),
        ropeGap(6378.1),
        EPS);
}

TEST(PoolTaskTest, ConcreteCostForTaskValues) {
    double cost = poolConcreteCost(3, 1, 1000);

    double expected =
        (PI * 4 * 4 - PI * 3 * 3) * 1000;

    EXPECT_NEAR(cost, expected, 1.0);
}

TEST(PoolTaskTest, FenceCostForTaskValues) {
    double cost = poolFenceCost(3, 1, 2000);

    double expected =
        2 * PI * 4 * 2000;

    EXPECT_NEAR(cost, expected, 2.0);
}

TEST(PoolTaskTest, TotalCostForTaskValues) {
    double cost = poolTotalCost(3, 1, 1000, 2000);

    double expected =
        (PI * 4 * 4 - PI * 3 * 3) * 1000
        + 2 * PI * 4 * 2000;

    EXPECT_NEAR(cost, expected, 2.0);
}

TEST(PoolTaskTest, TotalCostEqualsPartsSum) {
    EXPECT_NEAR(
        poolTotalCost(3, 1, 1000, 2000),
        poolConcreteCost(3, 1, 1000)
        + poolFenceCost(3, 1, 2000),
        EPS);
}

TEST(PoolTaskTest, FenceCostIsGreaterThanConcreteCost) {
    EXPECT_GT(
        poolFenceCost(3, 1, 2000),
        poolConcreteCost(3, 1, 1000));
}
