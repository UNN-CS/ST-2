// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.1415;
const double EPS = 1e-6;

TEST(CircleTest, Constructor_ZeroRadius) {
  Circle c(0);
  EXPECT_NEAR(c.getRadius(), 0, EPS);
  EXPECT_NEAR(c.getArea(), 0, EPS);
  EXPECT_NEAR(c.getFerence(), 0, EPS);
}

TEST(CircleTest, Constructor_PositiveRadius) {
  Circle c(2);
  EXPECT_NEAR(c.getRadius(), 2, EPS);
  EXPECT_NEAR(c.getArea(), PI * 4, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI * 2, EPS);
}

TEST(CircleTest, SetRadius_One) {
  Circle c(0);
  c.setRadius(1);
  EXPECT_NEAR(c.getArea(), PI, EPS);
}

TEST(CircleTest, SetRadius_Ten) {
  Circle c(0);
  c.setRadius(10);
  EXPECT_NEAR(c.getFerence(), 2 * PI * 10, EPS);
}

TEST(CircleTest, SetRadius_Fraction) {
  Circle c(0);
  c.setRadius(2.5);
  EXPECT_NEAR(c.getArea(), PI * 2.5 * 2.5, EPS);
}

TEST(CircleTest, SetFerence_Basic) {
  Circle c(0);
  c.setFerence(2 * PI);
  EXPECT_NEAR(c.getRadius(), 1, EPS);
}

TEST(CircleTest, SetFerence_Zero) {
  Circle c(1);
  c.setFerence(0);
  EXPECT_NEAR(c.getRadius(), 0, EPS);
}

TEST(CircleTest, SetFerence_Large) {
  Circle c(0);
  c.setFerence(100);
  EXPECT_NEAR(c.getRadius(), 100 / (2 * PI), EPS);
}

TEST(CircleTest, SetArea_One) {
  Circle c(0);
  c.setArea(PI);
  EXPECT_NEAR(c.getRadius(), 1, EPS);
}

TEST(CircleTest, SetArea_Zero) {
  Circle c(1);
  c.setArea(0);
  EXPECT_NEAR(c.getRadius(), 0, EPS);
}

TEST(CircleTest, SetArea_Large) {
  Circle c(0);
  c.setArea(100);
  EXPECT_NEAR(c.getRadius(), std::sqrt(100 / PI), EPS);
}

TEST(CircleTest, Consistency_RadiusToAreaToRadius) {
  Circle c(5);
  double area = c.getArea();
  c.setArea(area);
  EXPECT_NEAR(c.getRadius(), 5, EPS);
}

TEST(CircleTest, Consistency_RadiusToFerenceToRadius) {
  Circle c(7);
  double f = c.getFerence();
  c.setFerence(f);
  EXPECT_NEAR(c.getRadius(), 7, EPS);
}

TEST(CircleTest, Consistency_AreaToFerence) {
  Circle c(0);
  c.setArea(PI * 9);
  EXPECT_NEAR(c.getFerence(), 2 * PI * 3, EPS);
}

TEST(CircleTest, Getters_WorkCorrectly) {
  Circle c(3);
  EXPECT_NEAR(c.getRadius(), 3, EPS);
  EXPECT_NEAR(c.getArea(), PI * 9, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * PI * 3, EPS);
}

TEST(RopeGapTest, EarthRadius6371) {
  double gap = ropeGap(6371);
  EXPECT_NEAR(gap, 1.0 / (2 * PI), EPS);
}

TEST(RopeGapTest, SmallRadius) {
  double gap = ropeGap(1);
  EXPECT_NEAR(gap, 1.0 / (2 * PI), EPS);
}

TEST(RopeGapTest, ZeroRadius) {
  double gap = ropeGap(0);
  EXPECT_NEAR(gap, 1.0 / (2 * PI), EPS);
}

TEST(PoolConcreteTest, ZeroWidth) {
  EXPECT_NEAR(poolConcreteCost(10, 0, 100), 0, EPS);
}

TEST(PoolConcreteTest, BasicCase) {
  double result = poolConcreteCost(10, 1, 100);
  double expected = (PI * 11 * 11 - PI * 10 * 10) * 100;
  EXPECT_NEAR(result, expected, EPS);
}

TEST(PoolConcreteTest, LargeValues) {
  double result = poolConcreteCost(100, 10, 50);
  double expected = (PI * 110 * 110 - PI * 100 * 100) * 50;
  EXPECT_NEAR(result, expected, EPS);
}

TEST(PoolConcreteTest, Fractional) {
  double result = poolConcreteCost(2.5, 0.5, 200);
  double expected = (PI * 3.0 * 3.0 - PI * 2.5 * 2.5) * 200;
  EXPECT_NEAR(result, expected, EPS);
}

TEST(PoolFenceTest, BasicCase) {
  double result = poolFenceCost(10, 1, 50);
  double expected = 2 * PI * 11 * 50;
  EXPECT_NEAR(result, expected, EPS);
}

TEST(PoolFenceTest, ZeroWidth) {
  double result = poolFenceCost(10, 0, 50);
  EXPECT_NEAR(result, 2 * PI * 10 * 50, EPS);
}

TEST(PoolFenceTest, LargeValues) {
  double result = poolFenceCost(100, 10, 20);
  double expected = 2 * PI * 110 * 20;
  EXPECT_NEAR(result, expected, EPS);
}

TEST(PoolTotalTest, BasicCase) {
  double total = poolTotalCost(10, 1, 100, 50);
  double expected =
    poolConcreteCost(10, 1, 100) +
    poolFenceCost(10, 1, 50);
  EXPECT_NEAR(total, expected, EPS);
}

TEST(PoolTotalTest, ZeroWidth) {
  double total = poolTotalCost(10, 0, 100, 50);
  double expected = poolFenceCost(10, 0, 50);
  EXPECT_NEAR(total, expected, EPS);
}

TEST(PoolTotalTest, LargeValues) {
  double total = poolTotalCost(100, 20, 30, 10);
  double expected =
    poolConcreteCost(100, 20, 30) +
    poolFenceCost(100, 20, 10);
  EXPECT_NEAR(total, expected, EPS);
}

TEST(PoolTotalTest, FractionalValues) {
  double total = poolTotalCost(5.5, 1.5, 120.5, 60.3);
  double expected =
    poolConcreteCost(5.5, 1.5, 120.5) +
    poolFenceCost(5.5, 1.5, 60.3);
  EXPECT_NEAR(total, expected, EPS);
}
