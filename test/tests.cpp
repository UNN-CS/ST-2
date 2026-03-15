// Copyright 2026 UNN-CS

#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {

constexpr double kPi() noexcept {
  return 3.14159265358979323846264338327950288;
}

constexpr double kEps = 1e-9;

}  // namespace

TEST(CircleBasicTest, DefaultConstructorGivesZeroValues) {
  const Circle c;
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleBasicTest, ConstructorWithPositiveRadiusInitializesAllFields) {
  const Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi() * 5.0, kEps);
  EXPECT_NEAR(c.getArea(), kPi() * 25.0, kEps);
}

TEST(CircleBasicTest, ConstructorWithZeroRadiusIsValid) {
  const Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleSetRadiusTest, UpdatesDependentFields) {
  Circle c;
  c.setRadius(3.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi() * 3.0, kEps);
  EXPECT_NEAR(c.getArea(), kPi() * 9.0, kEps);
}

TEST(CircleSetRadiusTest, AllowsChangeBackToZero) {
  Circle c(10.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleSetRadiusTest, ThrowsOnNegativeRadius) {
  Circle c;
  EXPECT_THROW(c.setRadius(-1.0), std::invalid_argument);
}

TEST(CircleSetFerenceTest, UpdatesRadiusAndArea) {
  Circle c;
  const double targetRadius = 4.0;
  const double f = 2.0 * kPi() * targetRadius;
  c.setFerence(f);

  EXPECT_NEAR(c.getRadius(), targetRadius, kEps);
  EXPECT_NEAR(c.getFerence(), f, kEps);
  EXPECT_NEAR(c.getArea(), kPi() * targetRadius * targetRadius, kEps);
}

TEST(CircleSetFerenceTest, ZeroFerenceLeadsToZeroRadiusAndArea) {
  Circle c(5.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleSetFerenceTest, ThrowsOnNegativeFerence) {
  Circle c;
  EXPECT_THROW(c.setFerence(-0.5), std::invalid_argument);
}

TEST(CircleSetAreaTest, UpdatesRadiusAndFerence) {
  Circle c;
  const double targetRadius = 2.5;
  const double area = kPi() * targetRadius * targetRadius;

  c.setArea(area);

  EXPECT_NEAR(c.getRadius(), targetRadius, kEps);
  EXPECT_NEAR(c.getArea(), area, kEps);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi() * targetRadius, kEps);
}

TEST(CircleSetAreaTest, ZeroAreaLeadsToZeroRadiusAndFerence) {
  Circle c(10.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleSetAreaTest, ThrowsOnNegativeArea) {
  Circle c;
  EXPECT_THROW(c.setArea(-10.0), std::invalid_argument);
}

TEST(CircleConsistencyTest, MultipleUpdatesKeepInvariants) {
  Circle c;
  c.setRadius(1.0);
  const double f = c.getFerence();
  c.setFerence(f);
  const double a = c.getArea();
  c.setArea(a);

  EXPECT_NEAR(c.getFerence(), 2.0 * kPi() * c.getRadius(), kEps);
  EXPECT_NEAR(c.getArea(), kPi() * c.getRadius() * c.getRadius(), kEps);
}

TEST(CircleConsistencyTest, DifferentSettersLeadToSameCircle) {
  const double r = 7.0;
  const double f = 2.0 * kPi() * r;
  const double a = kPi() * r * r;

  Circle fromRadius;
  fromRadius.setRadius(r);

  Circle fromFerence;
  fromFerence.setFerence(f);

  Circle fromArea;
  fromArea.setArea(a);

  EXPECT_NEAR(fromRadius.getRadius(), fromFerence.getRadius(), kEps);
  EXPECT_NEAR(fromRadius.getRadius(), fromArea.getRadius(), kEps);
  EXPECT_NEAR(fromRadius.getFerence(), fromFerence.getFerence(), kEps);
  EXPECT_NEAR(fromRadius.getArea(), fromArea.getArea(), kEps);
}

TEST(RopeGapTest, GapIsPositiveAndFinite) {
  const double gap = computeRopeGap();
  EXPECT_GT(gap, 0.0);
  EXPECT_TRUE(std::isfinite(gap));
}

TEST(RopeGapTest, GapDoesNotDependOnEarthRadiusNumerically) {
  const double gap = computeRopeGap();
  const double expected = 1.0 / (2.0 * kPi());
  EXPECT_NEAR(gap, expected, 1e-7);
}

TEST(RopeGapTest, GapApproximateValue) {
  const double gap = computeRopeGap();
  EXPECT_NEAR(gap, 0.15915494309189535, 1e-7);
}

TEST(PoolTaskTest, ConcreteCostPositive) {
  const double cost = computePoolConcreteCost();
  EXPECT_GT(cost, 0.0);
}

TEST(PoolTaskTest, FenceCostPositive) {
  const double cost = computePoolFenceCost();
  EXPECT_GT(cost, 0.0);
}

TEST(PoolTaskTest, ConcreteCostMatchesAnalyticalFormula) {
  const double cost = computePoolConcreteCost();
  const double innerR = 3.0;
  const double outerR = 4.0;
  const double pathArea = kPi() * (outerR * outerR - innerR * innerR);
  const double expected = pathArea * 1000.0;

  EXPECT_NEAR(cost, expected, 1e-6);
}

TEST(PoolTaskTest, FenceCostMatchesAnalyticalFormula) {
  const double cost = computePoolFenceCost();
  const double outerR = 4.0;
  const double fenceLength = 2.0 * kPi() * outerR;
  const double expected = fenceLength * 2000.0;

  EXPECT_NEAR(cost, expected, 1e-6);
}
