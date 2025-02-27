// Copyright 2022 UNN-CS
#define _USE_MATH_DEFINES
#include <cstdint>
#include "circle.h"
#include <cmath>

void Circle::setRadius(double radius)
{
	if (radius < 0) return;
	radius_ = radius;
	ference_ = 2 * M_PI * radius_;
	area_ = M_PI * pow(radius_, 2);
}

void Circle::setFerence(double ference)
{
	if (ference < 0) return;
	ference_ = ference;
	radius_ = ference_ / (2 * M_PI);
	area_ = M_PI * pow(radius_, 2);
}

void Circle::setArea(double area)
{
	if (area < 0) return;
	area_ = area;
	radius_ = sqrt(area_ / M_PI);
	ference_ = 2 * M_PI * radius_;
}

double Circle::getRadius() 
{
	return radius_;
}

double Circle::getFerence()
{
	return ference_;
}

double Circle::getArea()
{
	return area_;
}
