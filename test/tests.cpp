// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
const double EPS = 1e-9;

double Pi() {
  return std::acos(-1.0);
}
}  // namespace

TEST(CircleConstructor, ValidRadius) {
  Circle c(5.0);
  EXPECT_NEAR(c.getRadius(), 5.0, EPS);
  EXPECT_NEAR(c.getArea(), Pi() * 25.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2.0 * Pi() * 5.0, EPS);
}

TEST(CircleConstructor, ZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleConstructor, NegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(SetRadius, Positive) {
  Circle c(1.0);
  c.setRadius(3.0);
  EXPECT_NEAR(c.getRadius(), 3.0, EPS);
  EXPECT_NEAR(c.getArea(), Pi() * 9.0, EPS);
  EXPECT_NEAR(c.getFerence(), 6.0 * Pi(), EPS);
}

TEST(SetRadius, Zero) {
  Circle c(10.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(SetRadius, Negative) {
  Circle c(5.0);
  EXPECT_THROW(c.setRadius(-2.0), std::invalid_argument);
  EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(SetFerence, Positive) {
  Circle c(2.0);
  double new_ference = 10.0;
  c.setFerence(new_ference);
  EXPECT_NEAR(c.getFerence(), new_ference, EPS);
  EXPECT_NEAR(c.getRadius(), new_ference / (2.0 * Pi()), EPS);
  EXPECT_NEAR(c.getArea(), Pi() * std::pow(new_ference / (2.0 * Pi()), 2), EPS);
}

TEST(SetFerence, Zero) {
  Circle c(4.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(SetFerence, Negative) {
  Circle c(3.0);
  EXPECT_THROW(c.setFerence(-5.0), std::invalid_argument);
  EXPECT_NEAR(c.getFerence(), 6.0 * Pi(), EPS);
}

TEST(SetArea, Positive) {
  Circle c(1.0);
  double new_area = 28.274333882308138;
  c.setArea(new_area);
  EXPECT_NEAR(c.getArea(), new_area, EPS);
  EXPECT_NEAR(c.getRadius(), 3.0, EPS);
  EXPECT_NEAR(c.getFerence(), 6.0 * Pi(), EPS);
}

TEST(SetArea, Zero) {
  Circle c(5.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(SetArea, Negative) {
  Circle c(2.0);
  EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
  EXPECT_NEAR(c.getArea(), 4.0 * Pi(), EPS);
}

TEST(Getters, ConsistentValues) {
  Circle c(10.0);
  EXPECT_NEAR(c.getArea(), Pi() * 100.0, EPS);
  EXPECT_NEAR(c.getFerence(), 20.0 * Pi(), EPS);
  EXPECT_NEAR(c.getRadius(), 10.0, EPS);
}

TEST(SetRadius, Consistency) {
  Circle c(1.0);
  c.setRadius(7.0);
  EXPECT_NEAR(c.getArea() / Pi(), std::pow(c.getRadius(), 2), EPS);
  EXPECT_NEAR(c.getFerence(), 2.0 * Pi() * c.getRadius(), EPS);
}

TEST(SetFerence, Consistency) {
  Circle c(1.0);
  c.setFerence(4.0 * Pi());
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
  EXPECT_NEAR(c.getArea(), 4.0 * Pi(), EPS);
}

TEST(SetArea, Consistency) {
  Circle c(1.0);
  c.setArea(4.0 * Pi());
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
  EXPECT_NEAR(c.getFerence(), 4.0 * Pi(), EPS);
}

TEST(Setters, OrderIndependent) {
  Circle c(5.0);
  c.setArea(25.0 * Pi());
  c.setRadius(5.0);
  c.setFerence(10.0 * Pi());
  EXPECT_NEAR(c.getRadius(), 5.0, EPS);
  EXPECT_NEAR(c.getArea(), 25.0 * Pi(), EPS);
  EXPECT_NEAR(c.getFerence(), 10.0 * Pi(), EPS);
}

TEST(CircleConstructor, LowPrecision) {
  Circle c(0.000001);
  EXPECT_NEAR(c.getArea(), Pi() * 1e-12, EPS);
  EXPECT_NEAR(c.getFerence(), 2.0 * Pi() * 1e-6, EPS);
}

TEST(CircleConstructor, LargeRadius) {
  Circle c(10000.0);
  EXPECT_NEAR(c.getArea(), Pi() * 10000.0 * 10000.0, EPS);
  EXPECT_NEAR(c.getFerence(), 20000.0 * Pi(), EPS);
}

TEST(Getters, NoThrow) {
  Circle c(3.14);
  EXPECT_NO_THROW(c.getRadius());
  EXPECT_NO_THROW(c.getArea());
  EXPECT_NO_THROW(c.getFerence());
}

TEST(Tasks, EarthCordGapCorrect) {
  double gap = resolveEarthAndCordTask();
  EXPECT_NEAR(gap, 1.0 / (2.0 * Pi()), 1e-6);
}

TEST(Tasks, EarthCordPositiveGap) {
  double gap = resolveEarthAndCordTask();
  EXPECT_GT(gap, 0.0);
}

TEST(Tasks, PoolConcretePathAreaCorrect) {
  auto prices = resolvePoolTask();
  double expected_area = Pi() * (16.0 - 9.0);
  double expected_concrete_price = expected_area * 1000.0;
  EXPECT_NEAR(prices.first, expected_concrete_price, 1e-6);
}

TEST(Tasks, PoolFenceLengthCorrect) {
  auto prices = resolvePoolTask();
  double expected_fence_price = 2.0 * Pi() * 4.0 * 2000.0;
  EXPECT_NEAR(prices.second, expected_fence_price, 1e-6);
}

TEST(Tasks, PoolPricesPositive) {
  auto prices = resolvePoolTask();
  EXPECT_GT(prices.first, 0.0);
  EXPECT_GT(prices.second, 0.0);
}
