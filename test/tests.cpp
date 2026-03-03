// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <stdexcept>
#include <math.h>
#include "circle.h"
#include "tasks.h"

// task
TEST(TaskTest, Task_Earth_and_rope) {
    double correct_answer = 0.159155;
    EXPECT_NEAR(calculateGap(), correct_answer, 1e-6);
}

TEST(TaskTest, Task_pool) {
    double correct_answer_fccp = 21991.14857;
    double correct_answer_fcf = 50265.48245;

    EXPECT_NEAR(calculateCosts().concrete_cost, correct_answer_fccp, 1e-5);
    EXPECT_NEAR(calculateCosts().fence_cost, correct_answer_fcf, 1e-5);
}

// task resuls are positives or corrects
TEST(TaskTest, EarthRopeGapPositive) {
    double gap = calculateGap();
    EXPECT_GT(gap, 0.0);
}

TEST(TaskTest, PoolConcreteCostPositive) {
    PoolCosts costs = calculateCosts();
    EXPECT_GT(costs.concrete_cost, 0.0);
}

TEST(TaskTest, PoolFenceCostPositive) {
    PoolCosts costs = calculateCosts();
    EXPECT_GT(costs.fence_cost, 0.0);
}

TEST(TaskTest, EarthRopeGapLessThanOne) {
    double gap = calculateGap();
    EXPECT_LT(gap, 1.0);
}

// tasks circles methods calculations correct
TEST(TaskTest, PoolWalkwayArea) {
    Circle pool;
    pool.setRadius(3.0);
    Circle poolWithWalkway;
    poolWithWalkway.setRadius(4.0);
    double expected_area = poolWithWalkway.getArea() - pool.getArea();
    
    PoolCosts costs = calculateCosts();
    double actual_area = costs.concrete_cost / 1000.0;
    
    EXPECT_NEAR(actual_area, expected_area, 1e-5);
}

TEST(TaskTest, PoolFenceLength) {
    Circle poolWithWalkway;
    poolWithWalkway.setRadius(4.0);
    double expected_length = poolWithWalkway.getFerence();
    
    PoolCosts costs = calculateCosts();
    double actual_length = costs.fence_cost / 2000.0;
    
    EXPECT_NEAR(actual_length, expected_length, 1e-5);
}

// constructor
TEST(CircleTest, DefaultConstructor) {
    Circle c;
    ASSERT_DOUBLE_EQ(c.getRadius(), 0.0);
    ASSERT_DOUBLE_EQ(c.getFerence(), 0.0);
    ASSERT_DOUBLE_EQ(c.getArea(), 0.0);
}

// radius
TEST(CircleTest, SetRadiusPositive) {
    Circle c;
    c.setRadius(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-3);
    EXPECT_NEAR(c.getFerence(), 2 * 3.1415926535 * 5.0, 1e-3);
    EXPECT_NEAR(c.getArea(), 3.1415926535 * 25.0, 1e-3);
}

TEST(CircleTest, SetRadiusZero) {
    Circle c;
    c.setRadius(0.0);
    ASSERT_DOUBLE_EQ(c.getRadius(), 0.0);
    ASSERT_DOUBLE_EQ(c.getFerence(), 0.0);
    ASSERT_DOUBLE_EQ(c.getArea(), 0.0);
}

// ference
TEST(CircleTest, SetFerencePositive) {
    Circle c;
    double f = 10.0;
    c.setFerence(f);
    EXPECT_NEAR(c.getFerence(), f, 1e-3);
    EXPECT_NEAR(c.getRadius(), f / (2 * 3.1415926535), 1e-3);
    EXPECT_NEAR(c.getArea(), 3.1415926535 * pow(f / (2 * 3.1415926535), 2), 1e-3);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c;
    c.setFerence(0.0);
    ASSERT_DOUBLE_EQ(c.getRadius(), 0.0);
    ASSERT_DOUBLE_EQ(c.getFerence(), 0.0);
    ASSERT_DOUBLE_EQ(c.getArea(), 0.0);
}

// area
TEST(CircleTest, SetAreaPositive) {
    Circle c;
    double a = 50.0;
    c.setArea(a);
    EXPECT_NEAR(c.getArea(), a, 1e-3);
    EXPECT_NEAR(c.getRadius(), sqrt(a / 3.1415926535), 1e-3);
    EXPECT_NEAR(c.getFerence(), 2 * 3.1415926535 * sqrt(a / 3.1415926535), 1e-3);
}

TEST(CircleTest, SetAreaZero) {
    Circle c;
    c.setArea(0.0);
    ASSERT_DOUBLE_EQ(c.getRadius(), 0.0);
    ASSERT_DOUBLE_EQ(c.getFerence(), 0.0);
    ASSERT_DOUBLE_EQ(c.getArea(), 0.0);
}

// negative
TEST(CircleTest, NegativeRadiusThrows) {
    Circle c;
    EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
}

TEST(CircleTest, NegativeFerenceThrows) {
    Circle c;
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
}

TEST(CircleTest, NegativeAreaThrows) {
    Circle c;
    EXPECT_THROW(c.setArea(-20.0), std::invalid_argument);
}

// positive
TEST(CircleTest, PositiveValuesWork) {
    Circle c;
    EXPECT_NO_THROW(c.setRadius(5.0));
    EXPECT_NO_THROW(c.setFerence(10.0));
    EXPECT_NO_THROW(c.setArea(20.0));
}

// more changes
TEST(CircleTest, SequentialChanges) {
    Circle c;
    c.setRadius(5.0);
    c.setFerence(40.0);
    c.setArea(200.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 200.0);
}