// Copyright 2024 Tushentsova Karina

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159;
const double EPS = 1e-6;

TEST(CircleTest, NegativeSetRadius1) {
    EXPECT_ANY_THROW(Circle(-10.0));
}
TEST(CircleTest, NegativeSetRadius2) {
    Circle c = Circle(5.0);
    EXPECT_ANY_THROW(c.setRadius(-3.0));
}
TEST(CircleTest, NullSetRadius1) {
    EXPECT_ANY_THROW(Circle(0.0));
}
TEST(CircleTest, NullSetRadius2) {
    Circle c = Circle(5.0);
    EXPECT_ANY_THROW(c.setRadius(0.0));
}
TEST(CircleTest, CorrectSetRadius) {
    Circle c = Circle(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
}

TEST(CircleTest, NegativeSetArea) {
    Circle c = Circle(5.0);
    EXPECT_ANY_THROW(c.setArea(-5.0));
}
TEST(CircleTest, NullSetArea) {
    Circle c = Circle(5.0);
    EXPECT_ANY_THROW(c.setArea(0.0));
}
TEST(CircleTest, CorrectSetArea) {
    Circle c = Circle(1.0);
    c.setArea(9 * PI);
    EXPECT_NEAR(c.getArea(), 9 * PI, EPS);
}

TEST(CircleTest, CorrectSetFerence) {
    Circle c = Circle(1.0);
    c.setFerence(9 * PI);
    EXPECT_NEAR(c.getFerence(), 9 * PI, EPS);
}

TEST(CircleTest, LargeSetRadius) {
    Circle c = Circle(1.0);
    c.setRadius(5000.0);
    EXPECT_NEAR(c.getRadius(), 5000.0, EPS);
}
TEST(CircleTest, LargeSetFerence) {
    Circle c = Circle(1.0);
    c.setFerence(5000.0);
    EXPECT_NEAR(c.getFerence(), 5000.0, EPS);
}
TEST(CircleTest, LargeSetArea) {
    Circle c = Circle(1.0);
    c.setArea(3000.0);
    EXPECT_NEAR(c.getArea(), 3000.0, EPS);
}

TEST(RopeTaskTest, NegativeLength) {
    EXPECT_THROW(ropeTask(-3.0), std::logic_error);
}
TEST(RopeTaskTest, NullLength) {
    EXPECT_NEAR(ropeTask(0.0), 0.0, EPS);
}
TEST(RopeTaskTest, CorrectLength) {
    EXPECT_NEAR(ropeTask(1.0), 1.0 / (2 * PI), EPS);
}

TEST(PoolTaskTest, PoolTask) {
    EXPECT_NEAR(
        poolTask(3.0, 1.0, 1000, 2000), 23000 * PI, EPS);
}
TEST(PoolTaskTest, NegativePoolRadius) {
    EXPECT_THROW(poolTask
    (-5.0, 1.0, 1000.0, 2000.0), std::logic_error);
}
TEST(PoolTaskTest, NullPoolRadius) {
    EXPECT_THROW(poolTask
    (0.0, 1.0, 1000.0, 2000.0), std::logic_error);
}
TEST(PoolTaskTest, NullPathWidth) {
    EXPECT_THROW(poolTask
    (5.0, 0.0, 1000.0, 2000.0), std::logic_error);
}
TEST(PoolTaskTest, NegativePathWidth) {
    EXPECT_THROW(poolTask
    (5.0, -2.0, 1000.0, 2000.0), std::logic_error);
}
