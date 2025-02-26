#include "tasks.hpp"

double GetGap() {
  constexpr auto radius = 6378.1;
  Circle earth(radius);
  earth.SetFerence(earth.GetFerence() + 1);
  return earth.GetRadius() - radius;
}

double GetSwimingPoolBuildingCost() {
  Circle swimingPool(3.0);
  Circle fence(4.0);
  double price = fence.GetFerence() * 2000;
  price += (fence.GetArea() - swimingPool.GetArea()) * 1000.0;
  return price;
}