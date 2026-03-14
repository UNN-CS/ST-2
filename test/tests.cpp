// Copyright 2025 UNN-CS Team

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

// getters
TEST(CircleTest, getRadius) {
  Circle c(10.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

TEST(CircleTest, getFerence) {
  Circle c(10.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * M_PI * 10.0);
}

TEST(CircleTest, getArea) {
  Circle c(10.0);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 100.0);
}

TEST(CircleTest, zeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

// setRadius
TEST(CircleTest, setRadius_getRadius) {
  Circle c(1.0);
  c.setRadius(5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, setRadius_getFerence) {
  Circle c(1.0);
  c.setRadius(5.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * M_PI * 5.0);
}

TEST(CircleTest, setRadius_getArea) {
  Circle c(1.0);
  c.setRadius(5.0);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, setZeroRadius) {
  Circle c(10.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

// setFerence
TEST(CircleTest, setFerence_getFerence) {
  Circle c(1.0);
  c.setFerence(10.0 * M_PI);
  EXPECT_DOUBLE_EQ(c.getFerence(), 10.0 * M_PI);
}

TEST(CircleTest, setFerence_getRadius) {
  Circle c(1.0);
  c.setFerence(10.0 * M_PI);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, setFerence_getArea) {
  Circle c(1.0);
  c.setFerence(10.0 * M_PI);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, setZeroFerence) {
  Circle c(10.0);
  c.setFerence(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

// setArea
TEST(CircleTest, setArea_getArea) {
  Circle c(1.0);
  c.setArea(25.0 * M_PI);
  EXPECT_DOUBLE_EQ(c.getArea(), 25.0 * M_PI);
}

TEST(CircleTest, setArea_getRadius) {
  Circle c(1.0);
  c.setArea(25.0 * M_PI);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, setArea_getFerence) {
  Circle c(1.0);
  c.setArea(25.0 * M_PI);
  EXPECT_DOUBLE_EQ(c.getFerence(), 10.0 * M_PI);
}

TEST(CircleTest, setZeroArea) {
  Circle c(10.0);
  c.setArea(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

// setting the same value
TEST(CircleTest, getRadius_setRadius) {
  Circle c(1.0);
  c.setRadius(c.getRadius());
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * M_PI);
}

TEST(CircleTest, getFerence_setFerence) {
  Circle c(1.0);
  c.setFerence(c.getFerence());
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
}

TEST(CircleTest, getArea_setArea) {
  Circle c(1.0);
  c.setArea(c.getArea());
  EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * M_PI);
}

// tasks
TEST(TasksTest, earthRope) {
  double gap = earthRope();
  double expected = 1.0 / (2.0 * M_PI);
  EXPECT_NEAR(gap, expected, 1e-10);
}

TEST(TasksTest, poolMaterialsPath) {
  double cost = poolMaterialsPath();
  double expected = (M_PI * 16.0 - M_PI * 9.0) * 1000.0;
  EXPECT_DOUBLE_EQ(cost, expected);
}

TEST(TasksTest, poolMaterialsFence) {
  double cost = poolMaterialsFence();
  double expected = (2.0 * M_PI * 4.0) * 2000.0;
  EXPECT_DOUBLE_EQ(cost, expected);
}

TEST(TasksTest, poolMaterials) {
  double cost = poolMaterials();
  double path = (M_PI * 16.0 - M_PI * 9.0) * 1000.0;
  double fence = (2.0 * M_PI * 4.0) * 2000.0;
  double expected = path + fence;
  EXPECT_DOUBLE_EQ(cost, expected);
}
