// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
class Circle
{
	double radius;
	double ference;
	double area;
public:
	Circle(double r, double f, double a) {
		radius = r;
		ference = r;
		area = a;
	}
	void setRadius(double r);
	void setFerence(double f);
	void setArea(double a);
	double	getRadius();
	double	getFerence();
	double	getArea();

};


#endif  // INCLUDE_CIRCLE_H_


