// Copyright 2025 UNN-CS Team

#define _USE_MATH_DEFINES

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, Initialization1) {
 Circle c(5);
 EXPECT_NEAR(c.getRadius(), 5, 1e-6);
}
TEST(CircleTest, Initialization2) {
 Circle c(5);
 EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5, 1e-6);
}
TEST(CircleTest, Initialization3) {
 Circle c(5);
 EXPECT_NEAR(c.getArea(), M_PI * 25, 1e-6);
}
TEST(CircleTest, Initialization4) {
 Circle c(6);
 EXPECT_NEAR(c.getRadius(), 6, 1e-6);
}
TEST(CircleTest, Initialization5) {
 Circle c(10);
 EXPECT_NEAR(c.getRadius(), 10, 1e-6);
}
TEST(CircleTest, Initialization6) {
 Circle c(100);
 EXPECT_NEAR(c.getRadius(), 100, 1e-6);
}
TEST(CircleTest, SetRadius1) {
 Circle c(5);
 c.setRadius(10);
 EXPECT_NEAR(c.getRadius(), 10, 1e-6);
}
TEST(CircleTest, SetRadius2) {
 Circle c(5);
 c.setRadius(10);
 EXPECT_NEAR(c.getFerence(), 2 * M_PI * 10, 1e-6);
}
TEST(CircleTest, SetRadius3) {
 Circle c(5);
 c.setRadius(10);
 EXPECT_NEAR(c.getArea(), M_PI * 100, 1e-6);
}
TEST(CircleTest, SetRadius4) {
 Circle c(5);
 c.setRadius(100);
 EXPECT_NEAR(c.getRadius(), 100, 1e-6);
}
TEST(CircleTest, SetRadius5) {
 Circle c(5);
 c.setRadius(200);
 EXPECT_NEAR(c.getRadius(), 200, 1e-6);
}
TEST(CircleTest, SetRadius6) {
 Circle c(5);
 c.setRadius(1000);
 EXPECT_NEAR(c.getRadius(), 1000, 1e-6);
}
TEST(CircleTest, SetFerence1) {
 Circle c(5);
 c.setFerence(2 * M_PI * 15);
 EXPECT_NEAR(c.getRadius(), 15, 1e-6);
}
TEST(CircleTest, SetFerence2) {
 Circle c(5);
 c.setFerence(2 * M_PI * 15);
 EXPECT_NEAR(c.getFerence(), 2 * M_PI * 15, 1e-6);
}
TEST(CircleTest, SetFerence3) {
 Circle c(5);
 c.setFerence(2 * M_PI * 15);
 EXPECT_NEAR(c.getArea(), M_PI * 225, 1e-6);
}
TEST(CircleTest, SetFerence4) {
 Circle c(5);
 c.setFerence(2 * M_PI * 40);
 EXPECT_NEAR(c.getRadius(), 40, 1e-6);
}
TEST(CircleTest, SetArea1) {
 Circle c(5);
 c.setArea(M_PI * 400);
 EXPECT_NEAR(c.getRadius(), 20, 1e-6);
}
TEST(CircleTest, SetArea2) {
 Circle c(5);
 c.setArea(M_PI * 400);
 EXPECT_NEAR(c.getFerence(), 2 * M_PI * 20, 1e-6);
}
TEST(CircleTest, SetArea3) {
 Circle c(5);
 c.setArea(M_PI * 400);
 EXPECT_NEAR(c.getArea(), M_PI * 400, 1e-6);
}
TEST(EarthRopeTest, CalculateGap) {
 double gap = calculateGap();
 EXPECT_NEAR(gap, 0.159, 1e-3);
}
TEST(PoolTest, CalculatePoolCost) {
 double cost = calculatePoolCost();
 double expectedCost = (M_PI * (16 - 9) * 1000 + 2 * M_PI * 4 * 2000);
 EXPECT_NEAR(cost, expectedCost, 1e-6);
}
