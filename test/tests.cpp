// Copyright 2024 Daria Sokolova
#include <gtest/gtest.h>
#include <cstdint>
#include "tasks.h"
#include "circle.h"

const double PI = 3.14159;
const double EPS = 1e-6;

TEST(CircleTest, SetNegativeRadius) {
    EXPECT_ANY_THROW(Circle(-2.0));
}
TEST(CircleTest, SetNullRadius) {
    EXPECT_ANY_THROW(Circle(0.0));
}
TEST(CircleTest, SetFerence) {
    Circle c = Circle(1.0);
    c.setFerence(9 * PI);
    EXPECT_NEAR(c.getRadius(), 4.5, EPS);
    EXPECT_NEAR(c.getArea(), 4.5*4.5 * PI, EPS);
    EXPECT_NEAR(c.getFerence(), 9 * PI, EPS);
}
TEST(CircleTest, setPositiveRadius) {
    Circle c = Circle(2.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getArea(), 9 * PI, EPS);
    EXPECT_NEAR(c.getFerence(), 6 * PI, EPS);
}
TEST(CircleTest, setNullRadius) {
    Circle c = Circle(2.0);
    EXPECT_ANY_THROW(c.setRadius(0.0));
}
TEST(CircleTest, setNegativeRadius) {
    Circle c = Circle(2.0);
    EXPECT_ANY_THROW(c.setRadius(-3.0));
}
TEST(CircleTest, setPositiveArea) {
    Circle c = Circle(1.0);
    c.setArea(9 * PI);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getArea(), 9 * PI, EPS);
    EXPECT_NEAR(c.getFerence(), 6 * PI, EPS);
}
TEST(CircleTest, setNullArea) {
    Circle c = Circle(5.0);
    EXPECT_ANY_THROW(c.setArea(0.0));
}
TEST(CircleTest, setNegativeArea) {
    Circle c = Circle(5.0);
    EXPECT_ANY_THROW(c.setArea(-5.0));
}
TEST(CircleTest, setLargeRadius) {
    Circle c = Circle(1.0);
    c.setRadius(3000.0);
    EXPECT_NEAR(c.getRadius(), 3000.0, EPS);
    EXPECT_NEAR(c.getArea(), 3000 * 3000 * PI, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * 3000 * PI, EPS);
}
TEST(CircleTest, setLargeFerence) {
    Circle c = Circle(1.0);
    c.setFerence(3000.0);
    EXPECT_NEAR(c.getFerence(), 3000.0, EPS);
    EXPECT_NEAR(c.getRadius(), 3000 / (2 * PI), EPS);
    EXPECT_NEAR(c.getArea(), 3000 * (3000 / (2 * PI)) / 2, EPS);
}
TEST(CircleTest, setLargeArea) {
    Circle c = Circle(1.0);
    c.setArea(1000.0);
    EXPECT_NEAR(c.getArea(), 1000.0, EPS);
    EXPECT_NEAR(c.getRadius(), sqrt(1000.0 / PI), EPS);
    EXPECT_NEAR(c.getFerence(), sqrt(1000.0 / PI) * 2 * PI, EPS);
}
TEST(RopeTaskTest, NegativeAddedLength) {
    EXPECT_THROW(ropeTask(-1.0), std::logic_error);
}
TEST(RopeTaskTest, NullAddedLength) {
    EXPECT_NEAR(ropeTask(0.0), 0.0, EPS);
}
TEST(RopeTaskTest, PositiveAddedLength) {
    EXPECT_NEAR(ropeTask(1.0), 1.0/(2*PI), EPS);
}
TEST(SwimmingPoolTaskTest, PoolTask) {
    EXPECT_NEAR(
        swimmingPoolTask(3.0, 1.0, 1000, 2000),
        23000 * PI,
        EPS);
}
TEST(SwimmingPoolTaskTest, NegativePoolRadius) {
    EXPECT_THROW(swimmingPoolTask
    (-5.0, 1.0, 1000.0, 2000.0), std::logic_error);
}
TEST(SwimmingPoolTaskTest, NullPoolRadius) {
    EXPECT_THROW(swimmingPoolTask
    (0.0, 1.0, 1000.0, 2000.0), std::logic_error);
}
TEST(SwimmingPoolTaskTest, NullPathWidth) {
    EXPECT_THROW(swimmingPoolTask
    (5.0, 0.0, 1000.0, 2000.0), std::logic_error);
}
TEST(SwimmingPoolTaskTest, NegativePathWidth) {
    EXPECT_THROW(swimmingPoolTask
    (5.0, -2.0, 1000.0, 2000.0), std::logic_error);
}
