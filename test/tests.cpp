// Copyright 2025 Salaev Vladislav
#include <gtest/gtest.h>
#include <cstdint>
#include "tasks.h"
#include "circle.h"


#define PI 3.14159265358979323846


class CircleTest : public ::testing::Test {
 protected:
    Circle* c;

    void SetUp() override {
        c = new Circle(1.0);
    }

    void TearDown() override {
        delete c;
    }
};

TEST_F(CircleTest, InitialRadius) {
    EXPECT_NEAR(c->getRadius(), 1.0, 1e-6);
}

TEST_F(CircleTest, InitialFerence) {
    EXPECT_NEAR(c->getFerence(), 2 * PI * 1.0, 1e-6);
}

TEST_F(CircleTest, InitialArea) {
    EXPECT_NEAR(c->getArea(), PI * 1.0 * 1.0, 1e-6);
}

TEST_F(CircleTest, SetRadius) {
    c->setRadius(2.0);
    EXPECT_NEAR(c->getRadius(), 2.0, 1e-6);
    EXPECT_NEAR(c->getFerence(), 2 * PI * 2.0, 1e-6);
    EXPECT_NEAR(c->getArea(), PI * 2.0 * 2.0, 1e-6);
}

TEST_F(CircleTest, SetFerence) {
    c->setFerence(2 * PI * 2.0);
    EXPECT_NEAR(c->getRadius(), 2.0, 1e-6);
    EXPECT_NEAR(c->getFerence(), 2 * PI * 2.0, 1e-6);
    EXPECT_NEAR(c->getArea(), PI * 2.0 * 2.0, 1e-6);
}

TEST_F(CircleTest, SetArea) {
    c->setArea(PI * 2.0 * 2.0);
    EXPECT_NEAR(c->getRadius(), 2.0, 1e-6);
    EXPECT_NEAR(c->getFerence(), 2 * PI * 2.0, 1e-6);
    EXPECT_NEAR(c->getArea(), PI * 2.0 * 2.0, 1e-6);
}

TEST_F(CircleTest, SetNegativeRadius) {
    c->setRadius(-1.0);
    EXPECT_LT(c->getRadius(), 0);
}

TEST_F(CircleTest, SetZeroRadius) {
    c->setRadius(0.0);
    EXPECT_NEAR(c->getRadius(), 0.0, 1e-6);
}

TEST_F(CircleTest, SetLargeRadius) {
    c->setRadius(1e6);
    EXPECT_NEAR(c->getRadius(), 1e6, 1e-6);
}

TEST_F(CircleTest, SetNegativeFerence) {
    c->setFerence(-1.0);
    EXPECT_LT(c->getFerence(), 0);
}

TEST_F(CircleTest, SetZeroFerence) {
    c->setFerence(0.0);
    EXPECT_NEAR(c->getFerence(), 0.0, 1e-6);
}

TEST_F(CircleTest, SetLargeFerence) {
    c->setFerence(2 * PI * 1e6);
    EXPECT_NEAR(c->getFerence(), 2 * PI * 1e6, 1e-6);
}

TEST_F(CircleTest, SetNegativeArea) {
    c->setArea(-1.0);
    EXPECT_LT(c->getArea(), 0);
}

TEST_F(CircleTest, SetZeroArea) {
    c->setArea(0.0);
    EXPECT_NEAR(c->getArea(), 0.0, 1e-6);
}

TEST_F(CircleTest, SetLargeArea) {
    c->setArea(PI * 1e6 * 1e6);
    EXPECT_NEAR(c->getArea(), PI * 1e6 * 1e6, 1e-6);
}

TEST(CircleIndependentTest, CalculateGapAfterAddingRope) {
    double initialRadius = 6378.1;
    double addedLength = 1.0;
    double gap = calculateGapAfterAddingRope(initialRadius, addedLength);
    EXPECT_NEAR(gap, 1.0 / (2 * PI), 1e-6);
}

TEST(CircleIndependentTest, CalculateGapZeroAddedLength) {
    double initialRadius = 6378.1;
    double addedLength = 0.0;
    double gap = calculateGapAfterAddingRope(initialRadius, addedLength);
    EXPECT_NEAR(gap, 0.0, 1e-6);
}

TEST(CircleIndependentTest, CalculateCostForPool) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double concreteCost = 1000.0;
    double fenceCost = 2000.0;
    double cost = calculateCostForPool(poolRadius,
        pathWidth, concreteCost, fenceCost);
    EXPECT_NEAR(cost, 72256.63, 0.1);
}

TEST(CircleIndependentTest, CalculateCostZeroWidth) {
    double poolRadius = 3.0;
    double pathWidth = 0.0;
    double concreteCost = 1000.0;
    double fenceCost = 2000.0;
    double cost = calculateCostForPool(poolRadius,
        pathWidth, concreteCost, fenceCost);
    EXPECT_NEAR(cost, 37699.11184307752, 1e-2);
}
