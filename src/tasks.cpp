// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

// Радиус земли в метрах (6378.1 км)
const double EARTH_RADIUS_M = 6378100.0;
// Длина добавленного куска верёвки в метрах
const double ROPE_ADDITION_M = 1.0;

// Радиус бассейна в метрах
const double POOL_RADIUS_M = 3.0;
// Ширина дорожки в метрах
const double PATH_WIDTH_M = 1.0;
// Стоимость 1 м² бетона в рублях
const double CONCRETE_PRICE = 1000.0;
// Стоимость 1 погонного метра ограды в рублях
const double FENCE_PRICE = 2000.0;

double ropeTask() {
  Circle earth(EARTH_RADIUS_M);
  double originalFerence = earth.getFerence();
  double newFerence = originalFerence + ROPE_ADDITION_M;

  Circle newCircle;
  newCircle.setFerence(newFerence);

  return newCircle.getRadius() - EARTH_RADIUS_M;
}

double poolConcreteCost() {
  Circle pool(POOL_RADIUS_M);
  double poolArea = pool.getArea();

  double outerRadius = POOL_RADIUS_M + PATH_WIDTH_M;
  Circle outer(outerRadius);
  double totalArea = outer.getArea();

  double pathArea = totalArea - poolArea;
  return pathArea * CONCRETE_PRICE;
}

double poolFenceCost() {
  double outerRadius = POOL_RADIUS_M + PATH_WIDTH_M;
  Circle outer(outerRadius);
  double fenceLength = outer.getFerence();
  return fenceLength * FENCE_PRICE;
}
