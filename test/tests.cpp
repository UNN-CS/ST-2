// Copyright 2024 Kriseev Mikhail, UNN
#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"

TEST(CIRCLE_CLASS, getRadius_correct) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getRadius(), 1.0, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, getArea_correct) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getArea(), M_PI, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, getFerence_correct) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getFerence(), M_PI * 2, DBL_EPSILON);
}

TEST(CIRCLE_CLASS, setRadius_correct_radius) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getRadius(), 2.0, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, setRadius_correct_area) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getArea(), 4.0 * M_PI, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, setRadius_correct_ference) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getFerence(), 4 * M_PI, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, setArea_correct_area) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getArea(), 4 * M_PI, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, setArea_correct_radius) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getRadius(), 2.0, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, setArea_correct_ference) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getFerence(), 4 * M_PI, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, setFerence_correct_ference) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getFerence(), 4 * M_PI, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, setFerence_correct_radius) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getRadius(), 2.0, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, setFerence_correct_area) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getArea(), 4 * M_PI, DBL_EPSILON);
}
TEST(CIRCLE_CLASS, negative_constructor_arg) {
    EXPECT_ANY_THROW(Circle(-1.0));
}

TEST(CIRCLE_CLASS, setRadius_negative_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setRadius(-1.0));
}
TEST(CIRCLE_CLASS, setArea_negative_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setArea(-1.0));
}
TEST(CIRCLE_CLASS, setFerence_negative_input) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setFerence(-1.0));
}