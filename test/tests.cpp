// Copyright 2024 Kochtov Nikolay
#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double EPS = 1.0e-9;

TEST(Circle, creatingCircleWithCorrectIntRadius) {
    EXPECT_NO_THROW(Circle(1));
}

TEST(Circle, creatingCircleWithCorrectDoubleRadius) {
    EXPECT_NO_THROW(Circle(1.0));
}

TEST(Circle, creatingCircleWithZeroRadius) {
    EXPECT_ANY_THROW(Circle(0));
}

TEST(Circle, creatingCircleWithNegativeRadius) {
    EXPECT_ANY_THROW(Circle(-10));
}

TEST(Circle, getCorrectRadius) {
    Circle circle(1);
    EXPECT_NEAR(circle.GetRadius(), 1, EPS);
}

TEST(Circle, getCorrectArea) {
    Circle circle(1);
    EXPECT_NEAR(circle.GetArea(), M_PI, EPS);
}

TEST(Circle, getCorrectFerence) {
    Circle circle(1);
    EXPECT_NEAR(circle.GetFerence(), 2 * M_PI, EPS);
}

TEST(Circle, SetCorrectRadius) {
    Circle circle(1);
    circle.SetRadius(2);
    EXPECT_NEAR(circle.GetRadius(), 2, EPS);
}

TEST(Circle, SetCorrectRadiusCheckingArea) {
    Circle circle(1);
    circle.SetRadius(2);
    EXPECT_NEAR(circle.GetArea(), 4 * M_PI, EPS);
}

TEST(Circle, SetCorrectRadiusCheckingFerence) {
    Circle circle(1);
    circle.SetRadius(2);
    EXPECT_NEAR(circle.GetFerence(), 4 * M_PI, EPS);
}

TEST(Circle, SetZeroRadius) {
    Circle circle(1);
    EXPECT_ANY_THROW(circle.SetRadius(0));
}

TEST(Circle, SetNegativeRadius) {
    Circle circle(1);
    EXPECT_ANY_THROW(circle.SetRadius(-10));
}

TEST(Circle, SetCorrectArea) {
    Circle circle(1);
    circle.SetArea(4 * M_PI);
    EXPECT_NEAR(circle.GetRadius(), 2, EPS);
    EXPECT_NEAR(circle.GetArea(), 4 * M_PI, EPS);
    EXPECT_NEAR(circle.GetFerence(), 4 * M_PI, EPS);
}

TEST(Circle, SetZeroArea) {
    Circle circle(1);
    EXPECT_ANY_THROW(circle.SetArea(0));
}

TEST(Circle, SetNegativeArea) {
    Circle circle(1);
    EXPECT_ANY_THROW(circle.SetArea(-10));
}

TEST(Circle, SetCorrectFerence) {
    Circle circle(1);
    circle.SetFerence(4 * M_PI);
    EXPECT_NEAR(circle.GetRadius(), 2, EPS);
    EXPECT_NEAR(circle.GetArea(), 4 * M_PI, EPS);
    EXPECT_NEAR(circle.GetFerence(), 4 * M_PI, EPS);
}

TEST(Circle, SetZeroFerence) {
    Circle circle(1);
    EXPECT_ANY_THROW(circle.SetFerence(0));
}

TEST(Circle, SetNegativeFerence) {
    Circle circle(1);
    EXPECT_ANY_THROW(circle.SetFerence(-10));
}

TEST(Tasks, RopeAroundPlanetTaskEarth1m) {
    EXPECT_NEAR(RopeAroundPlanetTask(6371000.0, 1.0), M_1_PI * 0.5, EPS);
}

TEST(Tasks, PathAroundPoolAndFencePriceTask) {
    EXPECT_NEAR(
            PathAroundPoolAndFencePriceTask(3.0, 1.0, 1000.0, 2000.0),
            23000.0 * M_PI,
            EPS);
}
