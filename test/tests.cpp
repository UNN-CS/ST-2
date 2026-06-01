// Copyright 2025 UNN-CS


#include <gtest/gtest.h>

#include "circle.h"
#include "tasks.h"

static const double EPS = 1e-6;

TEST(CircleConstructorTest, RadiusIsSetCorrectly) {
    Circle circle(5.0);

    EXPECT_NEAR(circle.getRadius(), 5.0, EPS);
}

TEST(CircleConstructorTest, FerenceIsCalculatedCorrectly) {
    Circle circle(1.0);

    EXPECT_NEAR(circle.getFerence(), 6.283185307179586, EPS);
}

TEST(CircleConstructorTest, AreaIsCalculatedCorrectly) {
    Circle circle(1.0);

    EXPECT_NEAR(circle.getArea(), 3.141592653589793, EPS);
}

TEST(CircleSetRadiusTest, RadiusChangesCorrectly) {
    Circle circle(1.0);

    circle.setRadius(10.0);

    EXPECT_NEAR(circle.getRadius(), 10.0, EPS);
}

TEST(CircleSetRadiusTest, FerenceChangesAfterRadius) {
    Circle circle(1.0);

    circle.setRadius(2.0);

    EXPECT_NEAR(circle.getFerence(), 12.566370614359172, EPS);
}

TEST(CircleSetRadiusTest, AreaChangesAfterRadius) {
    Circle circle(1.0);

    circle.setRadius(2.0);

    EXPECT_NEAR(circle.getArea(), 12.566370614359172, EPS);
}

TEST(CircleSetRadiusTest, ZeroRadius) {
    Circle circle(5.0);

    circle.setRadius(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, EPS);
    EXPECT_NEAR(circle.getFerence(), 0.0, EPS);
    EXPECT_NEAR(circle.getArea(), 0.0, EPS);
}

TEST(CircleSetFerenceTest, FerenceChangesCorrectly) {
    Circle circle(1.0);

    circle.setFerence(10.0);

    EXPECT_NEAR(circle.getFerence(), 10.0, EPS);
}

TEST(CircleSetFerenceTest, RadiusChangesAfterFerence) {
    Circle circle(1.0);

    circle.setFerence(6.283185307179586);

    EXPECT_NEAR(circle.getRadius(), 1.0, EPS);
}

TEST(CircleSetFerenceTest, AreaChangesAfterFerence) {
    Circle circle(1.0);

    circle.setFerence(6.283185307179586);

    EXPECT_NEAR(circle.getArea(), 3.141592653589793, EPS);
}

TEST(CircleSetFerenceTest, ZeroFerence) {
    Circle circle(5.0);

    circle.setFerence(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, EPS);
    EXPECT_NEAR(circle.getFerence(), 0.0, EPS);
    EXPECT_NEAR(circle.getArea(), 0.0, EPS);
}

TEST(CircleSetAreaTest, AreaChangesCorrectly) {
    Circle circle(1.0);

    circle.setArea(25.0);

    EXPECT_NEAR(circle.getArea(), 25.0, EPS);
}

TEST(CircleSetAreaTest, RadiusChangesAfterArea) {
    Circle circle(1.0);

    circle.setArea(3.141592653589793);

    EXPECT_NEAR(circle.getRadius(), 1.0, EPS);
}

TEST(CircleSetAreaTest, FerenceChangesAfterArea) {
    Circle circle(1.0);

    circle.setArea(3.141592653589793);

    EXPECT_NEAR(circle.getFerence(), 6.283185307179586, EPS);
}

TEST(CircleSetAreaTest, ZeroArea) {
    Circle circle(5.0);

    circle.setArea(0.0);

    EXPECT_NEAR(circle.getRadius(), 0.0, EPS);
    EXPECT_NEAR(circle.getFerence(), 0.0, EPS);
    EXPECT_NEAR(circle.getArea(), 0.0, EPS);
}

TEST(CircleLogicTest, RadiusToFerenceAndBack) {
    Circle circle(5.0);

    double ference = circle.getFerence();
    circle.setFerence(ference);

    EXPECT_NEAR(circle.getRadius(), 5.0, EPS);
}

TEST(CircleLogicTest, RadiusToAreaAndBack) {
    Circle circle(5.0);

    double area = circle.getArea();
    circle.setArea(area);

    EXPECT_NEAR(circle.getRadius(), 5.0, EPS);
}

TEST(EarthRopeTaskTest, GapIsCorrect) {
    EXPECT_NEAR(earthRopeGap(), 0.159154943, EPS);
}

TEST(EarthRopeTaskTest, GapDoesNotDependOnEarthRadiusInPractice) {
    EXPECT_GT(earthRopeGap(), 0.15);
    EXPECT_LT(earthRopeGap(), 0.17);
}

TEST(PoolTaskTest, ConcreteCostIsCorrect) {
    EXPECT_NEAR(poolConcreteCost(), 21991.148575, EPS);
}

TEST(PoolTaskTest, FenceCostIsCorrect) {
    EXPECT_NEAR(poolFenceCost(), 50265.482457, EPS);
}

TEST(PoolTaskTest, TotalCostIsCorrect) {
    EXPECT_NEAR(poolTotalCost(), 72256.631032, EPS);
}

TEST(PoolTaskTest, TotalCostEqualsConcretePlusFence) {
    EXPECT_NEAR(poolTotalCost(), poolConcreteCost() + poolFenceCost(), EPS);
}



