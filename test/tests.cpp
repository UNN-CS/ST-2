// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double EPS = 1e-9;

// === Тесты конструктора ===
TEST(CircleTest, ConstructorWithZero) {
  Circle c(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, ConstructorWithPositiveRadius) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5.0, EPS);
  EXPECT_NEAR(c.getArea(), M_PI * 25.0, EPS);
}

TEST(CircleTest, ConstructorWithRadiusOne) {
  Circle c(1.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI, EPS);
  EXPECT_NEAR(c.getArea(), M_PI, EPS);
}

// === Тесты setRadius ===
TEST(CircleTest, SetRadiusUpdatesAllFields) {
  Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 10.0, EPS);
  EXPECT_NEAR(c.getArea(), M_PI * 100.0, EPS);
}

TEST(CircleTest, SetRadiusToZero) {
  Circle c(5.0);
  c.setRadius(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

// === Тесты setFerence ===
TEST(CircleTest, SetFerenceUpdatesAllFields) {
  Circle c(1.0);
  double ference = 2 * M_PI * 7.0;
  c.setFerence(ference);
  EXPECT_NEAR(c.getRadius(), 7.0, EPS);
  EXPECT_NEAR(c.getFerence(), ference, EPS);
  EXPECT_NEAR(c.getArea(), M_PI * 49.0, EPS);
}

TEST(CircleTest, SetFerenceFromZero) {
  Circle c(5.0);
  c.setFerence(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

// === Тесты setArea ===
TEST(CircleTest, SetAreaUpdatesAllFields) {
  Circle c(1.0);
  double area = M_PI * 9.0;  // r=3
  c.setArea(area);
  EXPECT_NEAR(c.getRadius(), 3.0, EPS);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 3.0, EPS);
  EXPECT_NEAR(c.getArea(), area, EPS);
}

TEST(CircleTest, SetAreaFromZero) {
  Circle c(5.0);
  c.setArea(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

// === Тесты согласованности (setX -> getY, getZ) ===
TEST(CircleTest, SetRadiusThenGetFerenceAndArea) {
  Circle c;
  c.setRadius(3.0);
  EXPECT_NEAR(c.getFerence(), 6 * M_PI, EPS);
  EXPECT_NEAR(c.getArea(), 9 * M_PI, EPS);
}

TEST(CircleTest, SetFerenceThenGetRadiusAndArea) {
  Circle c;
  c.setFerence(4 * M_PI);  // r=2
  EXPECT_NEAR(c.getRadius(), 2.0, EPS);
  EXPECT_NEAR(c.getArea(), 4 * M_PI, EPS);
}

TEST(CircleTest, SetAreaThenGetRadiusAndFerence) {
  Circle c;
  c.setArea(16 * M_PI);  // r=4
  EXPECT_NEAR(c.getRadius(), 4.0, EPS);
  EXPECT_NEAR(c.getFerence(), 8 * M_PI, EPS);
}

// === Тесты цепочки вызовов ===
TEST(CircleTest, ChainSetRadiusSetFerenceSetArea) {
  Circle c(1.0);
  c.setRadius(2.0);
  c.setFerence(2 * M_PI * 3.0);
  c.setArea(M_PI * 4.0 * 4.0);
  EXPECT_NEAR(c.getRadius(), 4.0, EPS);
  EXPECT_NEAR(c.getFerence(), 8 * M_PI, EPS);
  EXPECT_NEAR(c.getArea(), 16 * M_PI, EPS);
}

// === Тесты задачи "Верёвка" ===
TEST(RopeTaskTest, GapIsPositive) {
  double gap = ropeTask();
  EXPECT_GT(gap, 0);
}

TEST(RopeTaskTest, GapApproximatelyOneOverTwoPi) {
  double gap = ropeTask();
  double expected = 1.0 / (2 * M_PI);
  EXPECT_NEAR(gap, expected, 1e-6);
}

TEST(RopeTaskTest, GapValue) {
  double gap = ropeTask();
  EXPECT_NEAR(gap, 0.15915494309189535, 1e-6);
}

// === Тесты задачи "Бассейн" ===
TEST(PoolTaskTest, ConcreteCostPositive) {
  double cost = poolConcreteCost();
  EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, ConcreteCostCorrect) {
  double cost = poolConcreteCost();
  double pathArea = M_PI * (4 * 4 - 3 * 3);  // 7*pi
  double expected = pathArea * 1000;
  EXPECT_NEAR(cost, expected, 0.01);
}

TEST(PoolTaskTest, FenceCostPositive) {
  double cost = poolFenceCost();
  EXPECT_GT(cost, 0);
}

TEST(PoolTaskTest, FenceCostCorrect) {
  double cost = poolFenceCost();
  double fenceLength = 2 * M_PI * 4;  // outer radius 4m
  double expected = fenceLength * 2000;
  EXPECT_NEAR(cost, expected, 0.01);
}

TEST(PoolTaskTest, ConcreteCostApprox21991) {
  double cost = poolConcreteCost();
  EXPECT_NEAR(cost, 21991.148, 1.0);
}

TEST(PoolTaskTest, FenceCostApprox50260) {
  double cost = poolFenceCost();
  EXPECT_NEAR(cost, 50265.48, 1.0);
}
