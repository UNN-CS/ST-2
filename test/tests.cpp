// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <stdexcept>
#include <cmath>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.14159265358979323846;
constexpr double kEps = 1e-7;
}  // namespace

TEST(CircleTest, ConstructorSetsRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, kEps);
}

TEST(CircleTest, ConstructorCalculatesFerence) {
    Circle c(1.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi, kEps);
}

TEST(CircleTest, ConstructorCalculatesArea) {
    Circle c(2.0);
    EXPECT_NEAR(c.getArea(), 4.0 * kPi, kEps);
}

TEST(CircleTest, ZeroRadiusIsValid) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleTest, NegativeRadiusInConstructorThrows) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetRadiusChangesRadius) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, kEps);
}

TEST(CircleTest, SetRadiusRecalculatesFerence) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getFerence(), 6.0 * kPi, kEps);
}

TEST(CircleTest, SetRadiusRecalculatesArea) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getArea(), 9.0 * kPi, kEps);
}

TEST(CircleTest, NegativeRadiusThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-2.0), std::invalid_argument);
}

TEST(CircleTest, SetFerenceChangesFerence) {
    Circle c(1.0);
    c.setFerence(4.0 * kPi);
    EXPECT_NEAR(c.getFerence(), 4.0 * kPi, kEps);
}

TEST(CircleTest, SetFerenceRecalculatesRadius) {
    Circle c(1.0);
    c.setFerence(4.0 * kPi);
    EXPECT_NEAR(c.getRadius(), 2.0, kEps);
}

TEST(CircleTest, SetFerenceRecalculatesArea) {
    Circle c(1.0);
    c.setFerence(4.0 * kPi);
    EXPECT_NEAR(c.getArea(), 4.0 * kPi, kEps);
}

TEST(CircleTest, ZeroFerenceIsValid) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleTest, NegativeFerenceThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetAreaChangesArea) {
    Circle c(1.0);
    c.setArea(16.0 * kPi);
    EXPECT_NEAR(c.getArea(), 16.0 * kPi, kEps);
}

TEST(CircleTest, SetAreaRecalculatesRadius) {
    Circle c(1.0);
    c.setArea(16.0 * kPi);
    EXPECT_NEAR(c.getRadius(), 4.0, kEps);
}

TEST(CircleTest, SetAreaRecalculatesFerence) {
    Circle c(1.0);
    c.setArea(16.0 * kPi);
    EXPECT_NEAR(c.getFerence(), 8.0 * kPi, kEps);
}

TEST(CircleTest, ZeroAreaIsValid) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleTest, NegativeAreaThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-10.0), std::invalid_argument);
}

TEST(CircleTest, RepeatedConversionsAreConsistent) {
    Circle c(7.0);
    double radius = c.getRadius();
    double ference = c.getFerence();
    double area = c.getArea();

    c.setFerence(ference);
    EXPECT_NEAR(c.getRadius(), radius, kEps);
    EXPECT_NEAR(c.getArea(), area, kEps);

    c.setArea(area);
    EXPECT_NEAR(c.getRadius(), radius, kEps);
    EXPECT_NEAR(c.getFerence(), ference, kEps);
}

TEST(TasksTest, EarthRopeGapIsCorrect) {
    double expected = 1.0 / (2.0 * kPi);
    EXPECT_NEAR(earthRopeGap(), expected, kEps);
}

TEST(TasksTest, EarthRopeGapDoesNotDependOnEarthRadiusFormulaCheck) {
    double gap = earthRopeGap();
    EXPECT_GT(gap, 0.15);
    EXPECT_LT(gap, 0.16);
}

TEST(TasksTest, PoolConcreteCostIsCorrect) {
    double expected = (16.0 * kPi - 9.0 * kPi) * 1000.0;
    EXPECT_NEAR(poolConcreteCost(), expected, kEps);
}

TEST(TasksTest, PoolFenceCostIsCorrect) {
    double expected = (8.0 * kPi) * 2000.0;
    EXPECT_NEAR(poolFenceCost(), expected, kEps);
}

TEST(TasksTest, PoolConcreteCostIsPositive) {
    EXPECT_GT(poolConcreteCost(), 0.0);
}

TEST(TasksTest, PoolFenceCostIsPositive) {
    EXPECT_GT(poolFenceCost(), 0.0);
}
