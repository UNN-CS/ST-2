// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"
#include <cassert>

void testCircle() {
	Circle c(5);
	assert(c.getRadius() == 5);
	assert(c.getFerence() == 2 * 3.14159265358979323846 * 5);
	assert(c.getArea() == 3.14159265358979323846 * 5 * 5);

	c.setRadius(10);
	assert(c.getRadius() == 10);
	assert(c.getFerence() == 2 * 3.14159265358979323846 * 10);
	assert(c.getArea() == 3.14159265358979323846 * 10 * 10);

	c.setFerence(62.831853);
	assert(c.getRadius() == 10);

	c.setArea(314.159265);
	assert(c.getRadius() == 10);

	c.setRadius(0);
	assert(c.getRadius() == 0);
	assert(c.getFerence() == 0);
	assert(c.getArea() == 0);

	c.setRadius(1);
	assert(c.getFerence() == 2 * 3.14159265358979323846 * 1);
	assert(c.getArea() == 3.14159265358979323846 * 1 * 1);

	c.setFerence(6.283185307179586);
	assert(c.getRadius() == 1);

	c.setArea(3.14159265358979323846);
	assert(c.getRadius() == 1);

	c.setFerence(12.566370614359172);
	assert(c.getRadius() == 2);

	c.setArea(12.566370614359172);
	assert(c.getRadius() == 2);
}

void testTasks() {
	assert(calculateGap(1) > 0);
	assert(calculatePoolCost(3, 1) > 0);

	assert(calculateGap(0) == 0);
	assert(calculatePoolCost(0, 1) == 2000);

	assert(calculatePoolCost(3, 0) == 6000);
	assert(calculatePoolCost(5, 1) > 0);

	assert(calculatePoolCost(100, 10) > 0);
	assert(calculateGap(10) > 0);

	assert(calculatePoolCost(0.1, 0.1) > 0);
	assert(calculateGap(0.1) > 0);
}
