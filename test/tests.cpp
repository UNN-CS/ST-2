// Copyright 2025 ovVrLFg8ks

#include <gtest/gtest.h>

#include <cstdint>

#include "circle.h"
#include "tasks.h"

TEST(circle, init_radius_10) {
  Circle c(10);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10);
  EXPECT_NEAR(c.getFerence(), 62.83185307179586, 1.0E-14);
  EXPECT_NEAR(c.getArea(), 314.1592653589793, 1.0E-14);
}
TEST(circle, init_radius_0) {
  Circle c(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}
TEST(circle, init_radius_negative) {
  EXPECT_THROW(Circle c(-1), std::invalid_argument);
}

TEST(circle, set_radius_10) {
  Circle c(0);
  c.setRadius(10);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10);
  EXPECT_NEAR(c.getFerence(), 62.83185307179586, 1.0E-14);
  EXPECT_NEAR(c.getArea(), 314.1592653589793, 1.0E-14);
}
TEST(circle, set_radius_0) {
  Circle c(10);
  c.setRadius(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}
TEST(circle, set_radius_negative) {
  Circle c(10);
  EXPECT_THROW(c.setRadius(-1), std::invalid_argument);
}

TEST(circle, set_ference_10) {
  Circle c(0);
  c.setFerence(10);
  EXPECT_DOUBLE_EQ(c.getFerence(), 10);
  EXPECT_NEAR(c.getRadius(), 1.5915494309189535, 1.0E-14);
  EXPECT_NEAR(c.getArea(), 7.9577471545947676, 1.0E-14);
}
TEST(circle, set_ference_0) {
  Circle c(10);
  c.setFerence(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}
TEST(circle, set_ference_negative) {
  Circle c(10);
  EXPECT_THROW(c.setFerence(-1), std::invalid_argument);
}

TEST(circle, set_area_10) {
  Circle c(0);
  c.setArea(10);
  EXPECT_DOUBLE_EQ(c.getArea(), 10);
  EXPECT_NEAR(c.getRadius(), 1.7841241161527712, 1.0E-14);
  EXPECT_NEAR(c.getFerence(), 11.209982432795858, 1.0E-14);
}
TEST(circle, set_are_0) {
  Circle c(10);
  c.setArea(0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}
TEST(circle, set_are_negative) {
  Circle c(10);
  EXPECT_THROW(c.setArea(-1), std::invalid_argument);
}

TEST(circle, many_sets) {
  Circle c1(10), c2(10);
  c2.setArea(c2.getArea());
  c2.setFerence(c2.getFerence());
  c2.setRadius(c2.getRadius());
  EXPECT_NEAR(c1.getRadius(), c2.getRadius(), 2.0E-14);
  EXPECT_NEAR(c1.getFerence(), c2.getFerence(), 2.0E-14);
  EXPECT_NEAR(c1.getArea(), c2.getArea(), 2.0E-14);
}

TEST(taskRope, default_task) {
  EXPECT_NEAR(ropeTask(6378.1, 0.001), 0.00015915, 1.0E-8);
}
TEST(taskRope, zero_values) { EXPECT_DOUBLE_EQ(ropeTask(0, 0), 0); }
TEST(taskRope, zero_radius) { EXPECT_NEAR(ropeTask(0, 1), 0.15915, 1.0E-5); }
TEST(taskRope, zero_gap) { EXPECT_DOUBLE_EQ(ropeTask(1, 0), 0); }

TEST(taskPool, default_task) {
  EXPECT_NEAR(poolTask(3, 1, 1000, 2000), 72256.631, 1.0E-3);
}
TEST(taskPool, zero_values) {
    EXPECT_DOUBLE_EQ(poolTask(0, 0, 0, 0), 0);
}
TEST(taskPool, zero_pool) {
  EXPECT_NEAR(poolTask(0, 1, 1000, 2000), 15707.963, 1.0E-3);
}
TEST(taskPool, zero_path) {
  EXPECT_NEAR(poolTask(3, 0, 1000, 2000), 37699.111, 1.0E-3);
}
TEST(taskPool, negative_pool) {
  EXPECT_THROW(poolTask(-1, 0, 1000, 2000), std::invalid_argument);
}
TEST(taskPool, negative_path) {
  EXPECT_THROW(poolTask(0, -1, 1000, 2000), std::invalid_argument);
}
