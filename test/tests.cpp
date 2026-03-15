// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

static const double PI = 3.14159265358979323846;
static const double EPS = 1e-6;

TEST(CircleConstructor, RadiusIsSet) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleConstructor, FerenceIsCalculated) {
    Circle c(1.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI, EPS);
}

TEST(CircleConstructor, AreaIsCalculated) {
    Circle c(1.0);
    EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleConstructor, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleSetRadius, FerenceRecalculated) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 3.0, EPS);
}

TEST(CircleSetRadius, AreaRecalculated) {
    Circle c(1.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getArea(), PI * 16.0, EPS);
}

TEST(CircleSetRadius, RadiusUpdated) {
    Circle c(1.0);
    c.setRadius(7.5);
    EXPECT_NEAR(c.getRadius(), 7.5, EPS);
}

TEST(CircleSetFerence, RadiusRecalculated) {
    Circle c(0.0);
    c.setFerence(2.0 * PI);
    EXPECT_NEAR(c.getRadius(), 1.0, EPS);
}

TEST(CircleSetFerence, AreaRecalculated) {
    Circle c(0.0);
    c.setFerence(2.0 * PI * 3.0);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleSetFerence, FerenceUpdated) {
    Circle c(1.0);
    double f = 100.0;
    c.setFerence(f);
    EXPECT_NEAR(c.getFerence(), f, EPS);
}

TEST(CircleSetArea, RadiusRecalculated) {
    Circle c(0.0);
    c.setArea(PI * 25.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleSetArea, FerenceRecalculated) {
    Circle c(0.0);
    c.setArea(PI * 4.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 2.0, EPS);
}

TEST(CircleSetArea, AreaUpdated) {
    Circle c(1.0);
    double a = PI * 9.0;
    c.setArea(a);
    EXPECT_NEAR(c.getArea(), a, EPS);
}

TEST(CircleConsistency, SetRadiusThenFerence) {
    Circle c(2.0);
    c.setFerence(c.getFerence());
    EXPECT_NEAR(c.getRadius(), 2.0, EPS);
}

TEST(CircleConsistency, SetRadiusThenArea) {
    Circle c(3.0);
    c.setArea(c.getArea());
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
}

TEST(CircleConsistency, LargeRadius) {
    double r = 1e9;
    Circle c(r);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * r, EPS * r);
    EXPECT_NEAR(c.getArea(), PI * r * r, EPS * r * r);
}

TEST(RopeTask, GapIsApproximatelyOneOverTwoPi) {
    double gap = ropeGap();
    EXPECT_NEAR(gap, 1.0 / (2.0 * PI), EPS);
}

TEST(RopeTask, GapIsPositive) {
    EXPECT_GT(ropeGap(), 0.0);
}

TEST(RopeTask, GapIsLessThanOneMeter) {
    EXPECT_LT(ropeGap(), 1.0);
}

TEST(PoolTask, ConcreteCost) {
    PoolCosts costs = poolCosts(3.0, 1.0, 1000.0, 2000.0);
    double expectedArea = PI * (4.0 * 4.0 - 3.0 * 3.0);
    EXPECT_NEAR(costs.concreteCost, expectedArea * 1000.0, EPS * 1000.0);
}

TEST(PoolTask, FenceCost) {
    PoolCosts costs = poolCosts(3.0, 1.0, 1000.0, 2000.0);
    double expectedFence = 2.0 * PI * 4.0;
    EXPECT_NEAR(costs.fenceCost, expectedFence * 2000.0, EPS * 2000.0);
}

TEST(PoolTask, ConcreteCostPositive) {
    PoolCosts costs = poolCosts(3.0, 1.0, 1000.0, 2000.0);
    EXPECT_GT(costs.concreteCost, 0.0);
}

TEST(PoolTask, FenceCostPositive) {
    PoolCosts costs = poolCosts(3.0, 1.0, 1000.0, 2000.0);
    EXPECT_GT(costs.fenceCost, 0.0);
}

TEST(PoolTask, ZeroPathWidth) {
    PoolCosts costs = poolCosts(3.0, 0.0, 1000.0, 2000.0);
    EXPECT_NEAR(costs.concreteCost, 0.0, EPS);
    double expectedFence = 2.0 * PI * 3.0 * 2000.0;
    EXPECT_NEAR(costs.fenceCost, expectedFence, EPS * 2000.0);
}

TEST(PoolTask, DoublePriceDoublesCost) {
    PoolCosts c1 = poolCosts(3.0, 1.0, 1000.0, 2000.0);
    PoolCosts c2 = poolCosts(3.0, 1.0, 2000.0, 4000.0);
    EXPECT_NEAR(c2.concreteCost, c1.concreteCost * 2.0, EPS * 1000.0);
    EXPECT_NEAR(c2.fenceCost, c1.fenceCost * 2.0, EPS * 2000.0);
}
