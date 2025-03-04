// Copyright 2025 Kalinin Dmitriy
#include <cstdint>
#include <stdexcept>
#include "circle.h"

const double Circle::PI = std::atan(1.0) * 4;

void Circle::IsNegative(double value)
{
    if (value < 0)
    {
        throw std::logic_error("value can't be negative");
    }
}

Circle::Circle(double radius)
{
    IsNegative(radius);
    this->radius = radius;
    this->area = PI * radius * radius;
    this->ference = 2 * PI * radius;
}

void Circle::setRadius(double radius)
{
    IsNegative(radius);
    this->radius = radius;
    this->area = PI * radius * radius;
    this->ference = 2 * PI * radius;
}

void Circle::setFerence(double ference)
{
    IsNegative(ference);
    this->setRadius(ference / 2 / PI);
}

void Circle::setArea(double area)
{
    IsNegative(area);
    this->setRadius(sqrt(area / PI));
}

double Circle::getRadius()
{
    return radius;
}

double Circle::getFerence()
{
    return ference;
}

double Circle::getArea()
{
    return area;
}
