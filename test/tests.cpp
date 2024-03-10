// Copyright 2024 Filatov Maxim
#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double EPS = 1.0e-9;

TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, getRadius_correct) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getRadius(), 1.0, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, getArea_correct) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getArea(), M_PI, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, getFerence_correct) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getFerence(), M_PI * 2, EPS);
}

TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setRadius_correct_radius) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getRadius(), 2.0, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setRadius_correct_area) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getArea(), 4.0 * M_PI, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setRadius_correct_ference) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getFerence(), 4 * M_PI, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setArea_correct_area) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getArea(), 4 * M_PI, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setArea_correct_radius) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getRadius(), 2.0, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setArea_correct_ference) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getFerence(), 4 * M_PI, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setFerence_correct_ference) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getFerence(), 4 * M_PI, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setFerence_correct_radius) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getRadius(), 2.0, EPS);
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setFerence_correct_area) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getArea(), 4 * M_PI, EPS);
}

TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, negative_constructor_arg) {
    EXPECT_ANY_THROW(Circle(-1.0));
}

TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setRadius_negative_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setRadius(-1.0));
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setArea_negative_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setArea(-1.0));
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setFerence_negative_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setFerence(-1.0));
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, zero_constructor_arg) {
    EXPECT_ANY_THROW(Circle(0.0));
}

TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setRadius_zero_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setRadius(0.0));
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setArea_zero_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setArea(0.0));
}
TEST(CIRCLE_CLASS_ALL_TESTED_GROUP, setFerence_zero_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setFerence(0.0));
}

TEST(TASKS_ALL_TESTED_GROUP, ropeAroundPlanetTask_Earth_1m) {
    EXPECT_NEAR(ropeAroundPlanetTask(6371000.0, 1.0), M_1_PI * 0.5, EPS);
}
TEST(TASKS_ALL_TESTED_GROUP, pathAroundPoolAndFencePriceTask) {
    EXPECT_NEAR(
            pathAroundPoolAndFencePriceTask(3.0, 1.0, 1000.0, 2000.0),
            23000.0 * M_PI,
            EPS);
}
