// Copyright 2025 UNN-CS Team

#include "gtest/gtest.h"
#include <cstdint>
#include "circle.h"

TEST(class_circle, can_create_with_rad_1) {
    Circle c;
    c.setRadius() = 1.0;
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
}
TEST(class_circle, can_get_ference) {
    Circle c;
    c.setRadius() = 1.0;
    EXPECT_NEAR(c.getFerence(), 2*PI);
}
TEST(class_circle, can_get_area) {
    Circle c;
    c.setRadius() = 1.0;
    EXPECT_DOUBLE_EQ(c.getArea(), PI);
}

TEST(class_circle, calculate_ference) {
    Circle c;
    c.setRadius() = 2.0;
    EXPECT_NEAR(c.getFerence(), 4 * PI, 1e-6);
}

TEST(class_circle, calculate_area) {
    Circle c;
    c.setRadius() = 2.0;
    EXPECT_NEAR(c.getArea(), 4 * PI, 1e-6);
}

TEST(class_circle, can_set_ference) {
    Circle c;
    c.setFerence() = 9.0;
    EXPECT_NEAR(c.getRadius(), 1.4323944, 1e-6);
    EXPECT_NEAR(c.getArea(), 9.2328928, 1e-6)
}

TEST(class_circle, can_set_area) {
    Circle c;
    c.setArea() = 9.0;
    EXPECT_NEAR(c.getRadius(), 1.69256875, 1e-6);
    EXPECT_NEAR(c.getFerence(), 10.6347231, 1e-6)
}

TEST(class_circle, can_create_with_rad_0) {
    Circle c;
    c.setRadius() = 0.0;
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(class_circle, can_create_with_large_rad) {
    Circle c;
    c.setRadius() = 100000;
    EXPECT_DOUBLE_EQ(c.getRadius(), 100000);
    EXPECT_NEAR(c.getRadius(), 628318.5307179, 1e-6);
    EXPECT_NEAR(c.getFerence(), 31415926535.8979324, 1e-6)
}
TEST(test_task_1, earth_and_roop) {
    double out = Earth_Roop();
    EXPECT_NEAR(out, 40074.7904909, 1e-6);
}
TEST(test_task_2, pool) {
    double out = Pool(3.0, 1.0);
    EXPECT_NEAR(out, 72256.63, 1e-2);
}
