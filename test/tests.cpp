// Copyright 2024 Marina Saratova

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

const double PI = 4 * std::atan(1.0);

TEST(Marina_Saratova_Test_Circle, ference_set_test) {
    Circle c(10);
    ASSERT_DOUBLE_EQ(10 * 2 * PI, c.getFerence());
}

TEST(Marina_Saratova_Test_Circle, area_set_test) {
    Circle c(10);
    ASSERT_DOUBLE_EQ(10 * 10 * PI, c.getArea());
}

TEST(Marina_Saratova_Test_Circle, construcor_test) {
    Circle c(10);
    ASSERT_DOUBLE_EQ(10, c.getRadius());
}

TEST(Marina_Saratova_Test_Circle, ference_setter) {
    double ference = 30.42;
    Circle c;
    c.setFerence(ference);
    ASSERT_DOUBLE_EQ(ference, c.getFerence());
}

TEST(Marina_Saratova_Test_Circle, area_setter) {
    double area = 40.23;
    Circle c;
    c.setArea(area);
    ASSERT_DOUBLE_EQ(area, c.getArea());
}

TEST(Marina_Saratova_Test_Circle, radius_setter) {
    double radius = 20;
    Circle c;
    c.setRadius(radius);
    ASSERT_DOUBLE_EQ(radius, c.getRadius());
}

TEST(Marina_Saratova_Test_Circle, test_rad_after_area) {
    double area = 40.23;
    Circle c;
    c.setArea(area);
    ASSERT_DOUBLE_EQ(sqrt(area / PI), c.getRadius());
}

TEST(Marina_Saratova_Test_Circle, test_ference_after_rad) {
    double radius = 20;
    Circle c;
    c.setRadius(radius);
    ASSERT_DOUBLE_EQ(radius * 2 * PI, c.getFerence());
}

TEST(Marina_Saratova_Test_Circle, test_area_after_rad) {
    double radius = 20;
    Circle c;
    c.setRadius(radius);
    ASSERT_DOUBLE_EQ(radius * radius * PI, c.getArea());
}

TEST(Marina_Saratova_Test_Circle, test_area_after_fer) {
    double ference = 30.42;
    Circle c;
    c.setFerence(ference);
    ASSERT_DOUBLE_EQ(pow(ference / 2 / PI, 2) * PI, c.getArea());
}

TEST(Marina_Saratova_Test_Circle, test_rad_after_fer) {
    double ference = 30.42;
    Circle c;
    c.setFerence(ference);
    ASSERT_DOUBLE_EQ(ference / 2 / PI, c.getRadius());
}

TEST(Marina_Saratova_Test_Circle, test_fer_after_area) {
    double area = 40.23;
    Circle c;
    c.setArea(area);
    ASSERT_DOUBLE_EQ(sqrt(area / PI) * 2 * PI, c.getFerence());
}

TEST(Marina_Saratova_Test_Circle, set_negative_rad) {
    Circle c;
    ASSERT_ANY_THROW(c.setRadius(-10));
}

TEST(Marina_Saratova_Test_Circle, set_negative_fer) {
    Circle c;
    ASSERT_ANY_THROW(c.setFerence(-10.2));
}

TEST(Marina_Saratova_Test_Circle, set_negative_area) {
    Circle c;
    ASSERT_ANY_THROW(c.setArea(-203.21));
}

TEST(Marina_Saratova_Test_Circle, check_ferecnde_with_equal_rad) {
    double radius = 20.34;
    Circle c1(radius), c2(radius);
    ASSERT_DOUBLE_EQ(c1.getFerence(), c2.getFerence());
}

TEST(Marina_Saratova_Test_Circle, create_negative_radius) {
    ASSERT_ANY_THROW(Circle(-23.2));
}

TEST(Marina_Saratova_Test_Circle, check_area_with_equal_rad) {
    double radius = 10.2;
    Circle c1(radius), c2(radius);
    ASSERT_DOUBLE_EQ(c1.getArea(), c2.getArea());
}

TEST(Marina_Saratova_Test_Circle, first_task) {
    double earthRadiusMeters = 6378.1 * 1e3;
    double startRopeMeters = earthRadiusMeters * 2 * PI;
    double actualResultMeters = (startRopeMeters + 1)
        / 2 / PI - earthRadiusMeters;

    ASSERT_DOUBLE_EQ(EarthAndRopeSolve(earthRadiusMeters, 1)
        , actualResultMeters);
}

TEST(Marina_Saratova_Test_Circle, second_task) {
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
