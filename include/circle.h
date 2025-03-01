#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
private:
	double radius;
	double ference;
	double area;

	void UpdateFromRadius();
	void UpdateFromFerence();
	void UpdateFromArea();
public:
	explicit Circle(double r);
	void SetRadius(double r);
	void SetFerence(double f);
	void SetArea(double a);
	double GetRadius();
	double GetFerence();
	double GetArea();
};

#endif // INCLUDE_CIRCLE_H_
