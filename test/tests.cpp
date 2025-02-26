// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>

#include "tasks.hpp"

TEST(circle_Task, testCircleCreate1) {
  Circle circle;
  ASSERT_EQ(circle.SetRadius(10.0), true);
}

TEST(circle_Task, testCircleCreate2) {
  Circle circle;
  ASSERT_EQ(circle.SetRadius(-5.0), false);
}

TEST(circle_Task, testCircleCreate3) {
  Circle circle;
  ASSERT_EQ(circle.SetFerence(-5.0), false);
}

TEST(circle_Task, testCircleCreate4) {
  Circle circle;
  ASSERT_EQ(circle.SetFerence(50.0), true);
}

TEST(circle_Task, testCircleCreate5) {
  Circle circle;
  ASSERT_EQ(circle.SetArea(50.0), true);
}

TEST(circle_Task, testCircleCreate6) {
  Circle circle;
  ASSERT_EQ(circle.SetArea(-50.0), false);
}

TEST(circle_Task, testCircleCreate7) {
  constexpr auto kEpsilon = 0.0001;
  constexpr auto kRadius = 5.0;
  constexpr auto kExpectedFence = 31.4159;
  constexpr auto kExpectedArea = 78.5398;
  Circle circle(kRadius);
  EXPECT_NEAR(kExpectedFence, circle.GetFerence(), kEpsilon);
  EXPECT_NEAR(kExpectedArea, circle.GetArea(), kEpsilon);
}

TEST(circle_Task, testCircleCreate8) {
  constexpr auto kEpsilon = 0.001;
  constexpr auto kRadius = 6.0;
  constexpr auto kExpectedFence = 37.6991;
  constexpr auto kExpectedArea = 113.097;
  Circle circle(kRadius);
  EXPECT_NEAR(kExpectedFence, circle.GetFerence(), kEpsilon);
  EXPECT_NEAR(kExpectedArea, circle.GetArea(), kEpsilon);
}

TEST(circle_Task, testCircleCreate9) {
  constexpr auto kEpsilon = 0.001;
  constexpr auto kRadius = 0.1;
  constexpr auto kExpectedFence = 0.6283;
  constexpr auto kExpectedArea = 0.031415;
  Circle circle(kRadius);
  EXPECT_NEAR(kExpectedFence, circle.GetFerence(), kEpsilon);
  EXPECT_NEAR(kExpectedArea, circle.GetArea(), kEpsilon);
}

TEST(circle_Task, testCircleCreate10) {
  constexpr auto kEpsilon = 0.001;
  constexpr auto kRadius = 15.0;
  constexpr auto kExpectedFence = 94.2478;
  constexpr auto kExpectedArea = 706.858;
  Circle circle(kRadius);
  EXPECT_NEAR(kExpectedFence, circle.GetFerence(), kEpsilon);
  EXPECT_NEAR(kExpectedArea, circle.GetArea(), kEpsilon);
}

TEST(circle_Task, testCircleCreate11) {
  constexpr auto kEpsilon = 0.001;
  constexpr auto kRadius = 2.0;
  constexpr auto kExpectedFence = 12.5664;
  constexpr auto kExpectedArea = 12.5664;
  Circle circle(kRadius);
  EXPECT_NEAR(kExpectedFence, circle.GetFerence(), kEpsilon);
  EXPECT_NEAR(kExpectedArea, circle.GetArea(), kEpsilon);
}

TEST(circle_Task, testTask1) {
  constexpr auto kEpsilon = 0.001;
  auto kExpectedNumber = 0.1591;
  EXPECT_NEAR(kExpectedNumber, GetGap(), kEpsilon);
}

TEST(circle_Task, testTask2) {
  constexpr auto kEpsilon = 0.001;
  auto kExpectedNumber = 72256.6297;
  EXPECT_NEAR(kExpectedNumber, GetSwimingPoolBuildingCost(), kEpsilon);
}
