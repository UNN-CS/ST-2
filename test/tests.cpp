// Copyright 2025 UNN-CS Team
#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"

// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

// Тесты для класса Circle

TEST(CircleTest, ConstructorAndGetters) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, ConstructorZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorNegativeRadius) {
    Circle c(-5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * (-5.0));
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 10.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 100.0);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    double newFerence = 2 * M_PI * 5.0;
    c.setFerence(newFerence);
    EXPECT_DOUBLE_EQ(c.getFerence(), newFerence);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 25.0);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    double newArea = M_PI * 25.0;
    c.setArea(newArea);
    EXPECT_DOUBLE_EQ(c.getArea(), newArea);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTest, CalculationFerence) {
    Circle c(7.0);
    double expected = 2 * M_PI * 7.0;
    EXPECT_DOUBLE_EQ(c.calculationFerence(), expected);
    EXPECT_DOUBLE_EQ(c.getFerence(), expected);
}

TEST(CircleTest, CalculationArea) {
    Circle c(7.0);
    double expected = M_PI * 49.0;
    EXPECT_DOUBLE_EQ(c.calculationArea(), expected);
    EXPECT_DOUBLE_EQ(c.getArea(), expected);
}

TEST(CircleTest, CalculationRadius) {
    Circle c(1.0);
    c.setRadius(1.0);
    c.setFerence(2 * M_PI * 9.0);
    double expected = 9.0;
    EXPECT_DOUBLE_EQ(c.calculationRadius(), expected);
    EXPECT_DOUBLE_EQ(c.getRadius(), expected);
}

TEST(CircleTest, ConsistencyCheck) {
    Circle c(4.0);
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();

    EXPECT_DOUBLE_EQ(f, 2 * M_PI * r);
    EXPECT_DOUBLE_EQ(a, M_PI * r * r);
    EXPECT_DOUBLE_EQ(f * f / (4 * M_PI), a);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e12);
}

TEST(CircleTest, SmallRadius) {
    Circle c(1e-6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1e-6);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1e-12);
}

TEST(CircleTest, SetRadiusThenSetFerence) {
    Circle c(3.0);
    c.setRadius(5.0);
    c.setFerence(2 * M_PI * 7.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 7.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 49.0);
}

TEST(CircleTest, SetAreaThenSetRadius) {
    Circle c(3.0);
    c.setArea(M_PI * 36.0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 2.0);
    EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 4.0);
}

// Тесты для задачи EarthTask

TEST(EarthTaskTest, EarthTaskReturnsOne) {
    double result = EarthTask();
    EXPECT_DOUBLE_EQ(result, 1.0);
}

TEST(EarthTaskTest, EarthTaskCheckRadius) {
    Circle earth(RADIUS_OF_EARTH);
    double originalRadius = earth.getRadius();
    earth.setRadius(RADIUS_OF_EARTH + 1);
    EXPECT_DOUBLE_EQ(earth.getRadius(), originalRadius + 1);
}

TEST(EarthTaskTest, EarthTaskCheckDifference) {
    Circle earth(RADIUS_OF_EARTH);
    double original = earth.getRadius();
    earth.setRadius(original + 1);
    EXPECT_DOUBLE_EQ(earth.getRadius() - original, 1.0);
}

// Тесты для задачи Pool

TEST(PoolTest, PoolReturnsPositive) {
    double result = Pool();
    EXPECT_GT(result, 0.0);
}

TEST(PoolTest, PoolCalculateManually) {
    double poolArea = M_PI * RADIUS_OF_POOL * RADIUS_OF_POOL;
    double roadArea = M_PI * (RADIUS_OF_POOL + WIDTH_OF_ROAD) * (RADIUS_OF_POOL + WIDTH_OF_ROAD) - poolArea;
    double fenceLength = 2 * M_PI * (RADIUS_OF_POOL + WIDTH_OF_ROAD);
    
    double expected = fenceLength * COST_OF_METER_FENCE + roadArea * COST_OF_CONCRETE_COATING;
    double actual = Pool();
    
    EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(PoolTest, PoolWithDifferentValues) {
    double testRadius = 5.0;
    double testWidth = 2.0;
    double testFenceCost = 1500.0;
    double testConcreteCost = 800.0;

    Circle pool(RADIUS_OF_POOL);
    Circle poolWithRoad(RADIUS_OF_POOL + WIDTH_OF_ROAD);
    
    double roadArea = poolWithRoad.getArea() - pool.getArea();
    double fenceLength = poolWithRoad.getFerence();
    
    double expected = fenceLength * COST_OF_METER_FENCE + roadArea * COST_OF_CONCRETE_COATING;
    double actual = Pool();
    
    EXPECT_DOUBLE_EQ(actual, expected);
}

TEST(CircleTest, ConstantsType) {
    EXPECT_EQ(typeid(RADIUS_OF_EARTH), typeid(int));
    EXPECT_EQ(typeid(RADIUS_OF_POOL), typeid(int));
    EXPECT_EQ(typeid(COST_OF_METER_FENCE), typeid(int));
}
