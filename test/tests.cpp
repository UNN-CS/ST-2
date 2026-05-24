// Copyright 2026 Salykina Alena

#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

const double pi = 3.14159265358979323846;
const double EPS = 1e-9;

// =====================
// Circle tests
// =====================

TEST(Circle, create_pos) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * pi * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), pi * 25.0);
}

TEST(Circle, create_zero) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(Circle, get_rad) {
    Circle c(2.5);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.5);
}

TEST(Circle, get_fer) {
    Circle c(2.5);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * pi * 2.5);
}

TEST(Circle, get_area) {
    Circle c(2.5);
    EXPECT_DOUBLE_EQ(c.getArea(), pi * 6.25);
}

TEST(Circle, set_rad) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * pi * 3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), pi * 9.0);
}

TEST(Circle, set_rad_zero) {
    Circle c(1.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(Circle, set_rad_neg) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-2.0), std::invalid_argument);
}

TEST(Circle, set_fer) {
    Circle c(1.0);
    c.setFerence(2 * pi * 4.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * pi * 4.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
    EXPECT_DOUBLE_EQ(c.getArea(), pi * 16.0);
}

TEST(Circle, set_fer_zero) {
    Circle c(1.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(Circle, set_fer_neg) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
}

TEST(Circle, set_area) {
    Circle c(1.0);
    c.setArea(pi * 25.0);
    EXPECT_DOUBLE_EQ(c.getArea(), pi * 25.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * pi * 5.0);
}

TEST(Circle, set_area_zero) {
    Circle c(1.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(Circle, set_area_neg) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-100.0), std::invalid_argument);
}

TEST(Circle, same_rad) {
    Circle c(2.0);
    double oldFer = c.getFerence();
    double oldArea = c.getArea();
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), oldFer);
    EXPECT_DOUBLE_EQ(c.getArea(), oldArea);
}

TEST(Circle, same_fer) {
    Circle c(2.0);
    c.setFerence(c.getFerence());
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getArea(), pi * 4.0);
}

TEST(Circle, same_area) {
    Circle c(2.0);
    c.setArea(c.getArea());
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * pi * 2.0);
}

TEST(Circle, many_changes) {
    Circle c(1.0);
    c.setRadius(2.0);
    c.setFerence(2 * pi * 3.0);
    c.setArea(pi * 16.0);

    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * pi * 4.0, EPS);
    EXPECT_NEAR(c.getArea(), pi * 16.0, EPS);
}

// =====================
// EarthAndRope tests
// =====================

TEST(EarthRope, gap_pos) {
    EXPECT_GT(EarthAndRope(), 0.0);
}

TEST(EarthRope, gap_val) {
    EXPECT_NEAR(EarthAndRope(), 1.0 / (2 * pi), 1e-6);
}

// =====================
// Pool tests
// =====================

TEST(Pool, path_area) {
    Circle pool(3.0);
    Circle path(4.0);

    EXPECT_NEAR(path.getArea() - pool.getArea(), pi * 7.0, 1e-9);
}

TEST(Pool, fence_len) {
    Circle path(4.0);
    EXPECT_NEAR(path.getFerence(), 2 * pi * 4.0, 1e-9);
}

TEST(Pool, total_cost) {
    double cost = Pool();
    double exp = 2000.0 * (2 * pi * 4.0) + 1000.0 * (pi * 7.0);

    EXPECT_NEAR(cost, exp, 1e-6);
}

TEST(Pool, cost_pos) {
    EXPECT_GT(Pool(), 0.0);
}


