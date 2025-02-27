// Copyright 2025 UNN-CS Team
#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

TEST(circle_tests, Task1) {
    double task1_answer = Rope(6378.1);
    double expected = 0.159155;
    EXPECT_NEAR(task1_answer, expected, 0.1);
}

TEST(circle_tests, Task2) {
    double task2_answer = SwimmingPool(3, 1, 1000, 2000);
    double expected = 72256.6;
    EXPECT_NEAR(task2_answer, expected, 0.1);
}

TEST(circle_tests, RadiusInitialization) {
    Circle c1(10);
    EXPECT_EQ(c1.getRadius(), 10);
    EXPECT_NEAR(c1.getFerence(), 2 * M_PI * 10, 1e-6);
    EXPECT_NEAR(c1.getArea(), M_PI * 100, 1e-6);
}

TEST(circle_tests, FerenceSetting) {
    Circle c1(10);
    c1.setFerence(20 * M_PI);
    EXPECT_EQ(c1.getRadius(), 10);
    EXPECT_EQ(c1.getArea(), M_PI * 100);
}

TEST(circle_tests, AreaSetting) {
    Circle c1(10);
    c1.setArea(100 * M_PI);
    EXPECT_EQ(c1.getRadius(), 10);
    EXPECT_EQ(c1.getFerence(), 2 * M_PI * 10);
}

TEST(circle_tests, ZeroRadius) {
    Circle c1(0);
    EXPECT_EQ(c1.getRadius(), 0);
    EXPECT_EQ(c1.getFerence(), 0);
    EXPECT_EQ(c1.getArea(), 0);
}

TEST(circle_tests, SmallRadius) {
    Circle c1(0.1);
    EXPECT_EQ(c1.getRadius(), 0.1);
    EXPECT_EQ(c1.getFerence(), 2 * M_PI * 0.1);
    EXPECT_EQ(c1.getArea(), M_PI * 0.01);
}

TEST(circle_tests, NegativeRadius) {
    Circle c1(5);
    c1.setRadius(-10);
    EXPECT_EQ(c1.getRadius(), 5);
}

TEST(circle_tests, NegativeFerence) {
    Circle c1;
    c1.setFerence(100);
    c1.setFerence(-300);
    EXPECT_EQ(c1.getFerence(), 100);
}

TEST(circle_tests, NegativeArea) {
    Circle c1;
    c1.setArea(1000);
    c1.setArea(-1);
    EXPECT_EQ(c1.getArea(), 1000);
}

TEST(circle_tests, FerenceCalculation) {
    Circle c1(5);
    EXPECT_EQ(c1.getFerence(), 2 * M_PI * 5);
}

TEST(circle_tests, AreaCalculation) {
    Circle c1(5);
    EXPECT_EQ(c1.getArea(), M_PI * 25);
}

TEST(circle_tests, ChangeRadius) {
    Circle c1(5);
    c1.setRadius(7);
    EXPECT_EQ(c1.getRadius(), 7);
    EXPECT_EQ(c1.getFerence(), 2 * M_PI * 7);
    EXPECT_EQ(c1.getArea(), M_PI * 49);
}

TEST(circle_tests, ChangeFerence) {
    Circle c1(5);
    c1.setFerence(2 * M_PI * 8);
    EXPECT_EQ(c1.getRadius(), 8);
    EXPECT_EQ(c1.getArea(), M_PI * 64);
}

TEST(circle_tests, ChangeArea) {
    Circle c1(5);
    c1.setArea(M_PI * 36);
    EXPECT_EQ(c1.getRadius(), 6);
    EXPECT_EQ(c1.getFerence(), 2 * M_PI * 6);
}

TEST(circle_tests, LargeRadius) {
    Circle c1(10000);
    EXPECT_EQ(c1.getFerence(), 2 * M_PI * 10000);
    EXPECT_EQ(c1.getArea(), M_PI * 100000000);
}

TEST(circle_tests, RopeTask_Small) {
    double result = Rope(1);
    double expected = 1 / (2 * M_PI);
    EXPECT_NEAR(result, expected, 1e-6);
}

TEST(circle_tests, SwimmingPool_Large) {
    double result = SwimmingPool(50, 5, 200, 500);
    double expected = 502654.82;
    EXPECT_NEAR(result, expected, 0.1);
}

TEST(circle_tests, SwimmingPool_NoRoad) {
    double result = SwimmingPool(3, 0, 1000, 2000);
    double expected = 37699.111;
    EXPECT_NEAR(result, expected, 1e-2);
}

TEST(circle_tests, SwimmingPool_ZeroCost) {
    double result = SwimmingPool(5, 2, 0, 0);
    EXPECT_EQ(result, 0);
}

TEST(circle_tests, SwimmingPool_ZeroRadius) {
    double result = SwimmingPool(0, 5, 1000, 500);
    double expected = (M_PI * 25) * 1000 + (2 * M_PI * 5) * 500;
    EXPECT_EQ(result, expected);
}
