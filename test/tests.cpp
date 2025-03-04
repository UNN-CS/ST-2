// Copyright 2025 Kalinin Dmitriy
#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

const double PI = 4 * std::atan(1.0);

TEST(Kalinin_Test_Circle, radius_constructor)
{
    Circle circle1(20);
    EXPECT_DOUBLE_EQ(20, circle1.getRadius());
    Circle circle2(15);
    EXPECT_DOUBLE_EQ(15, circle2.getRadius());
    Circle circle3(10);
    EXPECT_DOUBLE_EQ(10, circle3.getRadius());
    Circle circle4(2);
    EXPECT_DOUBLE_EQ(2, circle4.getRadius());
    Circle circle5(1);
    EXPECT_DOUBLE_EQ(1, circle5.getRadius());
}

TEST(Kalinin_Test_Circle, area_constructor)
{
    Circle circle1(10);
    EXPECT_DOUBLE_EQ(10 * 10 * PI, circle1.getArea());
    Circle circle2(20);
    EXPECT_DOUBLE_EQ(20 * 20 * PI, circle2.getArea());
    Circle circle3(15);
    EXPECT_DOUBLE_EQ(15 * 15 * PI, circle3.getArea());
    Circle circle4(11);
    EXPECT_DOUBLE_EQ(11 * 11 * PI, circle4.getArea());
    Circle circle5(0);
    EXPECT_DOUBLE_EQ(0 * 0 * PI, circle5.getArea());
}

TEST(Kalinin_Test_Circle, ference_constructor)
{
    Circle circle1(10);
    EXPECT_DOUBLE_EQ(10 * 2 * PI, circle1.getFerence());
    Circle circle2(1);
    EXPECT_DOUBLE_EQ(1 * 2 * PI, circle2.getFerence());
    Circle circle3(15);
    EXPECT_DOUBLE_EQ(15 * 2 * PI, circle3.getFerence());
    Circle circle4(20);
    EXPECT_DOUBLE_EQ(20 * 2 * PI, circle4.getFerence());
    Circle circle5(30);
    EXPECT_DOUBLE_EQ(30 * 2 * PI, circle5.getFerence());
}

TEST(Kalinin_Test_Circle, radius_setter)
{
    Circle circle1;
    Circle circle2;
    Circle circle3;
    Circle circle4;
    Circle circle5;
    circle1.setRadius(10);
    circle2.setRadius(0);
    circle3.setRadius(15);
    circle4.setRadius(2);
    circle5.setRadius(3);
    EXPECT_DOUBLE_EQ(10, circle1.getRadius());
    EXPECT_DOUBLE_EQ(0, circle2.getRadius());
    EXPECT_DOUBLE_EQ(15, circle3.getRadius());
    EXPECT_DOUBLE_EQ(2, circle4.getRadius());
    EXPECT_DOUBLE_EQ(3, circle5.getRadius());
}

TEST(Kalinin_Test_Circle, area_setter)
{
    Circle circle1;
    Circle circle2;
    Circle circle3;
    Circle circle4;
    Circle circle5;
    circle1.setArea(10);
    circle2.setArea(0);
    circle3.setArea(15);
    circle4.setArea(2);
    circle5.setArea(3);
    EXPECT_DOUBLE_EQ(10, circle1.getArea());
    EXPECT_DOUBLE_EQ(0, circle2.getArea());
    EXPECT_DOUBLE_EQ(15, circle3.getArea());
    EXPECT_DOUBLE_EQ(2, circle4.getArea());
    EXPECT_DOUBLE_EQ(3, circle5.getArea());
}

TEST(Kalinin_Test_Circle, ference_setter)
{
    Circle circle1;
    Circle circle2;
    Circle circle3;
    Circle circle4;
    Circle circle5;
    circle1.setFerence(10);
    circle2.setFerence(0);
    circle3.setFerence(15);
    circle4.setFerence(2);
    circle5.setFerence(3);
    EXPECT_DOUBLE_EQ(10, circle1.getFerence());
    EXPECT_DOUBLE_EQ(0, circle2.getFerence());
    EXPECT_DOUBLE_EQ(15, circle3.getFerence());
    EXPECT_DOUBLE_EQ(2, circle4.getFerence());
    EXPECT_DOUBLE_EQ(3, circle5.getFerence());
}

TEST(Kalinin_Test_Circle, check_area_after_setting_radius)
{
    Circle circle1;
    circle1.setRadius(20);
    Circle circle2;
    circle2.setRadius(0);
    Circle circle3;
    circle3.setRadius(15);
    Circle circle4;
    circle4.setRadius(2);
    Circle circle5;
    circle5.setRadius(3);
    EXPECT_DOUBLE_EQ(20 * 20 * PI, circle1.getArea());
    EXPECT_DOUBLE_EQ(0 * 0 * PI, circle2.getArea());
    EXPECT_DOUBLE_EQ(15 * 15 * PI, circle3.getArea());
    EXPECT_DOUBLE_EQ(2 * 2 * PI, circle4.getArea());
    EXPECT_DOUBLE_EQ(3 * 3 * PI, circle5.getArea());
}

TEST(Kalinin_Test_Circle, set_radius_check_ferecne)
{
    Circle circle1;
    circle1.setRadius(20);
    Circle circle2;
    circle2.setRadius(0);
    Circle circle3;
    circle3.setRadius(15);
    Circle circle4;
    circle4.setRadius(2);
    Circle circle5;
    circle5.setRadius(3);
    EXPECT_DOUBLE_EQ(20 * 2 * PI, circle1.getFerence());
    EXPECT_DOUBLE_EQ(0 * 2 * PI, circle2.getFerence());
    EXPECT_DOUBLE_EQ(15 * 2 * PI, circle3.getFerence());
    EXPECT_DOUBLE_EQ(2 * 2 * PI, circle4.getFerence());
    EXPECT_DOUBLE_EQ(3 * 2 * PI, circle5.getFerence());
}

TEST(Kalinin_Test_Circle, check_radius_after_settign_area)
{
    Circle circle1;
    circle1.setArea(20);
    Circle circle2;
    circle2.setArea(0);
    Circle circle3;
    circle3.setArea(15);
    Circle circle4;
    circle4.setArea(2);
    Circle circle5;
    circle5.setArea(3);
    EXPECT_DOUBLE_EQ(sqrt(20 / PI), circle1.getRadius());
    EXPECT_DOUBLE_EQ(sqrt(0 / PI), circle2.getRadius());
    EXPECT_DOUBLE_EQ(sqrt(15 / PI), circle3.getRadius());
    EXPECT_DOUBLE_EQ(sqrt(2 / PI), circle4.getRadius());
    EXPECT_DOUBLE_EQ(sqrt(3 / PI), circle5.getRadius());
}

TEST(Kalinin_Tasks, earth_and_rope_task)
{
    double earthRadiusMeters = 6378.1 * 1e3;
    double startRopeMeters = earthRadiusMeters * 2 * PI;
    double actualResultMeters = (startRopeMeters + 1) / 2 / PI - earthRadiusMeters;

    EXPECT_DOUBLE_EQ(EarthAndRopeTask(1), actualResultMeters);
}

TEST(Kalinin_Tasks, swimming_pool)
{
    double fencePrice = 2 * PI * (3 + 1) * 2000;
    double areaPrice = PI * 1 * (1 + 2 * 3) * 1000;

    ASSERT_DOUBLE_EQ(
        SwimmingPoolTask(3, 1, 1000,
                         2000),
        fencePrice + areaPrice);
}
