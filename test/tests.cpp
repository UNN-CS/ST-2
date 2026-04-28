// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kEps = 1e-9;
constexpr double kPi = 3.14159265358979323846;
}

TEST(CircleTest, ConstructorStoresRadius) {
    Circle c(2.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.5);
}

TEST(CircleTest, ConstructorCalculatesFerence) {
    Circle c(2.0);
    EXPECT_NEAR(c.getFerence(), 4.0 * kPi, kEps);
}

TEST(CircleTest, ConstructorCalculatesArea) {
    Circle c(3.0);
    EXPECT_NEAR(c.getArea(), 9.0 * kPi, kEps);
}

TEST(CircleTest, ConstructorThrowsOnNegativeRadius) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusUpdatesRadius) {
    Circle c(1.0);
    c.setRadius(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, SetRadiusUpdatesFerence) {
    Circle c(1.0);
    c.setRadius(5.0);
    EXPECT_NEAR(c.getFerence(), 10.0 * kPi, kEps);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
    Circle c(1.0);
    c.setRadius(5.0);
    EXPECT_NEAR(c.getArea(), 25.0 * kPi, kEps);
}

TEST(CircleTest, SetRadiusThrowsOnNegativeValue) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-0.1), std::invalid_argument);
}

TEST(CircleTest, SetFerenceUpdatesRadius) {
    Circle c(1.0);
    c.setFerence(8.0 * kPi);
    EXPECT_NEAR(c.getRadius(), 4.0, kEps);
}

TEST(CircleTest, SetFerenceUpdatesArea) {
    Circle c(1.0);
    c.setFerence(8.0 * kPi);
    EXPECT_NEAR(c.getArea(), 16.0 * kPi, kEps);
}

TEST(CircleTest, SetFerenceAllowsZero) {
    Circle c(2.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceThrowsOnNegativeValue) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    c.setArea(49.0 * kPi);
    EXPECT_NEAR(c.getRadius(), 7.0, kEps);
}

TEST(CircleTest, SetAreaUpdatesFerence) {
    Circle c(1.0);
    c.setArea(49.0 * kPi);
    EXPECT_NEAR(c.getFerence(), 14.0 * kPi, kEps);
}

TEST(CircleTest, SetAreaAllowsZero) {
    Circle c(3.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, SetAreaThrowsOnNegativeValue) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-0.5), std::invalid_argument);
}

TEST(CircleTest, SequentialSettersKeepValuesConsistent) {
    Circle c(10.0);
    c.setArea(36.0 * kPi);
    c.setFerence(6.0 * kPi);
    EXPECT_NEAR(c.getRadius(), 3.0, kEps);
    EXPECT_NEAR(c.getArea(), 9.0 * kPi, kEps);
}

TEST(TasksTest, EarthRopeGapForOneMeterIncrease) {
    EXPECT_NEAR(earthRopeGap(), 1.0 / (2.0 * kPi), kEps);
}

TEST(TasksTest, EarthRopeGapIndependentOfEarthRadius) {
    const double gapSmall = earthRopeGap(1.0, 1.0);
    const double gapHuge = earthRopeGap(100000.0, 1.0);
    EXPECT_NEAR(gapSmall, gapHuge, 1e-7);
}

TEST(TasksTest, EarthRopeGapThrowsOnNegativeRadius) {
    EXPECT_THROW(earthRopeGap(-1.0, 1.0), std::invalid_argument);
}

TEST(TasksTest, EarthRopeGapThrowsOnNegativeAddedLength) {
    EXPECT_THROW(earthRopeGap(6378.1, -0.1), std::invalid_argument);
}

TEST(TasksTest, PoolConcreteCostDefaultValues) {
    EXPECT_NEAR(poolConcreteCost(), 7000.0 * kPi, 1e-6);
}

TEST(TasksTest, PoolFenceCostDefaultValues) {
    EXPECT_NEAR(poolFenceCost(), 16000.0 * kPi, 1e-6);
}

TEST(TasksTest, PoolConcreteCostWithCustomValues) {
    EXPECT_NEAR(poolConcreteCost(2.0, 2.0, 10.0), 120.0 * kPi, kEps);
}

TEST(TasksTest, PoolFenceCostWithCustomValues) {
    EXPECT_NEAR(poolFenceCost(2.0, 2.0, 5.0), 40.0 * kPi, kEps);
}

TEST(TasksTest, PoolConcreteCostZeroPathWidthIsZero) {
    EXPECT_DOUBLE_EQ(poolConcreteCost(3.0, 0.0, 1000.0), 0.0);
}

TEST(TasksTest, PoolFunctionsThrowOnNegativeValues) {
    EXPECT_THROW(poolConcreteCost(-1.0, 1.0, 1000.0), std::invalid_argument);
    EXPECT_THROW(poolConcreteCost(1.0, -1.0, 1000.0), std::invalid_argument);
    EXPECT_THROW(poolConcreteCost(1.0, 1.0, -1000.0), std::invalid_argument);
    EXPECT_THROW(poolFenceCost(-1.0, 1.0, 2000.0), std::invalid_argument);
    EXPECT_THROW(poolFenceCost(1.0, -1.0, 2000.0), std::invalid_argument);
    EXPECT_THROW(poolFenceCost(1.0, 1.0, -2000.0), std::invalid_argument);
}
