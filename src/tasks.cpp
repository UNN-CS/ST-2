// Copyright 2026 Salykina Alena

#include "tasks.h"

#include <cmath>
#include <stdexcept>

double EarthAndRope() {
    const double radius_earth = 6378.1 * 1000.0;  // метры
    const double added_length = 1.0;

    Circle earth(radius_earth);

    // увеличиваем длину окружности на 1 метр через метод класса
    earth.setFerence(earth.getFerence() + added_length);

    // зазор = новый радиус - старый радиус
    return earth.getRadius() - radius_earth;
}

double Pool() {
    const double pool_radius = 3.0;
    const double path_width = 1.0;
    const double concrete_price = 1000.0;
    const double fence_price = 2000.0;

    Circle pool(pool_radius);
    Circle outer(pool_radius + path_width);

    double fence_cost = fence_price * outer.getFerence();

    double concrete_cost =
        concrete_price * (outer.getArea() - pool.getArea());

    return fence_cost + concrete_cost;
}
