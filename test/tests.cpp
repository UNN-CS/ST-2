// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>
#include "circle.h"
#include "tasks.h"

static const double kEps = 1e-5;
static const double kPi = 3.14159265358979323846;

// ========== Circle: конструктор ==========

TEST(CircleConstructor, DefaultIsZero) {
    Circle c;
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleConstructor, RadiusOne) {
    Circle c(1.0);
    EXPECT_NEAR(c.getRadius(), 1.0, kEps);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi, kEps);
    EXPECT_NEAR(c.getArea(), kPi, kEps);
}

TEST(CircleConstructor, RadiusTen) {
    Circle c(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, kEps);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 10.0, kEps);
    EXPECT_NEAR(c.getArea(), kPi * 100.0, kEps);
}

TEST(CircleConstructor, NegativeThrows) {
    EXPECT_THROW(Circle(-3.0), std::invalid_argument);
}

// ========== Circle: setRadius ==========

TEST(CircleSetRadius, UpdatesAll) {
    Circle c(2.0);
    c.setRadius(7.0);
    EXPECT_NEAR(c.getRadius(), 7.0, kEps);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 7.0, kEps);
    EXPECT_NEAR(c.getArea(), kPi * 49.0, kEps);
}

TEST(CircleSetRadius, ToZeroClearsAll) {
    Circle c(4.0);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleSetRadius, NegativeThrowsStateUnchanged) {
    Circle c(3.0);
    EXPECT_THROW(c.setRadius(-2.0), std::invalid_argument);
    EXPECT_NEAR(c.getRadius(), 3.0, kEps);
}

// ========== Circle: setFerence ==========

TEST(CircleSetFerence, UpdatesAll) {
    Circle c(1.0);
    c.setFerence(2.0 * kPi * 6.0);
    EXPECT_NEAR(c.getRadius(), 6.0, kEps);
    EXPECT_NEAR(c.getArea(), kPi * 36.0, kEps);
}

TEST(CircleSetFerence, ToZeroClearsAll) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(CircleSetFerence, NegativeThrowsStateUnchanged) {
    Circle c(2.0);
    double prevF = c.getFerence();
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
    EXPECT_NEAR(c.getFerence(), prevF, kEps);
}

// ========== Circle: setArea ==========

TEST(CircleSetArea, UpdatesAll) {
    Circle c(1.0);
    c.setArea(kPi * 9.0);
    EXPECT_NEAR(c.getRadius(), 3.0, kEps);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 3.0, kEps);
    EXPECT_NEAR(c.getArea(), kPi * 9.0, kEps);
}

TEST(CircleSetArea, ToZeroClearsAll) {
    Circle c(8.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, kEps);
    EXPECT_NEAR(c.getFerence(), 0.0, kEps);
}

TEST(CircleSetArea, NegativeThrowsStateUnchanged) {
    Circle c(4.0);
    double prevA = c.getArea();
    EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
    EXPECT_NEAR(c.getArea(), prevA, kEps);
}

// ========== Circle: согласованность ==========

TEST(CircleConsistency, SetFerenceThenCheckArea) {
    Circle c(1.0);
    c.setFerence(20.0);
    double r = 20.0 / (2.0 * kPi);
    EXPECT_NEAR(c.getArea(), kPi * r * r, kEps);
}

TEST(CircleConsistency, SetAreaThenCheckFerence) {
    Circle c(1.0);
    c.setArea(50.0);
    double r = std::sqrt(50.0 / kPi);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi * r, kEps);
}

TEST(CircleConsistency, ChainedSetsKeepLast) {
    Circle c(1.0);
    c.setRadius(5.0);
    c.setArea(kPi * 4.0);
    EXPECT_NEAR(c.getRadius(), 2.0, kEps);
    EXPECT_NEAR(c.getFerence(), 2.0 * kPi * 2.0, kEps);
}

// ========== Задача "Верёвка" ==========

TEST(EarthRope, ResultIsPositive) {
    EXPECT_GT(solveEarthRopeTask(), 0.0);
}

TEST(EarthRope, IndependentOfEarthRadius) {
    // зазор = 1 / (2*PI) — не зависит от радиуса Земли
    EXPECT_NEAR(solveEarthRopeTask(), 1.0 / (2.0 * kPi), kEps);
}

TEST(EarthRope, ApproxValue) {
    EXPECT_NEAR(solveEarthRopeTask(), 0.15915, 1e-4);
}

// ========== Задача "Бассейн" ==========

TEST(Pool, ConcreteCostIsPositive) {
    EXPECT_GT(solvePoolTask().concrete_cost, 0.0);
}

TEST(Pool, FenceCostIsPositive) {
    EXPECT_GT(solvePoolTask().fence_cost, 0.0);
}

TEST(Pool, ConcreteCostMatchesPathArea) {
    PoolCosts costs = solvePoolTask();
    Circle inner(3.0);
    Circle outer(4.0);
    double expectedArea = outer.getArea() - inner.getArea();
    EXPECT_NEAR(costs.concrete_cost / 1000.0, expectedArea, kEps);
}

TEST(Pool, FenceCostMatchesOuterCircle) {
    PoolCosts costs = solvePoolTask();
    Circle outer(4.0);
    EXPECT_NEAR(costs.fence_cost / 2000.0, outer.getFerence(), kEps);
}

TEST(Pool, AbsoluteValues) {
    PoolCosts costs = solvePoolTask();
    EXPECT_NEAR(costs.concrete_cost, 21991.1, 1.0);
    EXPECT_NEAR(costs.fence_cost, 50265.5, 1.0);
}

// Итого: 28 тестов
