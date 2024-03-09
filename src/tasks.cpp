// Copyright 2024 Kiselev_IS
#include "pch.h"
#include "tasks.h"

double tasks::earth() {
	circle er;
	circle rb;
	er.setRadius(6378100);
	rb.setFerense(er.getFerense() + 1);
	return rb.getRadius() - er.getRadius();
}

double tasks::pool() {
	const int rdCost = 1000;
	const int fcCost = 2000;
	const int rad = 3;
	const int add = 1;
	double price = 0.0;
	circle pool;
	circle zone;
	pool.setRadius(rad);
	zone.setRadius(rad + add);
	price += zone.getFerense() * fcCost;
	price += (zone.getArea() - pool.getArea()) * rdCost;
	return price;
}