// Copyright 2022 UNN-CS
#include <cmath>
#include "circle.h"

const double PI = 3.14159265358979323846;

Circle::Circle(double r)
{
    setRadius(r);
}

void Circle::setRadius(double r)
{
    radius = r;
    updateFerence();
    updateArea();
}

void Circle::setFerence(double f)
{
    ference = f;
    updateRadius();
    updateArea();
}

void Circle::setArea(double a)
{
    area = a;
    updateRadius();
    updateFerence();
}

double Circle::getRadius() const
{
    return radius;
}

double Circle::getFerence() const
{
    return ference;
}

double Circle::getArea() const
{
    return area;
}

void Circle::updateFerence()
{
    ference = 2 * PI * radius;
}

void Circle::updateArea()
{
    area = PI * radius * radius;
}

void Circle::updateRadius()
{
    radius = ference / (2 * PI);
}