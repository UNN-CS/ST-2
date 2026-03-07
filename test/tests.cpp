// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double EPSILON = 1e-10;

TEST(CircleTest, DefaultConstructor) {
    Circle c;
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, ParameterizedConstructor) {
    double radius = 5.0;
    Circle c(radius);
    EXPECT_DOUBLE_EQ(radius, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * radius, c.getFerence());
    EXPECT_DOUBLE_EQ(PI * radius * radius, c.getArea());
}

TEST(CircleTest, ConstructorWithZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, ConstructorWithNegativeRadius) {
    Circle c(-5.0);
    EXPECT_DOUBLE_EQ(-5.0, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * (-5.0), c.getFerence());
    EXPECT_DOUBLE_EQ(PI * 25.0, c.getArea());
}

TEST(CircleTest, SetRadius) {
    Circle c;
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(3.0, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * 3.0, c.getFerence());
    EXPECT_DOUBLE_EQ(PI * 9.0, c.getArea());
}

TEST(CircleTest, SetFerence) {
    Circle c;
    double ference = 10.0;
    c.setFerence(ference);
    double expectedRadius = ference / (2 * PI);
    EXPECT_DOUBLE_EQ(expectedRadius, c.getRadius());
    EXPECT_DOUBLE_EQ(ference, c.getFerence());
    EXPECT_DOUBLE_EQ(PI * expectedRadius * expectedRadius, c.getArea());
}

TEST(CircleTest, SetArea) {
    Circle c;
    double area = 50.0;
    c.setArea(area);
    double expectedRadius = std::sqrt(area / PI);
    EXPECT_DOUBLE_EQ(expectedRadius, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * expectedRadius, c.getFerence());
    EXPECT_DOUBLE_EQ(area, c.getArea());
}

TEST(CircleTest, SetRadiusUpdatesFerenceAndArea) {
    Circle c(2.0);
    double oldFerence = c.getFerence();
    double oldArea = c.getArea();
    c.setRadius(4.0);
    EXPECT_NE(oldFerence, c.getFerence());
    EXPECT_NE(oldArea, c.getArea());
    EXPECT_DOUBLE_EQ(2 * PI * 4.0, c.getFerence());
    EXPECT_DOUBLE_EQ(PI * 16.0, c.getArea());
}

TEST(CircleTest, SetFerenceUpdatesRadiusAndArea) {
    Circle c(2.0);
    double oldRadius = c.getRadius();
    double oldArea = c.getArea();
    c.setFerence(20.0);
    EXPECT_NE(oldRadius, c.getRadius());
    EXPECT_NE(oldArea, c.getArea());
    EXPECT_DOUBLE_EQ(20.0 / (2 * PI), c.getRadius());
}

TEST(CircleTest, SetAreaUpdatesRadiusAndFerence) {
    Circle c(2.0);
    double oldRadius = c.getRadius();
    double oldFerence = c.getFerence();
    c.setArea(100.0);
    EXPECT_NE(oldRadius, c.getRadius());
    EXPECT_NE(oldFerence, c.getFerence());
    EXPECT_DOUBLE_EQ(std::sqrt(100.0 / PI), c.getRadius());
}

TEST(CircleTest, FerenceConsistentWithRadius) {
    double r = 7.5;
    Circle c(r);
    EXPECT_DOUBLE_EQ(2 * PI * r, c.getFerence());
}

TEST(CircleTest, AreaConsistentWithRadius) {
    double r = 4.2;
    Circle c(r);
    EXPECT_DOUBLE_EQ(PI * r * r, c.getArea());
}

TEST(CircleTest, AreaConsistentWithFerence) {
    double f = 15.0;
    Circle c;
    c.setFerence(f);
    double r = f / (2 * PI);
    EXPECT_DOUBLE_EQ(PI * r * r, c.getArea());
}

TEST(CircleTest, FerenceConsistentWithArea) {
    double a = 30.0;
    Circle c;
    c.setArea(a);
    double r = std::sqrt(a / PI);
    EXPECT_DOUBLE_EQ(2 * PI * r, c.getFerence());
}

TEST(CircleTest, MultipleUpdatesConsistency) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(2.0, c.getRadius());
    EXPECT_DOUBLE_EQ(4 * PI, c.getArea());
    c.setFerence(10.0);
    double r = 10.0 / (2 * PI);
    EXPECT_DOUBLE_EQ(r, c.getRadius());
    EXPECT_DOUBLE_EQ(PI * r * r, c.getArea());
    c.setArea(20.0);
    r = std::sqrt(20.0 / PI);
    EXPECT_DOUBLE_EQ(r, c.getRadius());
    EXPECT_DOUBLE_EQ(2 * PI * r, c.getFerence());
}

