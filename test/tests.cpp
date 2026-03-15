// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.14159265358979323846;
constexpr double kEps = 1e-9;
}  // namespace

TEST(Circle, Constructor_SetsRadius) {
    Circle c(2.0);

    EXPECT_NEAR(c.getRadius(), 2.0, kEps);
}

TEST(Circle, Constructor_CalculatesFerence) {
    Circle c(2.0);

    EXPECT_NEAR(c.getFerence(), 4.0 * kPi, kEps);
}

TEST(Circle, Constructor_CalculatesArea) {
    Circle c(2.0);

    EXPECT_NEAR(c.getArea(), 4.0 * kPi, kEps);
}

TEST(Circle, Constructor_NegativeRadius_Throws) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(Circle, SetRadius_UpdatesFerence) {
    Circle c(1.0);

    c.setRadius(5.0);

    EXPECT_NEAR(c.getFerence(), 10.0 * kPi, kEps);
}

TEST(Circle, SetRadius_UpdatesArea) {
    Circle c(1.0);

    c.setRadius(5.0);

    EXPECT_NEAR(c.getArea(), 25.0 * kPi, kEps);
}

TEST(Circle, SetRadius_Zero_ResetsDerivedValues) {
    Circle c(3.0);

    c.setRadius(0.0);

    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle, SetRadius_Negative_Throws) {
    Circle c(1.0);

    EXPECT_THROW(c.setRadius(-0.1), std::invalid_argument);
}

TEST(Circle, SetFerence_UpdatesRadius) {
    Circle c(1.0);

    c.setFerence(20.0 * kPi);

    EXPECT_NEAR(c.getRadius(), 10.0, kEps);
}

TEST(Circle, SetFerence_UpdatesArea) {
    Circle c(1.0);

    c.setFerence(20.0 * kPi);

    EXPECT_NEAR(c.getArea(), 100.0 * kPi, kEps);
}

TEST(Circle, SetFerence_Zero_SetsZeroRadiusAndArea) {
    Circle c(3.0);

    c.setFerence(0.0);

    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle, SetFerence_Negative_Throws) {
    Circle c(1.0);

    EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(Circle, SetArea_UpdatesRadius) {
    Circle c(1.0);

    c.setArea(36.0 * kPi);

    EXPECT_NEAR(c.getRadius(), 6.0, kEps);
}

TEST(Circle, SetArea_UpdatesFerence) {
    Circle c(1.0);

    c.setArea(36.0 * kPi);

    EXPECT_NEAR(c.getFerence(), 12.0 * kPi, kEps);
}

TEST(Circle, SetArea_Zero_SetsZeroRadiusAndFerence) {
    Circle c(7.0);

    c.setArea(0.0);

    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
}

TEST(Circle, SetArea_Negative_Throws) {
    Circle c(1.0);

    EXPECT_THROW(c.setArea(-0.5), std::invalid_argument);
}

TEST(Circle, RadiusToFerenceToRadius_RoundTrip) {
    Circle c(8.25);
    const double initialRadius = c.getRadius();

    c.setFerence(c.getFerence());

    EXPECT_NEAR(c.getRadius(), initialRadius, kEps);
}

TEST(Circle, RadiusToAreaToRadius_RoundTrip) {
    Circle c(11.75);
    const double initialRadius = c.getRadius();

    c.setArea(c.getArea());

    EXPECT_NEAR(c.getRadius(), initialRadius, kEps);
}

TEST(Tasks, EarthRope_DefaultData_HasCorrectGap) {
    const double gap = calculateEarthRopeGap();

    EXPECT_NEAR(gap, 1.0 / (2.0 * kPi), kEps);
}

TEST(Tasks, EarthRope_GapIndependentFromEarthRadius) {
    const double gap1 = calculateEarthRopeGap(6378100.0, 1.0);
    const double gap2 = calculateEarthRopeGap(1.0, 1.0);

    EXPECT_NEAR(gap1, gap2, kEps);
}

TEST(Tasks, EarthRope_NegativeRadius_Throws) {
    EXPECT_THROW(calculateEarthRopeGap(-1.0, 1.0), std::invalid_argument);
}

TEST(Tasks, EarthRope_NegativeAddedLength_Throws) {
    EXPECT_THROW(calculateEarthRopeGap(10.0, -1.0), std::invalid_argument);
}

TEST(Tasks, Pool_DefaultData_ReturnsCorrectCosts) {
    const PoolCosts costs = calculatePoolCosts();

    EXPECT_NEAR(costs.concreteCost, 7000.0 * kPi, kEps);
    EXPECT_NEAR(costs.fenceCost, 16000.0 * kPi, kEps);
}

TEST(Tasks, Pool_ZeroPathWidth_ConcreteCostIsZero) {
    const PoolCosts costs = calculatePoolCosts(3.0, 0.0, 1000.0, 2000.0);

    EXPECT_NEAR(costs.concreteCost, 0.0, kEps);
}

TEST(Tasks, Pool_ZeroPathWidth_FenceAroundPoolOnly) {
    const PoolCosts costs = calculatePoolCosts(3.0, 0.0, 1000.0, 2000.0);

    EXPECT_NEAR(costs.fenceCost, 12000.0 * kPi, kEps);
}

TEST(Tasks, Pool_CustomRates_AreApplied) {
    const PoolCosts costs = calculatePoolCosts(2.0, 2.0, 1500.0, 3500.0);

    EXPECT_NEAR(costs.concreteCost, 18000.0 * kPi, kEps);
    EXPECT_NEAR(costs.fenceCost, 28000.0 * kPi, kEps);
}

TEST(Tasks, Pool_NegativeRadius_Throws) {
    EXPECT_THROW(calculatePoolCosts(-1.0, 1.0, 1000.0, 2000.0),
                 std::invalid_argument);
}

TEST(Tasks, Pool_NegativePathWidth_Throws) {
    EXPECT_THROW(calculatePoolCosts(3.0, -1.0, 1000.0, 2000.0),
                 std::invalid_argument);
}

TEST(Tasks, Pool_NegativeConcreteRate_Throws) {
    EXPECT_THROW(calculatePoolCosts(3.0, 1.0, -1000.0, 2000.0),
                 std::invalid_argument);
}

TEST(Tasks, Pool_NegativeFenceRate_Throws) {
    EXPECT_THROW(calculatePoolCosts(3.0, 1.0, 1000.0, -2000.0),
                 std::invalid_argument);
}


