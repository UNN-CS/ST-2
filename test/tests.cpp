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
TEST(CircleTest, Test1Ference) {
    Circle c(-3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), -3.0);
}
TEST(CircleTest, Test2Ference) {
    Circle c(-1.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), -1.0);
}
TEST(CircleTest, Test3Ference) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}
TEST(CircleTest, Test4Ference) {
    Circle c(1.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 1.0);
}
TEST(CircleTest, Test5Ference) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 5.0);
}
