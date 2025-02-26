// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

TEST(CircleTest, Constructor) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 25.0, 1e-9);
}

TEST(CircleTest, SetRadius) {
    Circle c(0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 10.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 100.0, 1e-9);
}

TEST(CircleTest, SetFerence) {
    Circle c(0);
    c.setFerence(20.0);
    EXPECT_NEAR(c.getRadius(), 20.0 / (2 * M_PI), 1e-9);
    EXPECT_NEAR(c.getFerence(), 20.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * pow(20.0 / (2 * M_PI), 2), 1e-9);
}

TEST(CircleTest, SetArea) {
    Circle c(0);
    c.setArea(50.0);
    EXPECT_NEAR(c.getRadius(), sqrt(50.0 / M_PI), 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * sqrt(50.0 / M_PI), 1e-9);
    EXPECT_NEAR(c.getArea(), 50.0, 1e-9);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getRadius(), 1e6, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 1e12, 1e-9);
}

TEST(CircleTest, SmallRadius) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getRadius(), 1e-6, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e-6, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 1e-12, 1e-9);
}

TEST(CircleTest, ZeroFerence) {
    Circle c(0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

TEST(CircleTest, ZeroArea) {
    Circle c(0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

// (должен выбрасывать исключение)
TEST(CircleTest, NegativeRadius) {
    Circle c(0);
    EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
}

TEST(CircleTest, NegativeFerence) {
    Circle c(0);
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
}

TEST(CircleTest, NegativeArea) {
    Circle c(0);
    EXPECT_THROW(c.setArea(-50.0), std::invalid_argument);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

TEST(CircleTest, Precision) {
    Circle c(1.0);
    c.setRadius(1.000000001);
    EXPECT_NEAR(c.getRadius(), 1.000000001, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1.000000001, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 1.0000000020000001, 1e-9);
}

TEST(CircleTest, UpdateRadiusFromArea) {
    Circle c(0);
    c.setArea(100.0);
    EXPECT_NEAR(c.getRadius(), sqrt(100.0 / M_PI), 1e-9);
}

TEST(CircleTest, UpdateFerenceFromRadius) {
    Circle c(0);
    c.setRadius(7.0);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 7.0, 1e-9);
}

TEST(EarthRopeTest, GapCalculation) {
    double gap = calculateRopeGap();
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-5);
}

TEST(EarthRopeTest, SmallGap) {
    Circle earth(6378100.0); // Радиус Земли в метрах
    earth.setFerence(earth.getFerence() + 0.001); // Добавляем 1 мм
    double gap = earth.getRadius() - 6378100.0;
    EXPECT_NEAR(gap, 0.001 / (2 * M_PI), 1e-9);
}

TEST(PoolCostTest, ConcreteCost) {
    double cost = calculatePoolCost();
    double expectedConcreteArea = M_PI * (16.0 - 9.0);
    double expectedFenceLength = 2 * M_PI * 4.0;
    double expectedCost = expectedConcreteArea * 1000
                          + expectedFenceLength * 2000;
    EXPECT_NEAR(cost, expectedCost, 1e-5);
}

TEST(PoolCostTest, ZeroWidthPath) {
    Circle pool(3.0);
    Circle outer(3.0); // Ширина дорожки = 0
    double concreteArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getFerence();
    double cost = concreteArea * 1000 + fenceLength * 2000;
    EXPECT_NEAR(cost, 2 * M_PI * 3.0 * 2000, 1e-5); // Только стоимость ограды
}

TEST(PoolCostTest, LargeWidthPath) {
    Circle pool(3.0);
    Circle outer(1003.0); // Ширина дорожки = 1000 м
    double concreteArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getFerence();
    double cost = concreteArea * 1000 + fenceLength * 2000;
    EXPECT_NEAR(cost, (M_PI * (1003.0 * 1003.0 - 9.0)) * 1000
                      + (2 * M_PI * 1003.0) * 2000, 1e-5);
}
