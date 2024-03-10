// Copyright 2024 Moiseev Nikita
#include "gtest/gtest.h"
#include "circle.h"
#include "tasks.h"

TEST(CircleTests, DefaultConstructor) {
    Circle circle;
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}
TEST(CircleTests, SetRadius) {
    Circle circle;
    circle.setRadius(5.0);
    EXPECT_NEAR(circle.getRadius(), 5.0, 1e-8);
    EXPECT_NEAR(circle.getFerence(), 31.4159265359, 1e-8);
    EXPECT_NEAR(circle.getArea(), 78.5398163397, 1e-8);
}

TEST(CircleTests, SetFerence) {
    Circle circle;
    circle.setFerence(10.0);
    EXPECT_NEAR(circle.getRadius(), 1.59154943092, 1e-8);
    EXPECT_NEAR(circle.getFerence(), 10.0, 1e-8);
}

TEST(CircleTests, SetArea) {
    Circle circle;
    circle.setArea(50.0);
    EXPECT_NEAR(circle.getRadius(), 3.98, 1e-1);
}

TEST(CircleTests, GetRadius) {
    Circle circle(2.5);
    EXPECT_NEAR(circle.getRadius(), 2.5, 1e-8);
}

TEST(CircleTests, GetFerence) {
    Circle circle(2.5);
    EXPECT_NEAR(circle.getFerence(), 15.7079632679, 1e-8);
}

TEST(CircleTests, GetArea) {
    Circle circle(2.5);
    EXPECT_NEAR(circle.getArea(), 19.6349540849, 1e-8);
}

TEST(CircleTests, BigRadius) {
    Circle circle(1e9);
    EXPECT_NEAR(circle.getRadius(), 1e9, 1e-8);
}

TEST(CircleTests, SmallRadius) {
    Circle circle(1e-9);
    EXPECT_NEAR(circle.getRadius(), 1e-9, 1e-8);
    EXPECT_NEAR(circle.getFerence(), 6.28318530718e-9, 1e-8);
    EXPECT_NEAR(circle.getArea(), 3.14159265359e-18, 1e-8);
}

TEST(CircleTests, ZeroRadius) {
    Circle circle(0.0);
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}

TEST(CircleTests, SetRadiusToZero) {
    Circle circle(5.0);
    circle.setRadius(0.0);
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}

TEST(CircleTests, SetFerenceToZero) {
    Circle circle(5.0);
    circle.setFerence(0.0);
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}

TEST(CircleTests, SetAreaToZero) {
    Circle circle(5.0);
    circle.setArea(0.0);
    EXPECT_EQ(circle.getRadius(), 0.0);
    EXPECT_EQ(circle.getFerence(), 0.0);
    EXPECT_EQ(circle.getArea(), 0.0);
}
TEST(CircleTests, SetAreaTwice) {
    Circle circle;
    circle.setArea(50.0);
    EXPECT_NEAR(circle.getRadius(), 3.98, 1e-1);
    EXPECT_NEAR(circle.getFerence(), 25.06, 1e-2);
    EXPECT_NEAR(circle.getArea(), 50.0, 1e-2);

    circle.setArea(100.0);
    EXPECT_NEAR(circle.getRadius(), 5.64, 1e-1);
    EXPECT_NEAR(circle.getFerence(), 35.44, 1e-2);
    EXPECT_NEAR(circle.getArea(), 100.0, 1e-2);
}

TEST(CircleTests, SetFerenceTwice) {
    Circle circle;
    circle.setFerence(10.0);
    EXPECT_NEAR(circle.getRadius(), 1.59, 1e-2);
    EXPECT_NEAR(circle.getFerence(), 10.0, 1e-2);
    EXPECT_NEAR(circle.getArea(), 7.95, 1e-2);

    circle.setFerence(20.0);
    EXPECT_NEAR(circle.getRadius(), 3.18, 1e-2);
    EXPECT_NEAR(circle.getFerence(), 20.0, 1e-2);
    EXPECT_NEAR(circle.getArea(), 31.83, 1e-2);
}

TEST(EarthAndRopeTests, EarthRadius) {
    EXPECT_NEAR(earthAndRope(1.0), 33696685.2, 1e-1);
}

TEST(EarthAndRopeTests, VeryLongRope) {
    const double ropeLength = 1000000.0;
    EXPECT_NEAR(earthAndRope(ropeLength), 34696684.2, 1e-1);
}

TEST(EarthAndRopeTests, VeryShortRope) {
    const double ropeLength = 0.000001;
    EXPECT_NEAR(earthAndRope(ropeLength), 33696684.2, 1e-1);
}

TEST(PoolCostTests, PoolRadius) {
    const double poolRadius = 3.0;
    const double roadWidth = 1.0;
    const double concreteCost = 1000.0;
    const double fenceCost = 2000.0;
    Circle pool(poolRadius);
    Circle poolWithRoad(pool.getRadius() + roadWidth);
    double concreteArea = poolWithRoad.getArea() - pool.getArea();
    double fenceFerence = poolWithRoad.getFerence();

    EXPECT_EQ(poolCost(poolRadius, roadWidth, concreteCost, fenceCost),
        concreteArea * concreteCost + fenceFerence * fenceCost);
}

TEST(PoolCostTests, CustomParameters) {
    const double poolRadius = 2.5;
    const double roadWidth = 0.5;
    const double concreteCost = 800.0;
    const double fenceCost = 1500.0;
    EXPECT_NEAR(poolCost(poolRadius, roadWidth, concreteCost, fenceCost),
        35185.8, 1e-1);
}
