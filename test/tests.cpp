// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

// --- ТЕСТЫ КЛАССА CIRCLE ---

// 1. Проверка инициализации через конструктор
TEST(CircleClass, ConstructorInit) {
    Circle c(10.0);
    EXPECT_NEAR(10.0, c.getRadius(), 0.0001);
}

// 2. Проверка пересчета длины окружности при установке радиуса
TEST(CircleClass, SetRadiusUpdatesFerence) {
    Circle c(0);
    c.setRadius(5.0);
    EXPECT_NEAR(31.4159, c.getFerence(), 0.0001);
}

// 3. Проверка пересчета площади при установке радиуса
TEST(CircleClass, SetRadiusUpdatesArea) {
    Circle c(0);
    c.setRadius(5.0);
    EXPECT_NEAR(78.5398, c.getArea(), 0.0001);
}

// 4. Проверка пересчета радиуса при установке длины окружности
TEST(CircleClass, SetFerenceUpdatesRadius) {
    Circle c(0);
    c.setFerence(62.8318);
    EXPECT_NEAR(10.0, c.getRadius(), 0.0001);
}

// 5. Проверка пересчета площади при установке длины окружности
TEST(CircleClass, SetFerenceUpdatesArea) {
    Circle c(0);
    c.setFerence(62.8318);
    EXPECT_NEAR(314.1592, c.getArea(), 0.0001);
}

// 6. Проверка пересчета радиуса при установке площади
TEST(CircleClass, SetAreaUpdatesRadius) {
    Circle c(0);
    c.setArea(314.1592);
    EXPECT_NEAR(10.0, c.getRadius(), 0.0001);
}

// 7. Проверка пересчета длины окружности при установке площади
TEST(CircleClass, SetAreaUpdatesFerence) {
    Circle c(0);
    c.setArea(78.5398);
    EXPECT_NEAR(31.4159, c.getFerence(), 0.0001);
}

// 8. Проверка работы с малым радиусом
TEST(CircleClass, SmallRadius) {
    Circle c(0.001);
    EXPECT_NEAR(0.00000314, c.getArea(), 0.00000001);
}

// 9. Проверка экстремально больших значений
TEST(CircleClass, LargeValue) {
    Circle c(1e6);
    EXPECT_GT(c.getArea(), 1e12);
}

// 10. Проверка последовательного изменения
TEST(CircleClass, SequenceUpdate) {
    Circle c(10);
    c.setFerence(20);
    c.setRadius(5);
    EXPECT_NEAR(5.0, c.getRadius(), 0.0001);
    EXPECT_NEAR(78.5398, c.getArea(), 0.0001);
}

// --- ТЕСТЫ ЗАДАЧИ "ЗЕМЛЯ И ВЕРЕВКА" ---

// 11. Классическая задача (добавление 1 метра)
TEST(EarthTask, StandardGap) {
    double gap = calculateEarthGap(6378.1, 1.0);
    // 1 / (2 * PI) ≈ 0.1591549
    EXPECT_NEAR(0.1591, gap, 0.001);
}

// 12. Добавление большой длины (например, 1 км)
TEST(EarthTask, LargeGap) {
    double gap = calculateEarthGap(6378.1, 1000.0);
    EXPECT_NEAR(159.1549, gap, 0.001);
}

// 13. Проверка на другом небесном теле (Луна ~1737 км)
TEST(EarthTask, MoonGap) {
    double gap = calculateEarthGap(1737.0, 1.0);
    EXPECT_NEAR(0.1591, gap, 0.001); // Зазор всегда одинаков при одинаковой добавке
}

// --- ТЕСТЫ ЗАДАЧИ "БАССЕЙН" ---

// 14. Стоимость бетона для стандартных условий (r=3, w=1)
TEST(PoolTask, ConcreteCostStandard) {
    Pool res = calculateCostOfPool(3.0, 1.0);
    // S = PI*(4^2 - 3^2) = 7*PI ≈ 21.9911. Цена = 21991.1
    EXPECT_NEAR(21991.14, res.costOfRoad, 0.1);
}

// 15. Стоимость ограды для стандартных условий (r=3, w=1)
TEST(PoolTask, FenceCostStandard) {
    Pool res = calculateCostOfPool(3.0, 1.0);
    // L = 2*PI*4 ≈ 25.1327. Цена = 50265.48
    EXPECT_NEAR(50265.48, res.costOfFence, 0.1);
}

// 16. Бассейн с нулевой шириной дорожки
TEST(PoolTask, ZeroPathWidth) {
    Pool res = calculateCostOfPool(5.0, 0.0);
    EXPECT_NEAR(0.0, res.costOfRoad, 0.0001);
}

// 17. Очень узкая дорожка
TEST(PoolTask, NarrowPath) {
    Pool res = calculateCostOfPool(3.0, 0.1);
    // S = PI*(3.1^2 - 3^2) = 0.61*PI ≈ 1.916. Цена ≈ 1916
    EXPECT_NEAR(1916.37, res.costOfRoad, 0.1);
}

// 18. Большой бассейн
TEST(PoolTask, LargePool) {
    Pool res = calculateCostOfPool(10.0, 2.0);
    // S = PI*(12^2 - 10^2) = 44*PI ≈ 138.23. Цена ≈ 138230
    EXPECT_NEAR(138230.0, res.costOfRoad, 1.0);
}

// 19. Проверка соотношения цен
TEST(PoolTask, PriceRatio) {
    Pool res = calculateCostOfPool(3.0, 1.0);
    // Ограда обычно дороже дорожки в этой задаче
    EXPECT_GT(res.costOfFence, res.costOfRoad);
}

// 20. Проверка влияния радиуса на ограду
TEST(PoolTask, FenceLinearGrowth) {
    Pool res1 = calculateCostOfPool(1.0, 1.0); // R=2
    Pool res2 = calculateCostOfPool(3.0, 1.0); // R=4
    // Ограда для R=4 должна быть в 2 раза дороже, чем для R=2
    EXPECT_NEAR(res1.costOfFence * 2, res2.costOfFence, 0.0001);
}

