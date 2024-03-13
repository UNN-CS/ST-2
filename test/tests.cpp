// Copyright 2024 Smirnov Leonid

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 4 * std::atan(1.0);

TEST(circle, setradius) {
    double radius = 10;
    Circle c;
    c.SetRadius(radius);
    ASSERT_DOUBLE_EQ(radius, c.GetRadius());
}

TEST(circle, setference) {
    double ference = 10;
    Circle c;
    c.SetFerence(ference);
    ASSERT_DOUBLE_EQ(ference, c.GetFerence());
}

TEST(circle, setarea) {
    double area = 10;
    Circle c;
    c.SetArea(area);
    ASSERT_DOUBLE_EQ(area, c.GetArea());
}


TEST(circle, cheakingradius) {
    Circle c(3);
    ASSERT_DOUBLE_EQ(3, c.GetRadius());
}

TEST(circle, checkingference) {
    Circle c(3);
    ASSERT_DOUBLE_EQ(3 * 2 * PI, c.GetFerence());
}

TEST(circle, checkingarea) {
    Circle c(3);
    ASSERT_DOUBLE_EQ(3 * 3 * PI, c.GetArea());
}


TEST(circle, createwithnegativeradius) {
    ASSERT_ANY_THROW(Circle(-10));
}

TEST(circle, setnegativeradius) {
    Circle c;
    ASSERT_ANY_THROW(c.SetRadius(-10));
}

TEST(circle, setnegativeference) {
    Circle c;
    ASSERT_ANY_THROW(c.SetFerence(-10));
}

TEST(circle, setnegativearea) {
    Circle c;
    ASSERT_ANY_THROW(c.SetArea(-10));
}


TEST(circle, setraduischeckferecne) {
    double radius = 3;
    Circle c;
    c.SetRadius(radius);
    ASSERT_DOUBLE_EQ(radius * 2 * PI, c.GetFerence());
}

TEST(circle, setraduischeckarea) {
    double radius = 3;
    Circle c;
    c.SetRadius(radius);
    ASSERT_DOUBLE_EQ(radius * radius * PI, c.GetArea());
}

TEST(circle, setareacheckradius) {
    double area = 3;
    Circle c;
    c.SetArea(area);
    ASSERT_DOUBLE_EQ(sqrt(area / PI), c.GetRadius());
}

TEST(circle, setareacheckferecne) {
    double area = 3;
    Circle c;
    c.SetArea(area);
    ASSERT_DOUBLE_EQ(sqrt(area / PI) * 2 * PI, c.GetFerence());
}

TEST(circle, setferencecheckradius) {
    double ference = 3;
    Circle c;
    c.SetFerence(ference);
    ASSERT_DOUBLE_EQ(ference / 2 / PI, c.GetRadius());
}

TEST(circle, setferencecheckarea) {
    double ference = 3;
    Circle c;
    c.SetFerence(ference);
    ASSERT_DOUBLE_EQ(pow(ference / 2 / PI, 2) * PI, c.GetArea());
}

TEST(circle, equalcirclesference) {
    Circle c1(3), c2(3);
    ASSERT_DOUBLE_EQ(c1.GetFerence(), c2.GetFerence());
}

TEST(circle, equalcirclesarea) {
    Circle c1(3), c2(3);
    ASSERT_DOUBLE_EQ(c1.GetArea(), c2.GetArea());
}

TEST(tasks, earthandrope) {
    double earthRadiusMeters = 6378.1 * 1e3;
    double earthL = earthRadiusMeters * 2 * PI;
    double actualResultMeters = (earthL + 1)
        / 2 / PI - earthRadiusMeters;

    ASSERT_DOUBLE_EQ(SolveEarthAndRope(earthRadiusMeters, 1)
        , actualResultMeters);
}

TEST(tasks, swimming_pool) {
    double poolRadius = 3;
    double areaWidth = 1;

    double meterFerencePrice = 2000;
    double squareMeterAreaPrice = 1000;

    double ferencePrice = 2 * PI * (poolRadius + areaWidth)
        * meterFerencePrice;
    double areaPrice = PI * areaWidth * (areaWidth + 2 * poolRadius)
        * squareMeterAreaPrice;

    ASSERT_DOUBLE_EQ(SolveSwimmingPool(poolRadius, areaWidth,
        squareMeterAreaPrice, meterFerencePrice),
        ferencePrice + areaPrice);
}
