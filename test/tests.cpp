// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"


TEST(CircleTest, Constructor_Sets_Radius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(5.0, c.getRadius());
}

TEST(CircleTest, Constructor_Calculates_Ference) {
    Circle c(1.0);
    EXPECT_NEAR(6.283185, c.getFerence(), 0.0001);
}

TEST(CircleTest, Constructor_Calculates_Area) {
    Circle c(1.0);
    EXPECT_NEAR(3.141592, c.getArea(), 0.0001);
}

TEST(CircleTest, SetRadius_Updates_Value) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(10.0, c.getRadius());
}

TEST(CircleTest, SetRadius_Updates_Ference) {
    Circle c(1.0);
    c.setRadius(2.0);
    EXPECT_NEAR(12.56637, c.getFerence(), 0.0001);
}

TEST(CircleTest, SetRadius_Updates_Area) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(28.27433, c.getArea(), 0.0001);
}

TEST(CircleTest, SetFerence_Updates_Value) {
    Circle c(1.0);
    c.setFerence(31.41592);
    EXPECT_NEAR(31.41592, c.getFerence(), 0.0001);
}

TEST(CircleTest, SetFerence_Updates_Radius) {
    Circle c(1.0);
    c.setFerence(62.83185);
    EXPECT_NEAR(10.0, c.getRadius(), 0.0001);
}

TEST(CircleTest, SetFerence_Updates_Area) {
    Circle c(1.0);
    c.setFerence(6.283185);
    EXPECT_NEAR(3.141592, c.getArea(), 0.0001);
}

TEST(CircleTest, SetArea_Updates_Value) {
    Circle c(1.0);
    c.setArea(100.0);
    EXPECT_NEAR(100.0, c.getArea(), 0.0001);
}

TEST(CircleTest, SetArea_Updates_Radius) {
    Circle c(1.0);
    c.setArea(314.159265);
    EXPECT_NEAR(10.0, c.getRadius(), 0.0001);
}

TEST(CircleTest, SetArea_Updates_Ference) {
    Circle c(1.0);
    c.setArea(12.56637);
    EXPECT_NEAR(12.56637, c.getFerence(), 0.1);
}

TEST(CircleTest, Zero_Radius_Handling) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, Set_Zero_Ference) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
}

TEST(CircleTest, Set_Zero_Area) {
    Circle c(10.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
}

TEST(CircleTest, Large_Radius_Consistency) {
    Circle c(1000000.0);
    double r = c.getRadius();
    c.setRadius(r);
    EXPECT_NEAR(r, c.getRadius(), 0.000001);
}

TEST(CircleTest, Small_Radius_Consistency) {
    Circle c(0.0001);
    EXPECT_GT(c.getArea(), 0);
}

TEST(CircleTest, Math_Consistency_Radius_Area) {
    Circle c(4.0);
    double area = 3.141592653589793 * 16.0;
    EXPECT_NEAR(area, c.getArea(), 0.000001);
}

TEST(CircleTest, Math_Consistency_Ference_Radius) {
    Circle c(0);
    c.setFerence(100.0);
    EXPECT_NEAR(100.0 / (2 * 3.141592653589793), c.getRadius(), 0.000001);
}

TEST(CircleTest, Repeated_Set_Stability) {
    Circle c(10.0);
    double f = c.getFerence();
    c.setFerence(f);
    EXPECT_NEAR(10.0, c.getRadius(), 0.000001);
}

TEST(TasksTest, EarthGap_Result_Check) {
    double gap = calculateEarthGap();
    EXPECT_NEAR(0.1591549, gap, 0.000001);
}

TEST(TasksTest, PoolConcrete_Cost_Check) {
    double cost = calculatePoolConcreteCost();
    EXPECT_NEAR(21991.148, cost, 0.001);
}

TEST(TasksTest, PoolFence_Cost_Check) {
    double cost = calculatePoolFenceCost();
    EXPECT_NEAR(50265.482, cost, 0.001);
}
