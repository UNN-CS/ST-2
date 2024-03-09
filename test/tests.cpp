// Copyright 2024 Chuvashov Andrey
#include <gtest/gtest.h>
#include <cstdint>
#include "tasks.h"

const double PI = 3.14159;
const double epsilon = 1e-5;

TEST(CircleTests, checkNoRadius) {
    Circle c = Circle(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, checkSmallRadius) {
    Circle c = Circle(7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 7.0 * PI * 2);
    EXPECT_DOUBLE_EQ(c.getArea(), 7.0 * 7.0 * PI);
}

TEST(CircleTests, checkHugeRadius) {
    Circle c = Circle(6810.14);
    EXPECT_DOUBLE_EQ(c.getRadius(), 6810.14);
    EXPECT_DOUBLE_EQ(c.getFerence(), 6810.14 * PI * 2);
    EXPECT_DOUBLE_EQ(c.getArea(), 6810.14 * 6810.14 * PI);
}

TEST(CircleTests, checkSetZeroRadius) {
    Circle c = Circle(1.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, checkSetSmallRadius) {
    Circle c = Circle(1.0);
    c.setRadius(11.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 11.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 11.0 * PI * 2);
    EXPECT_DOUBLE_EQ(c.getArea(), 11.0 * 11.0 * PI);
}

TEST(CircleTests, checkSetHugeRadius) {
    Circle c = Circle(1.0);
    c.setRadius(1429.3);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1429.3);
    EXPECT_DOUBLE_EQ(c.getFerence(), 1429.3 * PI * 2);
    EXPECT_DOUBLE_EQ(c.getArea(), 1429.3 * 1429.3 * PI);
}

TEST(CircleTests, checkSetNegativeRadius) {
    Circle c = Circle(1.0);
    ASSERT_ANY_THROW(c.setRadius(-1.0));
}

TEST(CircleTests, checkSetZeroFerence) {
    Circle c = Circle(1.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, checkSetSmallFerence) {
    Circle c = Circle(1.0);
    c.setFerence(19.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 19.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 19.0 / (2 * PI));
    EXPECT_DOUBLE_EQ(c.getArea(), 19.0 * (19.0 / (2 * PI)) / 2);
}

TEST(CircleTests, checkSetHugeFerence) {
    Circle c = Circle(1.0);
    c.setFerence(95678.193);
    EXPECT_DOUBLE_EQ(c.getFerence(), 95678.193);
    EXPECT_DOUBLE_EQ(c.getRadius(), 95678.193 / (2 * PI));
    EXPECT_DOUBLE_EQ(c.getArea(), 95678.193 * (95678.193 / (2 * PI)) / 2);
}

TEST(CircleTests, checkSetNegativeFerence) {
    Circle c = Circle(1.0);
    ASSERT_ANY_THROW(c.setFerence(-1.0));
}

TEST(CircleTests, checkSetZeroArea) {
    Circle c = Circle(1.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTests, checkSetSmallArea) {
    Circle c = Circle(1.0);
    c.setArea(123.4);
    EXPECT_DOUBLE_EQ(c.getArea(), 123.4);
    EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(123.4 / PI));
    EXPECT_DOUBLE_EQ(c.getFerence(), sqrt(123.4 / PI) * 2 * PI);
}

TEST(CircleTests, checkSetHugeArea) {
    Circle c = Circle(1.0);
    c.setArea(11351.151);
    EXPECT_DOUBLE_EQ(c.getArea(), 11351.151);
    EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(11351.151 / PI));
    EXPECT_DOUBLE_EQ(c.getFerence(), sqrt(11351.151 / PI) * 2 * PI);
}

TEST(CircleTests, checkSetNegativeArea) {
    Circle c = Circle(1.0);
    ASSERT_ANY_THROW(c.setArea(-1.0));
}

TEST(TasksTests, RopeTaskNegativeParams) {
    ASSERT_ANY_THROW(RopeTask(-1.0));
}

TEST(TasksTests, RopeTaskSmall) {
    EXPECT_NEAR(RopeTask(1.0), 40.07475, epsilon);
}

TEST(TasksTests, RopeTaskMiddle) {
    EXPECT_NEAR(RopeTask(100.0), 4007.50645, epsilon);
}

TEST(TasksTests, RopeTaskHuge) {
    EXPECT_NEAR(RopeTask(10000.0), 401061.66258, epsilon);
}

TEST(TasksTests, SwimmingPoolTaskNegativeParams) {
    ASSERT_ANY_THROW(SwimmingPoolTask(-1.0, -1.0));
}

TEST(TasksTests, SwimmingPoolTaskSmall) {
    EXPECT_NEAR(SwimmingPoolTask(3.0, 1.0), 72256.57, epsilon);
}

TEST(TasksTests, SwimmingPoolTaskMiddle) {
    EXPECT_NEAR(SwimmingPoolTask(60.0, 3.0), 1950927.39, epsilon);
}

TEST(TasksTests, SwimmingPoolTaskHuge) {
    EXPECT_NEAR(SwimmingPoolTask(90.0, 5.0), 4099774.95, epsilon);
}
