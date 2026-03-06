// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

// --- ТЕСТЫ КЛАССА CIRCLE ---

TEST(CircleClass, ConstructorInit) {
    Circle c(10.0);
    EXPECT_NEAR(10.0, c.getRadius(), 0.0001);
}

TEST(CircleClass, SetRadiusUpdatesFerence) {
    Circle c(0);
    c.setRadius(5.0);
    EXPECT_NEAR(31.4159, c.getFerence(), 0.0001);
}

TEST(CircleClass, SetRadiusUpdatesArea) {
    Circle c(0);
    c.setRadius(5.0);
    EXPECT_NEAR(78.5398, c.getArea(), 0.0001);
}

TEST(CircleClass, SetFerenceUpdatesRadius) {
    Circle c(0);
    c.setFerence(62.8318);
    EXPECT_NEAR(10.0, c.getRadius(), 0.0001);
}

TEST(CircleClass, SetFerenceUpdatesArea) {
    Circle c(0);
    c.setFerence(62.8318);
    EXPECT_NEAR(314.1592, c.getArea(), 0.0001);
}

TEST(CircleClass, SetAreaUpdatesRadius) {
    Circle c(0);
    c.setArea(314.1592);
    EXPECT_NEAR(10.0, c.getRadius(), 0.0001);
}

TEST(CircleClass, SetAreaUpdatesFerence) {
    Circle c(0);
    c.setArea(78.5398);
    EXPECT_NEAR(31.4159, c.getFerence(), 0.0001);
}

TEST(CircleClass, SmallRadius) {
    Circle c(0.001);
    EXPECT_NEAR(0.00000314, c.getArea(), 0.00000001);
}

TEST(CircleClass, LargeValue) {
    Circle c(1e6);
    EXPECT_GT(c.getArea(), 1e12);
}

TEST(CircleClass, SequenceUpdate) {
    Circle c(10);
    c.setFerence(20);
    c.setRadius(5);
    EXPECT_NEAR(5.0, c.getRadius(), 0.0001);
    EXPECT_NEAR(78.5398, c.getArea(), 0.0001);
}

// --- ТЕСТЫ ЗАДАЧИ "ЗЕМЛЯ И ВЕРЕВКА" ---

TEST(EarthTask, StandardGap) {
    double gap = calculateEarthGap(6378.1, 1.0);
    EXPECT_NEAR(0.1591, gap, 0.001);
}

TEST(EarthTask, LargeGap) {
    double gap = calculateEarthGap(6378.1, 1000.0);
    EXPECT_NEAR(159.1549, gap, 0.001);
}

TEST(EarthTask, MoonGap) {
    double gap = calculateEarthGap(1737.0, 1.0);
    EXPECT_NEAR(0.1591, gap, 0.001);
}

// --- ТЕСТЫ ЗАДАЧИ "БАССЕЙН" ---

TEST(PoolTask, ConcreteCostStandard) {
    Pool res = calculateCostOfPool(3.0, 1.0);
    EXPECT_NEAR(21991.14, res.costOfRoad, 0.1);
}

TEST(PoolTask, FenceCostStandard) {
    Pool res = calculateCostOfPool(3.0, 1.0);
    EXPECT_NEAR(50265.48, res.costOfFence, 0.1);
}

TEST(PoolTask, ZeroPathWidth) {
    Pool res = calculateCostOfPool(5.0, 0.0);
    EXPECT_NEAR(0.0, res.costOfRoad, 0.0001);
}

TEST(PoolTask, NarrowPath) {
    Pool res = calculateCostOfPool(3.0, 0.1);
    EXPECT_NEAR(1916.37, res.costOfRoad, 0.1);
}

TEST(PoolTask, LargePool) {
    Pool res = calculateCostOfPool(10.0, 2.0);
    EXPECT_NEAR(138230.0, res.costOfRoad, 1.0);
}

TEST(PoolTask, PriceRatio) {
    Pool res = calculateCostOfPool(3.0, 1.0);
    EXPECT_GT(res.costOfFence, res.costOfRoad);
}

TEST(PoolTask, FenceLinearGrowth) {
    Pool res1 = calculateCostOfPool(1.0, 1.0);
    Pool res2 = calculateCostOfPool(3.0, 1.0);
    EXPECT_NEAR(res1.costOfFence * 2, res2.costOfFence, 0.0001);
}
