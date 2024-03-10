// Copyright 2024 Khramov Ivan
#include <gtest/gtest.h>
#include <cstdint>
#include "../include/circle.h"
#include "../include/tasks.h"

double PI = std::acos(-1.0);

TEST(TEST_CLASS_CIRCLE, TEST_GET_RADIUS) {
    double radius = 5;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    EXPECT_EQ(circle->GetRadius(), radius);
}

TEST(TEST_CLASS_CIRCLE, TEST_GET_FERENCE) {
    double radius = 5;
    double ference = 2 * PI * radius;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    EXPECT_EQ(circle->GetFerence(), ference);
}

TEST(TEST_CLASS_CIRCLE, TEST_GET_AREA) {
    double radius = 5;
    double area = PI * pow(radius, 2);
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    EXPECT_EQ(circle->GetArea(), area);
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_RADIUS) {
    double radius = 5;
    double radius2 = 10;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetRadius(radius2);
    EXPECT_EQ(circle->GetRadius(), radius2);
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_FERENCE) {
    double radius = 5;
    double ference2 = 10;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetFerence(ference2);
    EXPECT_EQ(circle->GetFerence(), ference2);
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_AREA) {
    double radius = 5;
    double area2 = 10;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetArea(area2);
    EXPECT_EQ(circle->GetArea(), area2);
}

TEST(TEST_CLASS_CIRCLE, TEST_RADIUS_NEGATIVE_CONSTRUCTOR) {
    double radius = -5;
    ASSERT_ANY_THROW(new Circle(radius));
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_RADIUS_NEGATIVE) {
    double radius = 5;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    ASSERT_ANY_THROW(circle->SetRadius(-5));
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_FERENCE_NEGATIVE) {
    double radius = 5;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    ASSERT_ANY_THROW(circle->SetFerence(-100));
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_AREA_NEGATIVE) {
    double radius = 5;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    ASSERT_ANY_THROW(circle->SetArea(-100));
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_RADIUS_GET_FERENCE) {
    double radius = 5;
    double radius2 = 10;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetRadius(radius2);
    double ference2 = 2 * PI * radius2;
    ASSERT_EQ(circle->GetFerence(), ference2);
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_RADIUS_GET_AREA) {
    double radius = 5;
    double radius2 = 10;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetRadius(radius2);
    double area2 = PI * pow(radius2, 2);
    ASSERT_EQ(circle->GetArea(), area2);
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_FERENCE_GET_RADIUS) {
    double radius = 5;
    double ference2 = 100;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetFerence(ference2);
    double radius2 = ference2 / (2 * PI);
    ASSERT_EQ(circle->GetRadius(), radius2);
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_FERENCE_GET_AREA) {
    double radius = 5;
    double ference2 = 100;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetFerence(ference2);
    double area2 = PI * pow(circle->GetRadius(), 2);
    ASSERT_EQ(circle->GetArea(), area2);
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_AREA_GET_RADIUS) {
    double radius = 5;
    double area2 = 100;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetArea(area2);
    double radius2 = sqrt(area2 / PI);
    ASSERT_EQ(circle->GetRadius(), radius2);
}

TEST(TEST_CLASS_CIRCLE, TEST_SET_AREA_GET_FERENCE) {
    double radius = 5;
    double radius2 = 100;
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(radius);
    circle->SetArea(radius2);
    double ference2 = 2 * PI * circle->GetRadius();
    ASSERT_EQ(circle->GetFerence(), ference2);
}

TEST(TEST_CLASS_CIRCLE, TEST_TWO_EQUAL_OBJECTS_RADIUS) {
    double radius1 = 5;
    double radius2 = 5;
    std::unique_ptr<Circle> circle1 = std::make_unique<Circle>(radius1);
    std::unique_ptr<Circle> circle2 = std::make_unique<Circle>(radius2);
    ASSERT_EQ(circle1->GetRadius(), circle2->GetRadius());
}

TEST(TEST_CLASS_CIRCLE, TEST_TWO_EQUAL_OBJECTS_FERENCE) {
    double radius1 = 5;
    double radius2 = 5;
    std::unique_ptr<Circle> circle1 = std::make_unique<Circle>(radius1);
    std::unique_ptr<Circle> circle2 = std::make_unique<Circle>(radius2);
    ASSERT_EQ(circle1->GetFerence(), circle2->GetFerence());
}

TEST(TEST_CLASS_CIRCLE, TEST_TWO_EQUAL_OBJECTS_AREA) {
    double radius1 = 5;
    double radius2 = 5;
    std::unique_ptr<Circle> circle1 = std::make_unique<Circle>(radius1);
    std::unique_ptr<Circle> circle2 = std::make_unique<Circle>(radius2);
    ASSERT_EQ(circle1->GetArea(), circle2->GetArea());
}

TEST(TEST_TASKS, TEST_EARTH_ROPE_TASK) {
    double earthRadius = 6378.1 * 1e3;
    double delta = 1;
    double eps = 1e-6;

    double solving = EarthAndRopeSolve(earthRadius, delta);

    double correctRes = (2 * PI * earthRadius + delta) / (2 * PI) - earthRadius;
    ASSERT_NEAR(solving, correctRes, eps);
}

TEST(TEST_TASKS, TEST_SWIMMING_POOL_TASK) {
    double poolRadius = 3;
    double trackWidth = 1;
    double meterTrackPrice = 1000;
    double meterFencePrice = 2000;
    double eps = 1e-6;

    double trackArea = PI * (
        pow(poolRadius + trackWidth, 2) - pow(poolRadius, 2));
    double trackPrice = trackArea * meterTrackPrice;
    double fencePrice = 2 * PI * (poolRadius + trackWidth) * meterFencePrice;

    double solving = SwimmingPoolSolve(poolRadius,
                                    trackWidth,
                                    meterTrackPrice,
                                    meterFencePrice);
    ASSERT_NEAR(solving, trackPrice + fencePrice, eps);
}
