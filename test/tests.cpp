#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"
#include <cmath> 

const double PI = 3.141592653589793;

TEST(tests, can_create) {
  ASSERT_NO_THROW(Circle(1, 2, 3));
}

TEST(tests, can_get_radius) {
  Circle tmp(1, 2, 3);
  EXPECT_EQ(1, tmp.getRadius());
}

TEST(tests, can_get_ference) {
  Circle tmp(1, 2, 3);
  EXPECT_NEAR(2 * PI * tmp.getRadius(), tmp.getFerence(), 0.0001);
}

TEST(tests, can_get_area) {
  Circle tmp(1, 2, 3);
  EXPECT_NEAR(PI * tmp.getRadius() * tmp.getRadius(), tmp.getArea(), 0.0001);
}

TEST(tests, cant_set_zero_radius) {
  Circle tmp(1, 2, 3);
  tmp.setRadius(0);
  EXPECT_EQ(1, tmp.getRadius());
}

TEST(tests, cant_set_zero_ference) {
  Circle tmp(1, 2, 3);
  tmp.setFerence(0);
  EXPECT_NEAR(2 * PI * tmp.getRadius(), tmp.getFerence(), 0.0001);
}

TEST(tests, cant_set_zero_area) {
  Circle tmp(1, 2, 3);
  tmp.setArea(0);
  EXPECT_NEAR(PI * tmp.getRadius() * tmp.getRadius(), tmp.getArea(), 0.0001);
}

TEST(tests, cant_set_negative_radius) {
  Circle tmp(1, 2, 3);
  tmp.setRadius(-1);
  EXPECT_EQ(1, tmp.getRadius());
}

TEST(tests, cant_set_negative_ference) {
  Circle tmp(1, 2, 3);
  tmp.setFerence(-1);
  EXPECT_NEAR(2 * PI * tmp.getRadius(), tmp.getFerence(), 0.0001);
}

TEST(tests, cant_set_negative_area) {
  Circle tmp(1, 2, 3);
  tmp.setArea(-1);
  EXPECT_NEAR(PI * tmp.getRadius() * tmp.getRadius(), tmp.getArea(), 0.0001);
}

TEST(tests, can_set_radius) {
  Circle tmp(1, 2, 3);
  tmp.setRadius(100);
  EXPECT_EQ(100, tmp.getRadius());
}

TEST(tests, can_set_ference) {
  Circle tmp(1, 2, 3);
  tmp.setFerence(100);
  EXPECT_NEAR(100, tmp.getFerence(), 0.0001);
}

TEST(tests, can_set_area) {
  Circle tmp(1, 2, 3);
  tmp.setArea(100);
  EXPECT_NEAR(100, tmp.getArea(), 0.0001);
}

TEST(tests, set_radius_change_ference) {
  Circle tmp(1, 2, 3);
  tmp.setRadius(100);
  EXPECT_NEAR(2 * PI * 100, tmp.getFerence(), 0.0001);
}

TEST(tests, set_radius_change_area) {
  Circle tmp(1, 2, 3);
  tmp.setRadius(100);
  EXPECT_NEAR(PI * 100 * 100, tmp.getArea(), 0.0001);
}

TEST(tests, set_ference_change_radius) {
  Circle tmp(1, 2, 3);
  tmp.setFerence(100);
  EXPECT_NEAR(100 / (2 * PI), tmp.getRadius(), 0.0001);
}

TEST(tests, set_ference_change_area) {
  Circle tmp(1, 2, 3);
  tmp.setFerence(100);
  EXPECT_NEAR(PI * (100 / (2 * PI)) * (100 / (2 * PI)), tmp.getArea(), 0.0001);
}

TEST(tests, set_area_change_radius) {
  Circle tmp(1, 2, 3);
  tmp.setArea(100);
  EXPECT_NEAR(std::sqrt(100 / PI), tmp.getRadius(), 0.0001);
}

TEST(tests, set_area_change_ference) {
  Circle tmp(1, 2, 3);
  tmp.setArea(100);
  EXPECT_NEAR(2 * PI * std::sqrt(100 / PI), tmp.getFerence(), 0.0001);
}

TEST(tests, can_create_Tasks) {
  ASSERT_NO_THROW(tasks tmp);
}

TEST(tests, can_pool) {
  tasks tmp;
  EXPECT_EQ(0, tmp.pool());
}

TEST(tests, can_rope) {
  tasks tmp;
  EXPECT_NEAR(0.159, tmp.rope(), 0.001);
}
