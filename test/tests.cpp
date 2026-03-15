// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;
const double EPSILON = 1e-10;

// Тесты для класса Circle
TEST(CircleTest, ConstructorWithRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 5.0, EPSILON);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPSILON);
}

TEST(CircleTest, ConstructorWithZeroRadius) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0.0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0.0, EPSILON);
}

TEST(CircleTest, ConstructorNegativeRadiusThrows) {
    EXPECT_THROW(Circle c(-5.0), std::invalid_argument);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 3.0, EPSILON);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPSILON);
}

TEST(CircleTest, SetRadiusZero) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0.0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0.0, EPSILON);
}

TEST(CircleTest, SetRadiusNegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    double f = 10.0;
    c.setFerence(f);
    EXPECT_NEAR(c.getFerence(), f, EPSILON);
    EXPECT_NEAR(c.getRadius(), f / (2 * PI), EPSILON);
    EXPECT_NEAR(c.getArea(), PI * pow(f / (2 * PI), 2), EPSILON);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getFerence(), 0.0, EPSILON);
    EXPECT_NEAR(c.getRadius(), 0.0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0.0, EPSILON);
}

TEST(CircleTest, SetFerenceNegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    double a = 50.0;
    c.setArea(a);
    EXPECT_NEAR(c.getArea(), a, EPSILON);
    EXPECT_NEAR(c.getRadius(), sqrt(a / PI), EPSILON);
    EXPECT_NEAR(c.getFerence(), 2 * PI * sqrt(a / PI), EPSILON);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getArea(), 0.0, EPSILON);
    EXPECT_NEAR(c.getRadius(), 0.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0.0, EPSILON);
}

TEST(CircleTest, SetAreaNegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-50.0), std::invalid_argument);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e6, 1e-6);
    EXPECT_NEAR(c.getArea(), PI * 1e12, 1e0);
}

TEST(CircleTest, SmallRadius) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e-6, 1e-12);
    EXPECT_NEAR(c.getArea(), PI * 1e-12, 1e-20);
}

TEST(CircleTest, ConsistencyAfterMultipleSets) {
    Circle c(2.0);
    double originalRadius = c.getRadius();
    
    c.setFerence(c.getFerence() * 2);
    EXPECT_NEAR(c.getRadius(), originalRadius * 2, EPSILON);
    
    c.setArea(c.getArea() * 4);
    EXPECT_NEAR(c.getRadius(), originalRadius * 4, EPSILON);
}

// Тесты для задачи "Земля и верёвка"
TEST(EarthRopeTest, GapCalculation) {
    double gap = findGap();
    
    EXPECT_GT(gap, 0.0);
    
    double expectedGap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expectedGap, 1e-6);
}

TEST(EarthRopeTest, GapInCentimeters) {
    double gap = findGap();
    double gapCm = gap * 100;
    
    EXPECT_NEAR(gapCm, 100.0 / (2 * PI), 1e-4);
    EXPECT_GT(gapCm, 15.0);
    EXPECT_LT(gapCm, 17.0);
}

TEST(EarthRopeTest, GapIndependenceFromRadius) {
    Circle earth1(6378100.0);
    Circle earth2(1000000.0);
    
    earth1.setFerence(earth1.getFerence() + 1.0);
    earth2.setFerence(earth2.getFerence() + 1.0);
    
    double gap1 = earth1.getRadius() - 6378100.0;
    double gap2 = earth2.getRadius() - 1000000.0;
    
    double EPSILON_GAP = 1e-9;
    
    EXPECT_NEAR(gap1, gap2, EPSILON_GAP);
    
    double expectedGap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap1, expectedGap, 1e-6);
    EXPECT_NEAR(gap2, expectedGap, 1e-6);
}

// Тесты для задачи "Бассейн"
TEST(PoolTest, PathArea) {
    double cost = findCost();
    
    Circle pool(3.0);
    Circle poolWithPath(4.0);
    
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double expectedConcreteCost = pathArea * 1000.0;
    double expectedFenceCost = poolWithPath.getFerence() * 2000.0;
    double expectedTotal = expectedConcreteCost + expectedFenceCost;
    
    EXPECT_NEAR(cost, expectedTotal, 1e-6);
}

