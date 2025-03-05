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
TEST(CircleTest, TestSetFerencePositive) {
    Circle c(0.0);
    c.setFerence(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0 / (2 * M_PI));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * (c.getRadius() * c.getRadius()));
}
TEST(CircleTest, TestSetFerenceZero) {
    Circle c(0.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}
TEST(CircleTest, TestSetFerenceNegative) {
    Circle c(0.0);
    c.setFerence(-10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -10.0 / (2 * M_PI));
}
TEST(CircleTest, TestSetFerenceLargeValue) {
    Circle c(0.0);
    c.setFerence(1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6 / (2 * M_PI));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * (c.getRadius() * c.getRadius()));
}
TEST(CircleTest, TestSetFerenceSmallPositive) {
    Circle c(0.0);
    c.setFerence(0.1);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.1 / (2 * M_PI));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * (c.getRadius() * c.getRadius()));
}
TEST(CircleTest, TestSetFerenceVerySmallPositive) {
    Circle c(0.0);
    c.setFerence(1e-10);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e-10 / (2 * M_PI));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * (c.getRadius() * c.getRadius()));
}
TEST(CircleTest, TestSetFerenceMaxDouble) {
    Circle c(0.0);
    c.setFerence(DBL_MAX);
    EXPECT_DOUBLE_EQ(c.getRadius(), DBL_MAX / (2 * M_PI));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * (c.getRadius() * c.getRadius()));
}
TEST(CircleTest, TestSetFerenceMinDouble) {
    Circle c(0.0);
    c.setFerence(DBL_MIN);
    EXPECT_DOUBLE_EQ(c.getRadius(), DBL_MIN / (2 * M_PI));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * (c.getRadius() * c.getRadius()));
}
TEST(CircleTest, TestSetFerenceChangeValue) {
    Circle c(0.0);
    c.setFerence(20.0);
    double initialArea = c.getArea();
    c.setFerence(30.0);
    EXPECT_NE(c.getArea(), initialArea);
}
TEST(CircleTest, TestSetFerenceReuseObject) {
    Circle c(0.0);
    c.setFerence(15.0);
    double radius1 = c.getRadius();
    c.setFerence(25.0);
    double radius2 = c.getRadius();
    EXPECT_NE(radius1, radius2);
}
