// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include "circle.h"

Circle::Circle(double radius) : radius(radius)
{
    // check radius
    ference = 2.0 * radius * Circle::PI;
    area = Circle::PI * radius * radius;
}

void Circle::setRadius(double val)
{
    // check radius
    radius = val;
    ference = 2.0 * radius * Circle::PI;
    area = Circle::PI * radius * radius;
}
    
void Circle::setFerence(double val)
{
    // check ference
    ference = val;
    radius = ference / (2 * Circle::PI);
    area = Circle::PI * radius * radius; 
}

void Circle::setArea(double val)
{
    // check area
    area = val;
    radius = std::sqrt(area / Circle::PI);
    ference = 2.0 * radius * Circle::PI;
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const {return area; }