TEST(EarthRopeTest, SubFunction) {
    double a = 10.0;
    double b = 4.0;
    EXPECT_DOUBLE_EQ(6.0, sub(a, b));
    EXPECT_DOUBLE_EQ(-6.0, sub(b, a));
}


TEST(PoolTest, PathAreaCalculation) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double expectedPathArea = PI * (16.0 - 9.0);
    EXPECT_DOUBLE_EQ(expectedPathArea, pathArea);
    EXPECT_NEAR(21.9911, pathArea, 1e-4);
}

TEST(PoolTest, FenceLengthCalculation) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    Circle poolWithPath(poolRadius + pathWidth);
    double fenceLength = poolWithPath.getFerence();
    double expectedFenceLength = 2 * PI * 4.0;
    EXPECT_DOUBLE_EQ(expectedFenceLength, fenceLength);
    EXPECT_NEAR(25.1327, fenceLength, 1e-4);
}

TEST(PoolTest, ConcreteCostCalculation) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double concretePrice = 1000.0;
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double concreteCost = pathArea * concretePrice;
    EXPECT_NEAR(21991.1, concreteCost, 1e-1);
}

TEST(PoolTest, FenceCostCalculation) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double fencePrice = 2000.0;
    Circle poolWithPath(poolRadius + pathWidth);
    double fenceLength = poolWithPath.getFerence();
    double fenceCost = fenceLength * fencePrice;
    EXPECT_NEAR(50265.5, fenceCost, 1e-1);
}

TEST(PoolTest, TotalCostCalculation) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double concretePrice = 1000.0;
    double fencePrice = 2000.0;
    double totalCost = calculatePoolCost(poolRadius, pathWidth, concretePrice, fencePrice);
    EXPECT_NEAR(72256.6, totalCost, 1e-1);
}

TEST(PoolTest, ZeroWidthPath) {
    double poolRadius = 3.0;
    double pathWidth = 0.0;
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    EXPECT_DOUBLE_EQ(0.0, pathArea);
    double fenceLength = poolWithPath.getFerence();
    EXPECT_DOUBLE_EQ(2 * PI * 3.0, fenceLength);
}

TEST(PoolTest, NegativeWidthPath) {
    double poolRadius = 3.0;
    double pathWidth = -1.0;
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double expectedArea = PI * (4.0 - 9.0);
    EXPECT_DOUBLE_EQ(expectedArea, pathArea);
    EXPECT_LT(pathArea, 0.0);
}

TEST(PoolTest, DifferentPoolRadii) {
    double poolRadius = 5.0;
    double pathWidth = 2.0;
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double expectedPathArea = PI * ((poolRadius + pathWidth) * 
    (poolRadius + pathWidth) - poolRadius * poolRadius);
    EXPECT_DOUBLE_EQ(expectedPathArea, pathArea);
}

TEST(PoolTest, LargePoolRadius) {
    double poolRadius = 100.0;
    double pathWidth = 1.0;
    double totalCost = calculatePoolCost(poolRadius, pathWidth, 1000.0, 2000.0);
    EXPECT_GT(totalCost, 1.9e6);
    EXPECT_LT(totalCost, 1.91e6);
}

TEST(CircleTest, VerySmallRadius) {
    double r = 1e-10;
    Circle c(r);
    EXPECT_DOUBLE_EQ(2 * PI * r, c.getFerence());
    EXPECT_DOUBLE_EQ(PI * r * r, c.getArea());
}

TEST(CircleTest, VeryLargeRadius) {
    double r = 1e10;
    Circle c(r);
    EXPECT_DOUBLE_EQ(2 * PI * r, c.getFerence());
    EXPECT_DOUBLE_EQ(PI * r * r, c.getArea());
}

TEST(CircleTest, SetZeroFerence) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetZeroArea) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
}

TEST(SubFunctionTest, PositiveNumbers) {
    EXPECT_DOUBLE_EQ(5.0, sub(10.0, 5.0));
    EXPECT_DOUBLE_EQ(0.0, sub(7.0, 7.0));
}

TEST(SubFunctionTest, NegativeNumbers) {
    EXPECT_DOUBLE_EQ(-3.0, sub(-5.0, -2.0));
    EXPECT_DOUBLE_EQ(7.0, sub(5.0, -2.0));
    EXPECT_DOUBLE_EQ(-7.0, sub(-5.0, 2.0));
}

TEST(SubFunctionTest, FloatingPoint) {
    EXPECT_NEAR(0.1, sub(0.3, 0.2), 1e-10);
    EXPECT_NEAR(0.333333, sub(1.0, 0.666667), 1e-6);
}
