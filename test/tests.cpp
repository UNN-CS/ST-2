// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kEps = 1e-7;
constexpr double kPi = 3.14159265358979323846;
}  // namespace

TEST(Circle, ConstructorWithRadiusSetsRadius) {
    Circle c(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, kEps);
}

TEST(Circle, ConstructorWithRadiusSetsFerence) {
    Circle c(3.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 3.0, kEps);
}

TEST(Circle, ConstructorWithRadiusSetsArea) {
    Circle c(3.0);
    EXPECT_NEAR(c.getArea(), kPi * 9.0, kEps);
}

TEST(Circle, DefaultConstructorCreatesZeroCircle) {
    Circle c;
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle, SetRadiusUpdatesFerenceAndArea) {
    Circle c;
    c.setRadius(2.5);
    EXPECT_NEAR(c.getRadius(), 2.5, kEps);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 2.5, kEps);
    EXPECT_NEAR(c.getArea(), kPi * 2.5 * 2.5, kEps);
}

TEST(Circle, SetFerenceUpdatesRadiusAndArea) {
    Circle c;
    c.setFerence(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0 / (2.0 * kPi), kEps);
    EXPECT_NEAR(c.getArea(), kPi * std::pow(10.0 / (2.0 * kPi), 2), kEps);
}

TEST(Circle, SetAreaUpdatesRadiusAndFerence) {
    Circle c;
    c.setArea(12.0);
    EXPECT_NEAR(c.getRadius(), std::sqrt(12.0 / kPi), kEps);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi * std::sqrt(12.0 / kPi), kEps);
}

TEST(Circle, ConstructorThrowsForNegativeRadius) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(Circle, SetRadiusThrowsForNegativeValue) {
    Circle c;
    EXPECT_THROW(c.setRadius(-0.1), std::invalid_argument);
}

TEST(Circle, SetFerenceThrowsForNegativeValue) {
    Circle c;
    EXPECT_THROW(c.setFerence(-0.1), std::invalid_argument);
}

TEST(Circle, SetAreaThrowsForNegativeValue) {
    Circle c;
    EXPECT_THROW(c.setArea(-0.1), std::invalid_argument);
}

TEST(Circle, SetFerenceToZeroSetsZeroRadiusAndArea) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle, SetAreaToZeroSetsZeroRadiusAndFerence) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
}

TEST(Circle, SettersKeepValuesConsistentAfterMultipleUpdates) {
    Circle c(1.0);
    c.setRadius(2.0);
    c.setFerence(4.0 * kPi);
    c.setArea(16.0 * kPi);
    EXPECT_NEAR(c.getRadius(), 4.0, kEps);
    EXPECT_NEAR(c.getFerence(), 8.0 * kPi, kEps);
    EXPECT_NEAR(c.getArea(), 16.0 * kPi, kEps);
}

TEST(Tasks, EarthRopeGapForOneMeterEqualsOneOverTwoPi) {
    const double gap = calculateEarthRopeGap();
    EXPECT_NEAR(gap, 1.0 / (2.0 * kPi), 1e-9);
}

TEST(Tasks, EarthRopeGapDoesNotDependOnEarthRadius) {
    const double gap_small = calculateEarthRopeGap(10.0, 1.0);
    const double gap_earth = calculateEarthRopeGap(6378.1, 1.0);
    EXPECT_NEAR(gap_small, gap_earth, 1e-9);
}

TEST(Tasks, EarthRopeGapThrowsOnNegativeRadius) {
    EXPECT_THROW(calculateEarthRopeGap(-1.0, 1.0), std::invalid_argument);
}

TEST(Tasks, EarthRopeGapThrowsOnNegativeExtraLength) {
    EXPECT_THROW(calculateEarthRopeGap(6378.1, -0.1), std::invalid_argument);
}

TEST(Tasks, ConcreteCostForDefaultValues) {
    const double expected = kPi * (16.0 - 9.0) * 1000.0;
    EXPECT_NEAR(calculateConcreteCost(), expected, kEps);
}

TEST(Tasks, ConcreteCostThrowsOnNegativeInput) {
    EXPECT_THROW(calculateConcreteCost(-1.0, 1.0, 1000.0), std::invalid_argument);
    EXPECT_THROW(calculateConcreteCost(3.0, -1.0, 1000.0), std::invalid_argument);
    EXPECT_THROW(calculateConcreteCost(3.0, 1.0, -1000.0), std::invalid_argument);
}

TEST(Tasks, ConcreteCostCanBeZero) {
    EXPECT_NEAR(calculateConcreteCost(3.0, 0.0, 1000.0), 0.0, kEps);
}

TEST(Tasks, FenceCostForDefaultValues) {
    const double expected = 2.0 * kPi * 4.0 * 2000.0;
    EXPECT_NEAR(calculateFenceCost(), expected, kEps);
}

TEST(Tasks, FenceCostThrowsOnNegativeInput) {
    EXPECT_THROW(calculateFenceCost(-1.0, 1.0, 2000.0), std::invalid_argument);
    EXPECT_THROW(calculateFenceCost(3.0, -1.0, 2000.0), std::invalid_argument);
    EXPECT_THROW(calculateFenceCost(3.0, 1.0, -2000.0), std::invalid_argument);
}

TEST(Tasks, FenceCostCanBeZero) {
    EXPECT_NEAR(calculateFenceCost(3.0, 1.0, 0.0), 0.0, kEps);
}
