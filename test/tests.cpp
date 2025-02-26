// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

// 1. Проверка конструктора
TEST(CircleTest, Constructor) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 5.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 25.0, 1e-9);
}

// 2. Установка радиуса
TEST(CircleTest, SetRadius) {
    Circle c(0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 10.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 100.0, 1e-9);
}

// 3. Установка длины окружности
TEST(CircleTest, SetFerence) {
    Circle c(0);
    c.setFerence(20.0);
    EXPECT_NEAR(c.getRadius(), 20.0 / (2 * M_PI), 1e-9);
    EXPECT_NEAR(c.getFerence(), 20.0, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * pow(20.0 / (2 * M_PI), 2), 1e-9);
}

// 4. Установка площади
TEST(CircleTest, SetArea) {
    Circle c(0);
    c.setArea(50.0);
    EXPECT_NEAR(c.getRadius(), sqrt(50.0 / M_PI), 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * sqrt(50.0 / M_PI), 1e-9);
    EXPECT_NEAR(c.getArea(), 50.0, 1e-9);
}

// 5. Проверка на нулевой радиус
TEST(CircleTest, ZeroRadius) {
    Circle c(0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

// 6. Проверка на отрицательный радиус (должен выбрасывать исключение или игнорировать)
TEST(CircleTest, NegativeRadius) {
    Circle c(0);
    c.setRadius(-5.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9); // Ожидаем, что радиус останется 0
}

// 7. Проверка на очень большой радиус
TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getRadius(), 1e6, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 1e12, 1e-9);
}

// 8. Проверка на очень маленький радиус
TEST(CircleTest, SmallRadius) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getRadius(), 1e-6, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e-6, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 1e-12, 1e-9);
}

// 9. Проверка на установку нулевой длины окружности
TEST(CircleTest, ZeroFerence) {
    Circle c(0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

// 10. Проверка на установку нулевой площади
TEST(CircleTest, ZeroArea) {
    Circle c(0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

// 11. Проверка на установку отрицательной длины окружности
TEST(CircleTest, NegativeFerence) {
    Circle c(0);
    c.setFerence(-10.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9); // Ожидаем, что радиус останется 0
}

// 12. Проверка на установку отрицательной площади
TEST(CircleTest, NegativeArea) {
    Circle c(0);
    c.setArea(-50.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9); // Ожидаем, что радиус останется 0
}

// 13. Проверка на точность вычислений
TEST(CircleTest, Precision) {
    Circle c(1.0);
    c.setRadius(1.000000001);
    EXPECT_NEAR(c.getRadius(), 1.000000001, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1.000000001, 1e-9);
    EXPECT_NEAR(c.getArea(), M_PI * 1.0000000020000001, 1e-9);
}

// 14. Проверка на обновление радиуса после изменения площади
TEST(CircleTest, UpdateRadiusFromArea) {
    Circle c(0);
    c.setArea(100.0);
    EXPECT_NEAR(c.getRadius(), sqrt(100.0 / M_PI), 1e-9);
}

// 15. Проверка на обновление длины окружности после изменения радиуса
TEST(CircleTest, UpdateFerenceFromRadius) {
    Circle c(0);
    c.setRadius(7.0);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 7.0, 1e-9);
}

// 16. Проверка задачи "Земля и верёвка"
TEST(EarthRopeTest, GapCalculation) {
    double gap = calculateRopeGap();
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-5); // Ожидаемый зазор
}

// 17. Проверка на очень маленький зазор
TEST(EarthRopeTest, SmallGap) {
    Circle earth(6378100.0); // Радиус Земли в метрах
    earth.setFerence(earth.getFerence() + 0.001); // Добавляем 1 мм
    double gap = earth.getRadius() - 6378100.0;
    EXPECT_NEAR(gap, 0.001 / (2 * M_PI), 1e-9);
}

// 18. Проверка стоимости бетонной дорожки
TEST(PoolCostTest, ConcreteCost) {
    double cost = calculatePoolCost();
    double expectedConcreteArea = M_PI * (16.0 - 9.0); // Площадь дорожки
    double expectedFenceLength = 2 * M_PI * 4.0; // Длина ограды
    double expectedCost = expectedConcreteArea * 1000 + expectedFenceLength * 2000;
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
    EXPECT_NEAR(cost, (M_PI * (1003.0 * 1003.0 - 9.0)) * 1000 + (2 * M_PI * 1003.0) * 2000, 1e-5);
}
