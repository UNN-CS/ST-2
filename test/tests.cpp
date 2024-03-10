// Copyright 2024 Karagodin Andrey
#include <gtest/gtest.h>
#include <cstdint>
#include "../include/circle.h"
#include "../include/tasks.h"

const double EPS = 1.0e-9;

TEST(CircleTests, TestArea) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getArea(), M_PI, EPS);
}

TEST(CircleTests, TestRadius) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getRadius(), 1.0, EPS);
}

TEST(CircleTests, TestFerence) {
    Circle circle(1.0);
    EXPECT_NEAR(circle.getFerence(), M_PI * 2, EPS);
}

TEST(CircleTests, TestSetRadiusCorrectRadius) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getRadius(), 2.0, EPS);
}
TEST(CircleTests, TestSetRadiusCorrectArea) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getArea(), 4.0 * M_PI, EPS);
}
TEST(CircleTests, TestSetRadiusCorrectFerence) {
    Circle circle(1.0);
    circle.setRadius(2.0);
    EXPECT_NEAR(circle.getFerence(), 4.0 * M_PI, EPS);
}

TEST(CircleTests, TestSetAreaCorrectArea) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getArea(), 4 * M_PI, EPS);
}
TEST(CircleTests, TestSetAreaCorrectRadius) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getRadius(), 2.0, EPS);
}
TEST(CircleTests, TestSetAreaCorrectFerence) {
    Circle circle(1.0);
    circle.setArea(4 * M_PI);
    EXPECT_NEAR(circle.getFerence(), 4 * M_PI, EPS);
}
TEST(CircleTests, TestSetFerenceCorrectFerence) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getFerence(), 4 * M_PI, EPS);
}
TEST(CircleTests, TestSetFerenceCorrectRadius) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getRadius(), 2.0, EPS);
}
TEST(CircleTests, TestSetFerenceCorrectArea) {
    Circle circle(1.0);
    circle.setFerence(4 * M_PI);
    EXPECT_NEAR(circle.getArea(), 4 * M_PI, EPS);
}

TEST(CircleTests, TestValueZeroConstructorThrowsException) {
    EXPECT_ANY_THROW(Circle(0.0));
}

TEST(CircleTests, TestValueZeroSetRadiusThrowsException) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setRadius(0.0));
}
TEST(CircleTests, TestValueZeroSetAreaThrowsException) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setArea(0.0));
}
TEST(CircleTests, TestValueZeroSetFerenceThrowsException) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setFerence(0.0));
}

TEST(CircleTests, TestNegativeValueConstructorThrowsException) {
    EXPECT_ANY_THROW(Circle(-1.0));
}

TEST(CircleTests, TestNegativeValueSetRadiusThrowsException) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setRadius(-1.0));
}
TEST(CircleTests, TestNegativeValueSetAreaThrowsException) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setArea(-1.0));
}
TEST(CircleTests, TestNegativeValueSetFerenceThrowsException) {
    Circle circle(1.0);
    EXPECT_ANY_THROW(circle.setFerence(-1.0));
}
TEST(TaskTests, TestTask1) {
    EXPECT_NEAR(task_1(6371000.0, 1.0), M_1_PI * 0.5, EPS);
}
TEST(TaskTests, TestTask2) {
    EXPECT_NEAR(task_2(3.0, 1.0, 1000.0, 2000.0), 23000.0 * M_PI, EPS);
}
