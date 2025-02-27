// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"
#include <cstdint>
#include <cassert>

TEST(cir, constructor_with_positive_radius) {
  Circle c(10);
  EXPECT_FLOAT_EQ(c.getRadius(), 10);
  EXPECT_FLOAT_EQ(c.getFerence(), 62.831853);
  EXPECT_FLOAT_EQ(c.getArea(), 314.159265);
}

TEST(cir, set_radius_updates_properties) {
  Circle c(2);
  c.setRadius(8);
  EXPECT_FLOAT_EQ(c.getRadius(), 8);
  EXPECT_FLOAT_EQ(c.getFerence(), 50.265482);
  EXPECT_FLOAT_EQ(c.getArea(), 201.06193);
}

TEST(cir, set_ference_updates_radius_and_area) {
  Circle c(3);
  c.setFerence(37.699111);
  EXPECT_FLOAT_EQ(c.getRadius(), 6);
  EXPECT_FLOAT_EQ(c.getFerence(), 37.699111);
  EXPECT_FLOAT_EQ(c.getArea(), 113.097336);
}

TEST(cir, set_area_updates_radius_and_ference) {
  Circle c(1);
  c.setArea(50.265482);
  EXPECT_FLOAT_EQ(c.getRadius(), 4);
  EXPECT_FLOAT_EQ(c.getFerence(), 25.132742);
  EXPECT_FLOAT_EQ(c.getArea(), 50.265482);
}

TEST(cir, constructor_with_large_radius) {
  Circle c(100);
  EXPECT_FLOAT_EQ(c.getRadius(), 100);
  EXPECT_FLOAT_EQ(c.getFerence(), 628.318530);
  EXPECT_FLOAT_EQ(c.getArea(), 31415.92654);
}

TEST(cir, set_radius_large_value) {
  Circle c(5);
  c.setRadius(100);
  EXPECT_FLOAT_EQ(c.getRadius(), 100);
  EXPECT_FLOAT_EQ(c.getFerence(), 628.318530);
  EXPECT_FLOAT_EQ(c.getArea(), 31415.92654);
}

TEST(cir, set_ference_large_value) {
  Circle c(1);
  c.setFerence(628.318530);
  EXPECT_FLOAT_EQ(c.getRadius(), 100);
  EXPECT_FLOAT_EQ(c.getFerence(), 628.318530);
  EXPECT_FLOAT_EQ(c.getArea(), 31415.92654);
}

TEST(cir, set_area_large_value) {
  Circle c(1);
  c.setArea(31415.92654);
  EXPECT_FLOAT_EQ(c.getRadius(), 100);
  EXPECT_FLOAT_EQ(c.getFerence(), 628.318530);
  EXPECT_FLOAT_EQ(c.getArea(), 31415.92654);
}

TEST(cir, constructor_throws_on_negative_radius) {
  EXPECT_THROW(Circle(-10), std::invalid_argument);
}

TEST(cir, set_radius_throws_on_negative_value) {
  Circle c(1);
  EXPECT_THROW(c.setRadius(-10), std::invalid_argument);
}

TEST(cir, set_ference_throws_on_negative_value) {
  Circle c(1);
  EXPECT_THROW(c.setFerence(-10), std::invalid_argument);
}

TEST(cir, set_area_throws_on_negative_value) {
  Circle c(1);
  EXPECT_THROW(c.setArea(-10), std::invalid_argument);
}

TEST(cir, constructor_throws_on_zero_radius) {
  EXPECT_THROW(Circle(0), std::invalid_argument);
}

TEST(cir, set_radius_throws_on_zero_value) {
  Circle c(1);
  EXPECT_THROW(c.setRadius(0), std::invalid_argument);
}

TEST(cir, set_ference_throws_on_zero_value) {
  Circle c(1);
  EXPECT_THROW(c.setFerence(0), std::invalid_argument);
}

TEST(cir, set_area_throws_on_zero_value) {
  Circle c(1);
  EXPECT_THROW(c.setArea(0), std::invalid_argument);
}

TEST(task1, calculates_gap_correctly) {
  EXPECT_FLOAT_EQ(calculateGap(1), 0.15915494309189535);
}

TEST(task1, calculates_gap_for_large_length) {
  EXPECT_FLOAT_EQ(calculateGap(100), 15.915494309189533);
}

TEST(task2, calculates_pool_cost_correctly) {
  EXPECT_FLOAT_EQ(calculatePoolCost(3, 1), 72256.633);
}

TEST(task2, calculates_pool_cost_with_different_dimensions) {
  EXPECT_FLOAT_EQ(calculatePoolCost(15, 3), 537212.38);
}
