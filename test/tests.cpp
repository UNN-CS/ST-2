// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "../include/circle.h"
#include "../include/tasks.h"

constexpr double EPSILON = 1e-6;

TEST(CircleTest, ConstructorAndGetRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPSILON);
}

TEST(CircleTest, GetFerenceAndArea) {
    Circle c(2.0);
    double expectedFerence = 2 * 3.14159265358979323846 * 2.0;
    double expectedArea = 3.14159265358979323846 * 2.0 * 2.0;
    EXPECT_NEAR(c.getFerence(), expectedFerence, EPSILON);
    EXPECT_NEAR(c.getArea(), expectedArea, EPSILON);
}

TEST(CircleTest, SetRadiusUpdatesValues) {
    Circle c(1.0);
    c.setRadius(4.0);
    double expectedFerence = 2 * 3.14159265358979323846 * 4.0;
    double expectedArea = 3.14159265358979323846 * 4.0 * 4.0;
    EXPECT_NEAR(c.getRadius(), 4.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), expectedFerence, EPSILON);
    EXPECT_NEAR(c.getArea(), expectedArea, EPSILON);
}

TEST(CircleTest, SetFerenceUpdatesValues) {
    Circle c(1.0);
    double newFerence = 15.707963; 
    c.setFerence(newFerence);
    double expectedRadius = newFerence / (2 * 3.14159265358979323846);
    double expectedArea = 3.14159265358979323846 * expectedRadius * expectedRadius;
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPSILON);
    EXPECT_NEAR(c.getFerence(), newFerence, EPSILON);
    EXPECT_NEAR(c.getArea(), expectedArea, EPSILON);
}

TEST(CircleTest, SetAreaUpdatesValues) {
    Circle c(1.0);
    double newArea = 50.265482; 
    c.setArea(newArea);
    double expectedRadius = std::sqrt(newArea / 3.14159265358979323846);
    double expectedFerence = 2 * 3.14159265358979323846 * expectedRadius;
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPSILON);
    EXPECT_NEAR(c.getArea(), newArea, EPSILON);
    EXPECT_NEAR(c.getFerence(), expectedFerence, EPSILON);
}

TEST(CircleTest, SequentialUpdates) {
    Circle c(3.0);
    c.setRadius(6.0);
    double newFerence = c.getFerence();
    c.setFerence(newFerence);
    double newArea = c.getArea();
    c.setArea(newArea);
    EXPECT_NEAR(c.getRadius(), 6.0, EPSILON);
}

TEST(CircleTest, IdenticalCircles) {
    Circle c1(10.0);
    Circle c2(10.0);
    EXPECT_NEAR(c1.getFerence(), c2.getFerence(), EPSILON);
    EXPECT_NEAR(c1.getArea(), c2.getArea(), EPSILON);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0.0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0.0, EPSILON);
}

TEST(CircleTest, NegativeRadius) {
    Circle c(-5.0);
    EXPECT_NEAR(c.getRadius(), -5.0, EPSILON);
    double expectedFerence = 2 * 3.14159265358979323846 * (-5.0);
    double expectedArea = 3.14159265358979323846 * 25.0; 
    EXPECT_NEAR(c.getFerence(), expectedFerence, EPSILON);
    EXPECT_NEAR(c.getArea(), expectedArea, EPSILON);
}

TEST(CircleTest, NegativeFerence) {
    Circle c(5.0);
    double negFerence = -31.415926;
    c.setFerence(negFerence);
    double expectedRadius = negFerence / (2 * 3.14159265358979323846);
    double expectedArea = 3.14159265358979323846 * expectedRadius * expectedRadius;
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPSILON);
    EXPECT_NEAR(c.getFerence(), negFerence, EPSILON);
    EXPECT_NEAR(c.getArea(), expectedArea, EPSILON);
}

TEST(TaskTest, RopeGapCalculation) {
    double gap = calculateRopeGap();
    double expectedGap = 1.0 / (2 * 3.14159265358979323846);
    EXPECT_NEAR(gap, expectedGap, 1e-5);
}

TEST(TaskTest, PoolConcreteCostCalculation) {
    double concreteCost = 0.0, fenceCost = 0.0;
    calculatePoolCosts(concreteCost, fenceCost);
    double expectedConcrete = 7 * 3.14159265358979323846 * 1000;
    EXPECT_NEAR(concreteCost, expectedConcrete, 1e-2);
}

TEST(TaskTest, PoolFenceCostCalculation) {
    double concreteCost = 0.0, fenceCost = 0.0;
    calculatePoolCosts(concreteCost, fenceCost);
    double expectedFence = 2 * 3.14159265358979323846 * 4 * 2000;
    EXPECT_NEAR(fenceCost, expectedFence, 1e-2);
}

TEST(CircleTest, MultipleSequentialUpdates) {
    Circle c(2.0);
    c.setRadius(3.0);
    double f1 = c.getFerence();
    c.setFerence(f1 + 5.0);
    double r1 = c.getRadius();
    c.setArea(c.getArea() + 10.0);
    double r2 = c.getRadius();
    EXPECT_FALSE(std::isnan(r1));
    EXPECT_FALSE(std::isnan(r2));
}

TEST(CircleTest, FloatPrecision) {
    Circle a(3.1415);
    Circle b(3.1415);
    EXPECT_NEAR(a.getRadius(), b.getRadius(), EPSILON);
    EXPECT_NEAR(a.getFerence(), b.getFerence(), EPSILON);
    EXPECT_NEAR(a.getArea(), b.getArea(), EPSILON);
}

TEST(CircleTest, LargeValue) {
    Circle c(1e6);
    c.setRadius(1e6);
    double expectedFerence = 2 * 3.14159265358979323846 * 1e6;
    EXPECT_NEAR(c.getFerence(), expectedFerence, 1e-2);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    c.setArea(50.0); 
    double expectedRadius = std::sqrt(50.0 / 3.14159265358979323846);
    EXPECT_NEAR(c.getRadius(), expectedRadius, 1e-6);
}

TEST(CircleTest, SetAreaCorrectness) {
    Circle c(0.5);
    double newArea = 100.0;
    c.setArea(newArea);
    double expectedRadius = std::sqrt(newArea / 3.14159265358979323846);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPSILON);
}

TEST(CircleTest, SetFerenceCorrectness) {
    Circle c(4.0);
    double newFerence = 2 * 3.14159265358979323846 * 4.0 + 0.123456;
    c.setFerence(newFerence);
    double expectedRadius = newFerence / (2 * 3.14159265358979323846);
    EXPECT_NEAR(c.getRadius(), expectedRadius, 1e-5);
}

TEST(TaskTest, PoolCostsNonNegative) {
    double concreteCost = 0.0, fenceCost = 0.0;
    calculatePoolCosts(concreteCost, fenceCost);
    EXPECT_GE(concreteCost, 0.0);
    EXPECT_GE(fenceCost, 0.0);
}


