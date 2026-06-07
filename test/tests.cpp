// Copyright 2026 NNTU-CS
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

static const double PI = acos(-1.0);
static const double EPS = 1e-6;

// --- Circle: конструктор ---
TEST(CircleConstructor, RadiusIsSet) {
    Circle c(5.0);
    EXPECT_NEAR(5.0, c.getRadius(), EPS);
}
TEST(CircleConstructor, FerenceIsCorrect) {
    Circle c(5.0);
    EXPECT_NEAR(2.0 * PI * 5.0, c.getFerence(), EPS);
}
TEST(CircleConstructor, AreaIsCorrect) {
    Circle c(5.0);
    EXPECT_NEAR(PI * 25.0, c.getArea(), EPS);
}
TEST(CircleConstructor, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(0.0, c.getRadius(), EPS);
    EXPECT_NEAR(0.0, c.getFerence(), EPS);
    EXPECT_NEAR(0.0, c.getArea(), EPS);
}

// --- setRadius ---
TEST(SetRadius, UpdatesFerence) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(2.0 * PI * 10.0, c.getFerence(), EPS);
}
TEST(SetRadius, UpdatesArea) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(PI * 100.0, c.getArea(), EPS);
}

// --- setFerence ---
TEST(SetFerence, UpdatesRadius) {
    Circle c(0.0);
    c.setFerence(2.0 * PI * 7.0);
    EXPECT_NEAR(7.0, c.getRadius(), EPS);
}
TEST(SetFerence, UpdatesArea) {
    Circle c(0.0);
    c.setFerence(2.0 * PI * 7.0);
    EXPECT_NEAR(PI * 49.0, c.getArea(), EPS);
}

// --- setArea ---
TEST(SetArea, UpdatesRadius) {
    Circle c(0.0);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(3.0, c.getRadius(), EPS);
}
TEST(SetArea, UpdatesFerence) {
    Circle c(0.0);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(2.0 * PI * 3.0, c.getFerence(), EPS);
}

// --- Consistency checks ---
TEST(Consistency, SetRadiusThenGetAll) {
    Circle c(4.0);
    EXPECT_NEAR(4.0, c.getRadius(), EPS);
    EXPECT_NEAR(2.0 * PI * 4.0, c.getFerence(), EPS);
    EXPECT_NEAR(PI * 16.0, c.getArea(), EPS);
}
TEST(Consistency, SetFerenceThenGetAll) {
    Circle c(0.0);
    c.setFerence(2.0 * PI * 3.0);
    EXPECT_NEAR(3.0, c.getRadius(), EPS);
    EXPECT_NEAR(PI * 9.0, c.getArea(), EPS);
}
TEST(Consistency, SetAreaThenGetAll) {
    Circle c(0.0);
    c.setArea(PI * 4.0);
    EXPECT_NEAR(2.0, c.getRadius(), EPS);
    EXPECT_NEAR(2.0 * PI * 2.0, c.getFerence(), EPS);
}

// --- Rope gap ---
TEST(RopeGap, GapIsAboutSixteenCm) {
    // 1 / (2*PI) ≈ 0.159155 м
    EXPECT_NEAR(1.0 / (2.0 * PI), ropeGap(), 1e-4);
}
TEST(RopeGap, GapIsPositive) {
    EXPECT_GT(ropeGap(), 0.0);
}
TEST(RopeGap, GapIsIndependentOfRadius) {
    // зазор всегда ~0.159 м независимо от радиуса земли
    EXPECT_NEAR(0.159155, ropeGap(), 1e-4);
}

// --- Pool ---
TEST(Pool, ConcreteCostIsPositive) {
    EXPECT_GT(poolConcreteCost(), 0.0);
}
TEST(Pool, FenceCostIsPositive) {
    EXPECT_GT(poolFenceCost(), 0.0);
}
TEST(Pool, ConcreteCostValue) {
    // площадь кольца = PI*(4^2 - 3^2) = 7*PI, стоимость = 7*PI*1000
    EXPECT_NEAR(7.0 * PI * 1000.0, poolConcreteCost(), 1e-3);
}
TEST(Pool, FenceCostValue) {
    // периметр внешней окружности = 2*PI*4, стоимость = 2*PI*4*2000
    EXPECT_NEAR(2.0 * PI * 4.0 * 2000.0, poolFenceCost(), 1e-3);
}
