// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "task.h"
// Тесты для класса Circle
TEST(CircleTest, Test1Radius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}
TEST(CircleTest, Test2Radius) {
    Circle c(4.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
}
TEST(CircleTest, Test3Radius) {
    Circle c(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
}
TEST(CircleTest, Test4Radius) {
    Circle c(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
}
TEST(CircleTest, Test5Radius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}
TEST(CircleTest, Test6Radius) {
    Circle c(1.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
}
TEST(CircleTest, Test7Radius) {
    Circle c(-1.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -1.0);
}
TEST(CircleTest, Test8Radius) {
    Circle c(-2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -2.0);
}
TEST(CircleTest, Test9Radius) {
    Circle c(6.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 6.0);
}
TEST(CircleTest, Test10Radius) {
    Circle c(-3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -3.0);
}
TEST(PoolTest, ZeroRadius) {
  double cost = calculatePoolCost(0, 5, 500, 1500);
  double expectedCost = (PI * 5 * 5 * 500) + (2 * PI * 5 * 1500);
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}
TEST(PoolTest, ZeroConstructionCost) {
  double cost = calculatePoolCost(10, 5, 0, 1500);
  double expectedCost = 2 * PI * 15 * 1500;
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}
TEST(PoolTest, ZeroBorderCost) {
  double cost = calculatePoolCost(10, 5, 1000, 0);
  double expectedCost = PI * (15 * 15 - 10 * 10) * 1000;
  EXPECT_NEAR(cost, expectedCost, 1e-6);
}
TEST(GapTest, SmallEarthRadius) {
    double gap = calculateGap(1.0, 0.1);
    ASSERT_NEAR(gap, 0.015915494309189535, 1e-12);
}
TEST(GapTest, EarthAndRope) {
    double gap = calculateGap(6378.1 * 1000, 1);
    ASSERT_NEAR(gap, 0.15915494309, 1e-6);
}
TEST(CircleTest, SR5) {
    Circle c(100.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 100.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 100.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 100.0 * 100.0);
}
TEST(CircleTest, SR4) {
    Circle c(0.01);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.01);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 0.01);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 0.01 * 0.01);
}
TEST(CircleTest, SR3) {
    Circle c(0.05);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.05);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 0.05);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 0.05 * 0.05);
}
TEST(CircleTest, SR2) {
    Circle c(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 10.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 10.0 * 10.0);
}
TEST(CircleTest, SR1) {
    Circle c(150.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 150.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 150.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 150.0 * 150.0);
}