TEST(PoolTest, PathAreaValue) {
    double pathArea = Circle(4.0).getArea() - Circle(3.0).getArea();
    double expectedArea = PI * (16.0 - 9.0);
    EXPECT_NEAR(pathArea, expectedArea, 1e-6);
}

TEST(PoolTest, FenceLength) {
    double fenceLength = Circle(4.0).getFerence();
    double expectedLength = 2 * PI * 4.0; 
    EXPECT_NEAR(fenceLength, expectedLength, 1e-6);
}

TEST(PoolTest, ConcreteCost) {
    double cost = findCost();
    double pathArea = Circle(4.0).getArea() - Circle(3.0).getArea();
    double concreteCost = pathArea * 1000.0;
    double fenceCost = Circle(4.0).getFerence() * 2000.0;
    
    EXPECT_NEAR(cost, concreteCost + fenceCost, 1e-6);
    EXPECT_GT(concreteCost, 20000.0);
    EXPECT_LT(concreteCost, 25000.0);
}

TEST(PoolTest, FenceCost) {
    double fenceCost = Circle(4.0).getFerence() * 2000.0;
    double expectedFenceCost = 2 * PI * 4.0 * 2000.0;
    EXPECT_NEAR(fenceCost, expectedFenceCost, 1e-3);
    EXPECT_GT(fenceCost, 50000.0);
    EXPECT_LT(fenceCost, 51000.0);
}

TEST(PoolTest, TotalCost) {
    double cost = findCost();
    double expectedTotal = (PI * 7.0 * 1000.0) + (2 * PI * 4.0 * 2000.0);
    EXPECT_NEAR(cost, expectedTotal, 1e-3);
    EXPECT_GT(cost, 70000.0);
    EXPECT_LT(cost, 76000.0);
}

// Интеграционные тесты
TEST(IntegrationTest, CircleConsistency) {
    Circle c(2.5);
    
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();
    
    EXPECT_NEAR(f, 2 * PI * r, EPSILON);
    EXPECT_NEAR(a, PI * r * r, EPSILON);
    EXPECT_NEAR(r, sqrt(a / PI), EPSILON);
}

TEST(IntegrationTest, UpdateChain) {
    Circle c(1.0);
    
    for (int i = 1; i <= 5; i++) {
        c.setRadius(i);
        EXPECT_NEAR(c.getRadius(), i, EPSILON);
        EXPECT_NEAR(c.getFerence(), 2 * PI * i, EPSILON);
        EXPECT_NEAR(c.getArea(), PI * i * i, EPSILON);
    }
}

TEST(IntegrationTest, ZeroValues) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 0.0, EPSILON);
    EXPECT_NEAR(c.getArea(), 0.0, EPSILON);
    
    c.setFerence(10.0);
    EXPECT_GT(c.getRadius(), 0.0);
    EXPECT_GT(c.getArea(), 0.0);
}

// Дополнительные тесты для покрытия
TEST(CircleTest, VeryLargeValues) {
    Circle c(1e12);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e12, 1e0);
    EXPECT_NEAR(c.getArea(), PI * 1e24, 1e12);
}

TEST(CircleTest, VerySmallValues) {
    Circle c(1e-12);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 1e-12, 1e-20);
    EXPECT_NEAR(c.getArea(), PI * 1e-24, 1e-30);
}

TEST(CircleTest, PrecisionTest) {
    Circle c(2.0);
    c.setFerence(2 * PI * 2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, EPSILON);
    EXPECT_NEAR(c.getArea(), PI * 4.0, EPSILON);
    
    c.setArea(PI * 4.0);
    EXPECT_NEAR(c.getRadius(), 2.0, EPSILON);
    EXPECT_NEAR(c.getFerence(), 2 * PI * 2.0, EPSILON);
}