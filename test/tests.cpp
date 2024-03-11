// Copyright 2024 Kirillov Maxim
#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "../include/circle.h"
#include "../include/tasks.h"

const double PI = 3.14159265358979323846264;
const double accuracy = 1e-9;

TEST(Circles, TestGetRadius) {
    Circle circle(10);
    EXPECT_NEAR(circle.getRadius(), 10, accuracy);
}

TEST(Circles, TestGetFerence) {
    Circle circle(10);
    EXPECT_NEAR(circle.getFerence(), 2 * PI * 10, accuracy);
}

TEST(Circles, TestGetArea) {
    Circle circle(10);
    EXPECT_NEAR(circle.getArea(), PI * 10 * 10, accuracy);
}

TEST(Circles, TestSetRadius) {
    Circle circle(10);
    circle.setRadius(7);
    EXPECT_NEAR(circle.getRadius(), 7, accuracy);
    EXPECT_NEAR(circle.getFerence(), 14 * PI, accuracy);
    EXPECT_NEAR(circle.getArea(), PI * 7 * 7, accuracy);
}

TEST(Circles, TestSetFerence) {
    Circle circle(10);
    circle.setFerence(10 * PI);
    EXPECT_NEAR(circle.getRadius(), 5, accuracy);
    EXPECT_NEAR(circle.getFerence(), 10 * PI, accuracy);
    EXPECT_NEAR(circle.getArea(), PI * 5 * 5, accuracy);
}

TEST(Circles, TestSetArea) {
    Circle circle(5);
    circle.setArea(PI * 36);
    EXPECT_NEAR(circle.getRadius(), 6, accuracy);
    EXPECT_NEAR(circle.getFerence(), 12 * PI, accuracy);
    EXPECT_NEAR(circle.getArea(), PI * 36, accuracy);
}

TEST(Circles, TestInvalidRadius) {
    ASSERT_THROW(Circle(-10), std::invalid_argument);
}

TEST(Circles, TestSetInvalidRadius) {
    Circle circle(5);
    ASSERT_THROW(circle.setRadius(-10), std::invalid_argument);
}

TEST(Circles, TestSetInvalidFerence) {
    Circle circle(5);
    ASSERT_THROW(circle.setFerence(-50), std::invalid_argument);
}

TEST(Circles, TestSetInvalidArea) {
    Circle circle(5);
    ASSERT_THROW(circle.setArea(-250), std::invalid_argument);
}

TEST(Circles, TestSetRadiusGetFerence) {
    Circle circle(5);
    circle.setRadius(10);
    EXPECT_NEAR(circle.getFerence(), 2 * PI * 10, accuracy);
}

TEST(Circles, TestSetFerenceGetRadius) {
    Circle circle(5);
    circle.setFerence(2 * PI * 15);
    EXPECT_NEAR(circle.getRadius(), 15, accuracy);
}

TEST(Circles, TestSetRadiusGetArea) {
    Circle circle(10);
    circle.setRadius(5);
    EXPECT_NEAR(circle.getArea(), PI * 5 * 5, accuracy);
}

TEST(Circles, TestSetAreaGetFerence) {
    Circle circle(5);
    circle.setArea(PI * 36);
    EXPECT_NEAR(circle.getFerence(), 2 * PI * 6, accuracy);
}

TEST(EarthAndRope, AssertInvalidArgument) {
    ASSERT_THROW(SolveEarthAndRope(-100), std::invalid_argument);
}

TEST(EarthAndRope, AddedNullArgument) {
    EXPECT_NEAR(SolveEarthAndRope(0), 0, accuracy);
}

TEST(EarthAndRope, TestTask1) {
    double earthRadius = 6378100;
    double ropeLength = 1;
    double result = (2 * PI * earthRadius + ropeLength) /
            (2 * PI) - earthRadius;
    ASSERT_NEAR(SolveEarthAndRope(ropeLength), result, accuracy);
}

TEST(SwimmingPool, AssertInvalidArguments) {
    ASSERT_THROW(SolvePool(-10, 10, 1000, 1000), std::invalid_argument);
    ASSERT_THROW(SolvePool(10, -10, 1000, 1000), std::invalid_argument);
    ASSERT_THROW(SolvePool(-10, -10, 1000, 1000), std::invalid_argument);
}

TEST(SwimmingPool, AddedNullArgument) {
    ASSERT_THROW(SolvePool(0, 0, 0, 0), std::invalid_argument);
}

TEST(SwimmingPool, TestTask2) {
    double poolRadius = 3;
    double trackWidth = 1;
    double concreteCost = 1000;
    double fenceCost = 2000;
    double fencePrice = 2 * PI * (poolRadius + trackWidth) * fenceCost;
    double trackPrice = PI * (pow(poolRadius + trackWidth, 2)
            - pow(poolRadius, 2)) * concreteCost;
    double summary = fencePrice + trackPrice;
    ASSERT_NEAR(SolvePool(poolRadius, trackWidth, concreteCost, fenceCost),
                summary, accuracy);
}
