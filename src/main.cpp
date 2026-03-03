// Copyright 2022 UNN-CS
#include "circle.h"
#include <iostream>

int main() {
    // Circle a;
    // a.setArea(5);
    // std::cout << "Radius: "<< a.getRadius() << std::endl;
    // std::cout << "Ference: "<< a.getFerence() << " (F = 2 * pi * radius)" << std::endl;
    // std::cout << "Area: "<< a.getArea() << " (A = pi * radius^2)" << std::endl;

    const double Earth_radius_in_kilometers = 6378.1;
    const double Earth_radius_in_meters = 6378.1 * 1000.0;
    double Rope_radius_in_meters = Earth_radius_in_meters;

    Circle Earth;
    Earth.setRadius(Earth_radius_in_meters);

    Circle Rope;
    Rope.setRadius(Rope_radius_in_meters);

    double ference_new = Rope.getFerence() + 1;

    Rope.setFerence(ference_new);

    std::cout << "Radius Earth: " << Earth.getRadius() << std::endl;
    std::cout << "Radius Rope_new: " << Rope.getRadius() << std::endl;
    std::cout << "Gap: " << Rope.getRadius() - Earth.getRadius() << std::endl;
}