// Copyright 2026 UNN-CS
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

static constexpr double EPS = 1e-6;
static constexpr double PI = 3.14159265358979323846;

// ----------------------
// Тесты конструктора
// ----------------------

TEST(CircleTest, ConstructorCorrectRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleTest, ConstructorCorrectFerence) {
    Circle c(5.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 5.0, EPS);
}

TEST(CircleTest, ConstructorCorrectArea) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(CircleTest, ConstructorThrowsOnZero) {
    EXPECT_THROW(Circle c(0.0), std::invalid_argument);
}

TEST(CircleTest, ConstructorThrowsOnNegative) {
    EXPECT_THROW(Circle c(-3.0), std::invalid_argument);
}

// ----------------------
// setRadius
// ----------------------

TEST(CircleTest, SetRadiusChangesRadius) {
    Circle c(2.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
}

TEST(CircleTest, SetRadiusRecalculatesFerence) {
    Circle c(2.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 4.0, EPS);
}

TEST(CircleTest, SetRadiusRecalculatesArea) {
    Circle c(2.0);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getArea(), PI * 16.0, EPS);
}

TEST(CircleTest, SetRadiusThrowsOnNegative) {
    Circle c(2.0);
    EXPECT_THROW(c.setRadius(-1.0), std::invalid_argument);
}

// ----------------------
// setFerence
// ----------------------

TEST(CircleTest, SetFerenceRecalculatesRadius) {
    Circle c(1.0);
    c.setFerence(2.0 * PI * 3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
}

TEST(CircleTest, SetFerenceRecalculatesArea) {
    Circle c(1.0);
    c.setFerence(2.0 * PI * 3.0);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleTest, SetFerenceThrowsOnNegative) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
}

// ----------------------
// setArea
// ----------------------

TEST(CircleTest, SetAreaRecalculatesRadius) {
    Circle c(1.0);
    c.setArea(PI * 16.0);
    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
}

TEST(CircleTest, SetAreaRecalculatesFerence) {
    Circle c(1.0);
    c.setArea(PI * 16.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 4.0, EPS);
}

TEST(CircleTest, SetAreaThrowsOnNegative) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-5.0), std::invalid_argument);
}

// ----------------------
// Согласованность данных
// ----------------------

TEST(CircleTest, ConsistencyAfterMultipleChanges) {
    Circle c(3.0);
    c.setFerence(2.0 * PI * 10.0);
    c.setArea(PI * 25.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

// ----------------------
// Задача Земля и верёвка
// ----------------------

TEST(TasksTest, EarthRopeGapIsCorrect) {
    double gap = earthRopeGap();
    EXPECT_NEAR(gap, 1.0 / (2.0 * PI), EPS);
}

// ----------------------
// Задача Бассейн
// ----------------------

TEST(TasksTest, PoolConcreteAreaCorrect) {
    double area = poolConcreteArea();
    double expected = PI * 16.0 - PI * 9.0;
    EXPECT_NEAR(area, expected, EPS);
}

TEST(TasksTest, PoolConcreteCostCorrect) {
    double cost = poolConcreteCost();
    double expectedArea = PI * 16.0 - PI * 9.0;
    EXPECT_NEAR(cost, expectedArea * 1000.0, EPS);
}

TEST(TasksTest, PoolFenceLengthCorrect) {
    double length = poolFenceLength();
    EXPECT_NEAR(length, 2.0 * PI * 4.0, EPS);
}

TEST(TasksTest, PoolFenceCostCorrect) {
    double cost = poolFenceCost();
    EXPECT_NEAR(cost, 2.0 * PI * 4.0 * 2000.0, EPS);
}
