// Copyright 2024 Timofey Vinichuk

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>

#include "circle.h"
#include "tasks.h"


TEST(Circle, test_null) {
    ASSERT_THROW(circle c1 = circle(0); , std::invalid_argument);
    ASSERT_THROW(circle c2 = circle(-10); , std::invalid_argument);
}

TEST(Circle, test_correct_constr1) {
    circle c = circle(1);
    ASSERT_EQ(1, c.getRadius());
    ASSERT_EQ(2 * M_PI, c.getFerence());
    ASSERT_EQ(M_PI, c.getArea());
}

TEST(Circle, test_correct_constr2) {
    circle c = circle(4);
    ASSERT_EQ(4, c.getRadius());
    ASSERT_EQ(8 * M_PI, c.getFerence());
    ASSERT_EQ(M_PI * 16, c.getArea());
}

TEST(Circle, test_correct_constr3) {
    circle c = circle(100);
    ASSERT_EQ(100, c.getRadius());
    ASSERT_EQ(200 * M_PI, c.getFerence());
    ASSERT_EQ(M_PI * 10000, c.getArea());
}

TEST(Circle, test_negative_radius) {
    circle c = circle(1);
    ASSERT_THROW(c.setRadius(-1); , std::invalid_argument);
    ASSERT_THROW(c.setRadius(0); , std::invalid_argument);
}

TEST(Circle, test_negative_ference) {
    circle c = circle(1);
    ASSERT_THROW(c.setFerence(-1); , std::invalid_argument);
    ASSERT_THROW(c.setFerence(0); , std::invalid_argument);
}

TEST(Circle, test_negative_area) {
    circle c = circle(1);
    ASSERT_THROW(c.setArea(-1); , std::invalid_argument);
    ASSERT_THROW(c.setArea(0); , std::invalid_argument);
}

TEST(Circle, test_set_radius_1) {
    circle c = circle(1);
    c.setRadius(4);
    ASSERT_EQ(4, c.getRadius());
    ASSERT_EQ(8 * M_PI, c.getFerence());
    ASSERT_EQ(M_PI * 16, c.getArea());
}

TEST(Circle, test_set_radius_2) {
    circle c = circle(1);
    c.setRadius(100);
    ASSERT_EQ(100, c.getRadius());
    ASSERT_EQ(200 * M_PI, c.getFerence());
    ASSERT_EQ(M_PI * 10000, c.getArea());
}

TEST(Circle, test_set_ference_1) {
    circle c = circle(1);
    c.setFerence(4);
    ASSERT_EQ(4, c.getFerence());
    ASSERT_EQ(4 / (2 * M_PI), c.getRadius());
    ASSERT_EQ(16 / (4 * M_PI), c.getArea());
}

TEST(Circle, test_set_ference_2) {
    circle c = circle(1);
    c.setFerence(100);
    ASSERT_EQ(100, c.getFerence());
    ASSERT_EQ(100 / (2 * M_PI), c.getRadius());
    ASSERT_EQ(M_PI * c.getRadius() * c.getRadius(), c.getArea());
}

TEST(Circle, test_set_area_1) {
    circle c = circle(1);
    c.setArea(4);
    ASSERT_EQ(4, c.getArea());
    ASSERT_EQ(sqrt(4 / M_PI), c.getRadius());
    ASSERT_EQ(2 * M_PI * c.getRadius(), c.getFerence());
}

TEST(Circle, test_set_area_2) {
    circle c = circle(1);
    c.setArea(100);
    ASSERT_EQ(100, c.getArea());
    ASSERT_EQ(sqrt(100 / M_PI), c.getRadius());
    ASSERT_EQ(2 * M_PI * c.getRadius(), c.getFerence());
}

TEST(Task, task_earth_and_rope_negative) {
    ASSERT_THROW(EarthAndRope(-1); , std::invalid_argument);
    ASSERT_THROW(EarthAndRope(-100); , std::invalid_argument);
}

TEST(Task, task_earth_and_rope) {
    ASSERT_NEAR(1 / (2 * M_PI), EarthAndRope(1), 1e-7);
}

TEST(Task, task_swimming_pool_road_negative) {
    ASSERT_THROW(SwimmingPoolRoad(-1, 23, 234); , std::invalid_argument);
    ASSERT_THROW(SwimmingPoolRoad(1, -23, 234); , std::invalid_argument);
    ASSERT_THROW(SwimmingPoolRoad(1, 23, -234); , std::invalid_argument);
    ASSERT_THROW(SwimmingPoolRoad(0, 23, 234); , std::invalid_argument);
    ASSERT_THROW(SwimmingPoolRoad(1, 0, 234); , std::invalid_argument);
    ASSERT_THROW(SwimmingPoolRoad(1, 23, 0); , std::invalid_argument);
}


TEST(Task, task_swimming_pool_fence_negative) {
    ASSERT_THROW(SwimmingPoolFence(1, -23); , std::invalid_argument);
    ASSERT_THROW(SwimmingPoolFence(-23, 234); , std::invalid_argument);
}

TEST(Task, task_swimming_pool_fence_and_road) {
    circle c = circle(1);

    ASSERT_EQ(6 * M_PI * 2000 + 7 * M_PI * 1000, SwimmingPoolRoad(3, 1, 1000) +
        SwimmingPoolFence(3, 2000));
}







