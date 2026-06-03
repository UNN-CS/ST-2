// Copyright 2024 Nazyrov A.A.

#include <iostream>
#include <iomanip>
#include "circle.h"
#include "tasks.h"

int main() {
  std::cout << std::fixed << std::setprecision(6);

  geometry::Circle c(5.0);
  std::cout << "Circle with radius 5:\n";
  std::cout << "  Circumference: " << c.getCircumference() << "\n";
  std::cout << "  Area: " << c.getArea() << "\n\n";

  double gap = tasks::calculateRopeGap();
  std::cout << "Earth and rope problem:\n";
  std::cout << "  Gap after adding 1 meter: " << gap;
  std::cout << " meters (~15.9 cm)\n\n";

  double concreteCost = 0.0, fenceCost = 0.0;
  tasks::calculatePoolCosts(3.0, 1.0, 1000.0, 2000.0,
                            concreteCost, fenceCost);
  std::cout << "Pool problem:\n";
  std::cout << "  Concrete cost: " << concreteCost << " rubles\n";
  std::cout << "  Fence cost: " << fenceCost << " rubles\n";
  std::cout << "  Total cost: " << concreteCost + fenceCost;
  std::cout << " rubles\n";

  return 0;
}
