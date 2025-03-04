// Copyright 2025 Dmitry kavtorev

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

const double PI = 4 * std::atan(1.0);

TEST(Dmitry_Kavtorev_Test_Circle, constructor_default_test) {
    Circle c;
    ASSERT_DOUBLE_EQ(0, c.getRadius());
    ASSERT_DOUBLE_EQ(0, c.getFerence());
    ASSERT_DOUBLE_EQ(0, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, constructor_positive_test) {
    Circle c(5);
    ASSERT_DOUBLE_EQ(5, c.getRadius());
    ASSERT_DOUBLE_EQ(5 * 2 * Circle::PI, c.getFerence());
    ASSERT_DOUBLE_EQ(5 * 5 * Circle::PI, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, setRadius_positive_test) {
    Circle c;
    c.setRadius(7);
    ASSERT_DOUBLE_EQ(7, c.getRadius());
    ASSERT_DOUBLE_EQ(7 * 2 * Circle::PI, c.getFerence());
    ASSERT_DOUBLE_EQ(7 * 7 * Circle::PI, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, setFerence_positive_test) {
    Circle c;
    c.setFerence(31.4);
    ASSERT_DOUBLE_EQ(31.4 / (2 * Circle::PI), c.getRadius());
    ASSERT_DOUBLE_EQ(31.4, c.getFerence());
    ASSERT_DOUBLE_EQ((31.4 / (2 * Circle::PI)) *
     (31.4 / (2 * Circle::PI)) * Circle::PI, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, setArea_positive_test) {
    Circle c;
    c.setArea(78.5);
    ASSERT_DOUBLE_EQ(sqrt(78.5 / Circle::PI), c.getRadius());
    ASSERT_DOUBLE_EQ(2 * Circle::PI * sqrt(78.5 / Circle::PI), c.getFerence());
    ASSERT_DOUBLE_EQ(78.5, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, radius_not_negative_test) {
    ASSERT_THROW(Circle(-1), std::logic_error);
}

TEST(Dmitry_Kavtorev_Test_Circle, setRadius_not_negative_test) {
    Circle c;
    ASSERT_THROW(c.setRadius(-1), std::logic_error);
}

TEST(Dmitry_Kavtorev_Test_Circle, setFerence_not_negative_test) {
    Circle c;
    ASSERT_THROW(c.setFerence(-1), std::logic_error);
}

TEST(Dmitry_Kavtorev_Test_Circle, setArea_not_negative_test) {
    Circle c;
    ASSERT_THROW(c.setArea(-1), std::logic_error);
}

TEST(Dmitry_Kavtorev_Test_Circle, zero_radius_test) {
    Circle c(0);
    ASSERT_DOUBLE_EQ(0, c.getRadius());
    ASSERT_DOUBLE_EQ(0, c.getFerence());
    ASSERT_DOUBLE_EQ(0, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, zero_ference_test) {
    Circle c;
    c.setFerence(0);
    ASSERT_DOUBLE_EQ(0, c.getRadius());
    ASSERT_DOUBLE_EQ(0, c.getFerence());
    ASSERT_DOUBLE_EQ(0, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, zero_area_test) {
    Circle c;
    c.setArea(0);
    ASSERT_DOUBLE_EQ(0, c.getRadius());
    ASSERT_DOUBLE_EQ(0, c.getFerence());
    ASSERT_DOUBLE_EQ(0, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, update_radius_test) {
    Circle c(2);
    c.setRadius(3);
    ASSERT_DOUBLE_EQ(3, c.getRadius());
    ASSERT_DOUBLE_EQ(3 * 2 * Circle::PI, c.getFerence());
    ASSERT_DOUBLE_EQ(3 * 3 * Circle::PI, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, update_ference_test) {
    Circle c(2);
    c.setFerence(37.7);
    ASSERT_DOUBLE_EQ(37.7 / (2 * Circle::PI), c.getRadius());
    ASSERT_DOUBLE_EQ(37.7, c.getFerence());
    ASSERT_DOUBLE_EQ((37.7 / (2 * Circle::PI)) * (37.7 /
     (2 * Circle::PI)) * Circle::PI, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_Circle, update_area_test) {
    Circle c(2);
    c.setArea(50.24);
    ASSERT_DOUBLE_EQ(sqrt(50.24 / Circle::PI), c.getRadius());
    ASSERT_DOUBLE_EQ(2 * Circle::PI * sqrt(50.24 / Circle::PI), c.getFerence());
    ASSERT_DOUBLE_EQ(50.24, c.getArea());
}

TEST(Dmitry_Kavtorev_Test_EarthAndRopeSolve, positive_test) {
    double earthRadius = 6371.0;
    double growth = 10.0;
    double result = EarthAndRopeSolve(earthRadius, growth);
    ASSERT_NEAR(result, growth / (2 * Circle::PI), 1e-6);
}

TEST(Dmitry_Kavtorev_Test_SwimmingPoolSolve, positive_test) {
    double poolRadius = 5.0;
    double areaWidth = 3.0;
    double areaPricePerSquareMeter = 50.0;
    double fencePricePerMeter = 10.0;

    double result = SwimmingPoolSolve(poolRadius, areaWidth,
     areaPricePerSquareMeter, fencePricePerMeter);

    Circle pool(poolRadius);
    Circle poolAndArea(poolRadius + areaWidth);

    double expectedFerencePrice = poolAndArea.getFerence() * fencePricePerMeter;
    double expectedAreaPrice = (poolAndArea.getArea() - pool.getArea()) *
     areaPricePerSquareMeter;
    double expectedTotalPrice = expectedFerencePrice + expectedAreaPrice;

    ASSERT_NEAR(result, expectedTotalPrice, 1e-6);
}
