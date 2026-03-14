// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double earthRope() {
  Circle earth(6378100.0);
  double prev_radius = earth.getRadius();
  earth.setFerence(earth.getFerence() + 1.0);
  return earth.getRadius() - prev_radius;
}

double poolMaterialsPath() {
  Circle pool(3.0);
  Circle path(4.0);
  int cost = 1000;
  double path_area = path.getArea() - pool.getArea();
  return path_area * cost;
}

double poolMaterialsFence() {
  Circle path(4.0);
  int cost = 2000;
  return path.getFerence() * cost;
}

double poolMaterials() {
  return poolMaterialsPath() + poolMaterialsFence();
}
