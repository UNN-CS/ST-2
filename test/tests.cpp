// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "task.h"
// Тесты для класса Circle
TEST(CircleTest, Test1Radius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}
TEST(CircleTest, Test2Radius) {
    Circle c(4.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
}
TEST(CircleTest, Test3Radius) {
    Circle c(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
}
TEST(CircleTest, Test4Radius) {
    Circle c(2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
}
TEST(CircleTest, Test5Radius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
}
TEST(CircleTest, Test6Ference) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 31.4159); // 2 * PI * 5
}
TEST(CircleTest, Test7Area) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 78.5398); // PI * 5^2
}
// Тесты для установки радиуса
TEST(CircleTest, Set8RadiusUpdatesFerenceAndArea) {
    Circle c(5.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 62.8319); // 2 * PI * 10
    EXPECT_DOUBLE_EQ(c.getArea(), 314.159);   // PI * 10^2
}
TEST(CircleTest, Set9RadiusUpdatesFerenceAndArea_2) {
    Circle c(3.0);
    c.setRadius(7.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 43.9823); // 2 * PI * 7
    EXPECT_DOUBLE_EQ(c.getArea(), 153.938);    // PI * 7^2
}
TEST(CircleTest, Set10RadiusUpdatesFerenceAndArea_3) {
    Circle c(1.0);
    c.setRadius(5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 31.4159); // 2 * PI * 5
    EXPECT_DOUBLE_EQ(c.getArea(), 78.5398);    // PI * 5^2
}
TEST(CircleTest, Set11RadiusUpdatesFerenceAndArea_4) {
    Circle c(10.0);
    c.setRadius(15.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 94.2478); // 2 * PI * 15
    EXPECT_DOUBLE_EQ(c.getArea(), 706.8577);   // PI * 15^2
}
TEST(CircleTest, Set12RadiusUpdatesFerenceAndArea_5) {
    Circle c(2.5);
    c.setRadius(12.5);
    EXPECT_DOUBLE_EQ(c.getFerence(), 78.5398); // 2 * PI * 12.5
    EXPECT_DOUBLE_EQ(c.getArea(), 490.8738);   // PI * 12.5^2
}
TEST(CircleTest, Set13RadiusUpdatesFerenceAndArea_6) {
    Circle c(0.5);
    c.setRadius(2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 12.5664); // 2 * PI * 2
    EXPECT_DOUBLE_EQ(c.getArea(), 12.5664);    // PI * 2^2
}
TEST(CircleTest, Set14RadiusUpdatesFerenceAndArea_7) {
    Circle c(4.0);
    c.setRadius(8.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 50.2655); // 2 * PI * 8
    EXPECT_DOUBLE_EQ(c.getArea(), 201.0619);   // PI * 8^2
}
TEST(CircleTest, Set15RadiusUpdatesFerenceAndArea_8) {
    Circle c(6.0);
    c.setRadius(9.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 56.5487); // 2 * PI * 9
    EXPECT_DOUBLE_EQ(c.getArea(), 254.4690);   // PI * 9^2
}
// Тесты для задач
TEST(TaskTest, CalculateGap_Example1) {
    EXPECT_DOUBLE_EQ(calculateGap(6378.1, 1.0), 0.159154943);
}
TEST(TaskTest, CalculateGap_Example2) {
    EXPECT_DOUBLE_EQ(calculateGap(6378.1, 10.0), 1.59154943);
}
TEST(TaskTest, CalculateGap_Example3) {
    EXPECT_DOUBLE_EQ(calculateGap(6378.1, 45.0), 7.06858347);
}
TEST(TaskTest, CalculateGap_Example4) {
    EXPECT_DOUBLE_EQ(calculateGap(6378.1, 90.0), 12.56637061);
}
TEST(TaskTest, CalculateGap_Example5) {
    EXPECT_DOUBLE_EQ(calculateGap(6378.1, 180.0), 25.13274123);
}
TEST(TaskTest, CalculateGap_Example6) {
    EXPECT_DOUBLE_EQ(calculateGap(6378.1, 360.0), 50.26548246);
}
TEST(TaskTest, CalculateGap_Example7) {
    EXPECT_DOUBLE_EQ(calculateGap(10000.0, 1.0), 0.1570796327);
}
TEST(TaskTest, CalculatePoolCost) {
    EXPECT_DOUBLE_EQ(calculatePoolCost(3.0, 1.0), 12000);
}
