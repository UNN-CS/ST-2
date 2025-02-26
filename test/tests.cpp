// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <stdexcept>
#include "circle.h"
#include "tasks.h"

TEST(circle, ctor) {
  Circle c(5);

  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, setRadius) {
  Circle c(1);

  c.setRadius(5);

  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, setFerence) {
  Circle c(1);

  c.setFerence(31.415926);

  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, setArea) {
  Circle c(1);

  c.setArea(78.539818);

  EXPECT_FLOAT_EQ(c.getRadius(), 5);
  EXPECT_FLOAT_EQ(c.getFerence(), 31.415926);
  EXPECT_FLOAT_EQ(c.getArea(), 78.539818);
}

TEST(circle, ctor2) {
  Circle c(33.33);

  EXPECT_FLOAT_EQ(c.getRadius(), 33.33);
  EXPECT_FLOAT_EQ(c.getFerence(), 209.418566);
  EXPECT_FLOAT_EQ(c.getArea(), 3489.960407);
}

TEST(circle, setRadius2) {
  Circle c(1);

  c.setRadius(33.33);

  EXPECT_FLOAT_EQ(c.getRadius(), 33.33);
  EXPECT_FLOAT_EQ(c.getFerence(), 209.418566);
  EXPECT_FLOAT_EQ(c.getArea(), 3489.960407);
}

TEST(circle, setFerence2) {
  Circle c(1);

  c.setFerence(209.418566);

  EXPECT_FLOAT_EQ(c.getRadius(), 33.33);
  EXPECT_FLOAT_EQ(c.getFerence(), 209.418566);
  EXPECT_FLOAT_EQ(c.getArea(), 3489.960407);
}

TEST(circle, setArea2) {
  Circle c(1);

  c.setArea(3489.960407);

  EXPECT_FLOAT_EQ(c.getRadius(), 33.33);
  EXPECT_FLOAT_EQ(c.getFerence(), 209.418566);
  EXPECT_FLOAT_EQ(c.getArea(), 3489.960407);
}

TEST(circle, ctor_throws_if_radius_is_negative) {
  EXPECT_THROW(Circle(-5), std::invalid_argument);
}

TEST(circle, setRadius_throws_if_radius_is_negative) {
  Circle c(1);

  EXPECT_THROW(c.setRadius(-5), std::invalid_argument);
}

TEST(circle, setFerence_throws_if_radius_is_negative) {
  Circle c(1);

  EXPECT_THROW(c.setFerence(-5), std::invalid_argument);
}

TEST(circle, setArea_throws_if_radius_is_negative) {
  Circle c(1);

  EXPECT_THROW(c.setArea(-5), std::invalid_argument);
}

TEST(circle, ctor_throws_if_radius_is_zero) {
  EXPECT_THROW(Circle(0), std::invalid_argument);
}

TEST(circle, setRadius_throws_if_radius_is_zero) {
  Circle c(1);

  EXPECT_THROW(c.setRadius(0), std::invalid_argument);
}

TEST(circle, setFerence_throws_if_radius_is_zero) {
  Circle c(1);

  EXPECT_THROW(c.setFerence(0), std::invalid_argument);
}

TEST(circle, setArea_throws_if_radius_is_zero) {
  Circle c(1);

  EXPECT_THROW(c.setArea(0), std::invalid_argument);
}

TEST(task1, gives_correct_answer) {
  EXPECT_FLOAT_EQ(task1(6378100, 1), 0.15915494);
}

TEST(task1, gives_correct_answer2) {
  EXPECT_FLOAT_EQ(task1(9999999, 50000), 7957.7471);
}

TEST(task2, gives_correct_answer) {
  EXPECT_FLOAT_EQ(task2(3, 1, 1000, 2000), 72256.633);
}
TEST(task2, gives_correct_answer2) {
  EXPECT_FLOAT_EQ(task2(10.5, 11, 33.33, 22.22), 39859.332);
}
