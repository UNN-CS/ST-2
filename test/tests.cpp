// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, SetRadiusUpdatesAll) {
    Circle c(0);
    c.setRadius(2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 2, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 4, 1e-9);
}

TEST(CircleTest, SetFerenceUpdatesAll) {
    Circle c(0);
    c.setFerence(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0 / (2 * M_PI), 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * pow(10.0 / (2 * M_PI), 2), 1e-9);
}

TEST(EarthRopeTest, Gap) {
    double gap = calculateRopeGap();
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-5);
}

TEST(PoolCostTest, Cost) {
    double cost = calculatePoolCost();
    double expected = (M_PI*(16 - 9))*1000 + (2*M_PI*4)*2000;
    EXPECT_NEAR(cost, expected, 1e-5);
}
