// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include "circle.h"
#include "tasks.h"

using std::numeric_limits;

// =========================================================

TEST(CircleConstructor, CreatesValidCircle) {
    Circle c(10.0);

    EXPECT_NEAR(c.getRadius(), 10.0, Circle::EPS);
    EXPECT_NEAR(c.getFerence(), 2 * Circle::PI * 10.0, Circle::EPS);
    EXPECT_NEAR(c.getArea(), Circle::PI * 100.0, Circle::EPS);
}

TEST(CircleConstructor, NegativeRadiusThrows) {
    EXPECT_THROW(Circle(-5.0), std::invalid_argument);
}

TEST(CircleConstructor, NaNRadiusThrows) {
    EXPECT_THROW(Circle(numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);
}

TEST(CircleConstructor, InfRadiusThrows) {
    EXPECT_THROW(Circle(numeric_limits<double>::infinity()),
                 std::invalid_argument);
}

TEST(CircleConstructor, MaxRadiusThrows) {
    EXPECT_THROW(Circle(numeric_limits<double>::max()),
                 std::invalid_argument);
}

// =========================================================

TEST(CircleSetRadius, UpdatesValuesCorrectly) {
    Circle c(5.0);

    c.setRadius(7.0);

    EXPECT_NEAR(c.getRadius(), 7.0, Circle::EPS);
    EXPECT_NEAR(c.getFerence(), 2 * Circle::PI * 7.0, Circle::EPS);
    EXPECT_NEAR(c.getArea(), Circle::PI * 49.0, Circle::EPS);
}

TEST(CircleSetRadius, NegativeValueThrows) {
    Circle c(5.0);

    EXPECT_THROW(c.setRadius(-2.0), std::invalid_argument);
}

TEST(CircleSetRadius, NaNThrows) {
    Circle c(5.0);

    EXPECT_THROW(c.setRadius(numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);
}

TEST(CircleSetRadius, InfinityThrows) {
    Circle c(5.0);

    EXPECT_THROW(c.setRadius(numeric_limits<double>::infinity()),
                 std::invalid_argument);
}

TEST(CircleSetRadius, MaxThrows) {
    Circle c(5.0);

    EXPECT_THROW(c.setRadius(numeric_limits<double>::max()),
                 std::invalid_argument);
}

// =========================================================

TEST(CircleSetFerence, RecalculatesRadius) {
    Circle c(5.0);

    double newFerence = 2 * Circle::PI * 20.0;

    c.setFerence(newFerence);

    EXPECT_NEAR(c.getRadius(), 20.0, Circle::EPS);
}

TEST(CircleSetFerence, RecalculatesArea) {
    Circle c(1.0);

    double newFerence = 2 * Circle::PI * 4.0;

    c.setFerence(newFerence);

    EXPECT_NEAR(c.getArea(), Circle::PI * 16.0, Circle::EPS);
}

TEST(CircleSetFerence, NegativeThrows) {
    Circle c(2.0);

    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
}

TEST(CircleSetFerence, NaNThrows) {
    Circle c(2.0);

    EXPECT_THROW(c.setFerence(numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);
}

TEST(CircleSetFerence, MaxThrows) {
    Circle c(2.0);

    EXPECT_THROW(c.setFerence(numeric_limits<double>::max()),
                 std::invalid_argument);
}

TEST(CircleSetFerence, InfiniteThrows) {
    Circle c(2.0);

    EXPECT_THROW(c.setFerence(numeric_limits<double>::infinity()),
                 std::invalid_argument);
}

// =========================================================

TEST(CircleSetArea, RecalculatesRadius) {
    Circle c(2.0);

    double newArea = Circle::PI * 9.0;

    c.setArea(newArea);

    EXPECT_NEAR(c.getRadius(), 3.0, Circle::EPS);
}

TEST(CircleSetArea, RecalculatesFerence) {
    Circle c(1.0);

    double newArea = Circle::PI * 25.0;

    c.setArea(newArea);

    EXPECT_NEAR(c.getFerence(), 2 * Circle::PI * 5.0, Circle::EPS);
}

TEST(CircleSetArea, NegativeThrows) {
    Circle c(3.0);

    EXPECT_THROW(c.setArea(-10.0), std::invalid_argument);
}

TEST(CircleSetArea, InfinityThrows) {
    Circle c(3.0);

    EXPECT_THROW(c.setArea(numeric_limits<double>::infinity()),
                 std::invalid_argument);
}

TEST(CircleSetArea, NanThrows) {
    Circle c(3.0);

    EXPECT_THROW(c.setArea(numeric_limits<double>::quiet_NaN()),
                 std::invalid_argument);
}

// =========================================================

TEST(CircleGetters, Consistency) {
    Circle c(8.0);

    EXPECT_NEAR(c.getFerence(), 2 * Circle::PI * c.getRadius(), Circle::EPS);
    EXPECT_NEAR(c.getArea(), Circle::PI * c.getRadius() * c.getRadius(),
                 Circle::EPS);
}

// =========================================================

TEST(Tasks, EarthGapCorrectValue) {
    double gap = calculateEarthGap();

    EXPECT_NEAR(gap, 1.0 / (2 * Circle::PI), 1e-6);
}

TEST(Tasks, PoolCostCorrectValue) {
    double cost = calculatePoolCost();

    double poolRadius = 3.0;
    double pathWidth = 1.0;

    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    double pathArea = outer.getArea() - pool.getArea();
    double expected = pathArea * 1000.0 + outer.getFerence() * 2000.0;

    EXPECT_NEAR(cost, expected, Circle::EPS);
}

TEST(Tasks, PoolCostPositive) {
    double cost = calculatePoolCost();

    EXPECT_GT(cost, 0.0);
}
