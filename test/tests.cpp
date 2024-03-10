// Copyright 2024 Alexandr Kutarin
#include <gtest/gtest.h>
#include <cstdint>
#include "tasks.h"

const double PI = 4 * std::atan(1.0);

TEST(circle, check_radius) {
    Circle c(10);
    ASSERT_DOUBLE_EQ(10, c.getRadius());
}
TEST(circle, check_area) {
    Circle c(10);
    ASSERT_DOUBLE_EQ(10 * 10 * PI, c.getArea());
}
TEST(circle, check_ference) {
    Circle c(10);
    ASSERT_DOUBLE_EQ(10 * 2 * PI, c.getFerence());
}
TEST(circle, set_radius) {
    double radius = 20;
    Circle c;
    c.setRadius(radius);
    ASSERT_DOUBLE_EQ(radius, c.getRadius());
}
TEST(circle, set_area) {
    double area = 40.23;
    Circle c;
    c.setArea(area);
    ASSERT_DOUBLE_EQ(area, c.getArea());
}
TEST(circle, set_ference) {
    double ference = 30.42;
    Circle c;
    c.setFerence(ference);
    ASSERT_DOUBLE_EQ(ference, c.getFerence());
}
TEST(circle, set_raduis_check_area) {
    double radius = 20;
    Circle c;
    c.setRadius(radius);
    ASSERT_DOUBLE_EQ(radius * radius * PI, c.getArea());
}
TEST(circle, set_raduis_check_ferecne) {
    double radius = 20;
    Circle c;
    c.setRadius(radius);
    ASSERT_DOUBLE_EQ(radius * 2 * PI, c.getFerence());
}
TEST(circle, set_area_check_radius) {
    double area = 40.23;
    Circle c;
    c.setArea(area);
    ASSERT_DOUBLE_EQ(sqrt(area / PI), c.getRadius());
}
TEST(circle, set_area_check_ferecne) {
    double area = 40.23;
    Circle c;
    c.setArea(area);
    ASSERT_DOUBLE_EQ(sqrt(area / PI) * 2 * PI, c.getFerence());
}
TEST(circle, set_ference_check_radius) {
    double ference = 30.42;
    Circle c;
    c.setFerence(ference);
    ASSERT_DOUBLE_EQ(ference / 2 / PI, c.getRadius());
}
TEST(circle, set_ference_check_area) {
    double ference = 30.42;
    Circle c;
    c.setFerence(ference);
    ASSERT_DOUBLE_EQ(pow(ference / 2 / PI, 2) * PI, c.getArea());
}
TEST(circle, set_negative_radius) {
    Circle c;
    ASSERT_ANY_THROW(c.setRadius(-10));
}
TEST(circle, set_negative_area) {
    Circle c;
    ASSERT_ANY_THROW(c.setArea(-203.21));
}
TEST(circle, set_negative_ference) {
    Circle c;
    ASSERT_ANY_THROW(c.setFerence(-10.2));
}
TEST(circle, create_negative_radius) {
    ASSERT_ANY_THROW(Circle(-23.2));
}
TEST(circle, check_area_two_circles_with_equal_radius) {
    double radius = 10.2;
    Circle c1(radius), c2(radius);
    ASSERT_DOUBLE_EQ(c1.getArea(), c2.getArea());
}
TEST(circle, check_ferecnde_two_circles_with_equal_radius) {
    double radius = 20.34;
    Circle c1(radius), c2(radius);
    ASSERT_DOUBLE_EQ(c1.getFerence(), c2.getFerence());
}


TEST(tasks, earth_and_rope) {
    double earthRadiusMeters = 6378.1 * 1e3;
    double startRopeMeters = earthRadiusMeters * 2 * PI;
    double actualResultMeters = (startRopeMeters + 1)
    / 2 / PI - earthRadiusMeters;

    ASSERT_DOUBLE_EQ(EarthAndRopeSolve(earthRadiusMeters, 1)
    , actualResultMeters);
}
TEST(tasks, swimming_pool) {
    double poolRadius = 3;
    double areaWidth = 1;

    double meterFencePrice = 2000;
    double squareMeterAreaPrice = 1000;

    double fencePrice = 2 * PI * (poolRadius + areaWidth) * meterFencePrice;
    double areaPrice = PI * areaWidth * (areaWidth + 2 * poolRadius)
        * squareMeterAreaPrice;

    ASSERT_DOUBLE_EQ(
        SwimmingPoolSolve(poolRadius, areaWidth, squareMeterAreaPrice,
        meterFencePrice), fencePrice + areaPrice);
}
