#include "tasks.h"

double tasks::pool()
{
	double cost = 0;
	C.setRadius(3);
	double pool_area = C.getArea();
	C.setRadius(4);
	double all_area = C.getArea();
	// бетонная дорожка
	cost += (all_area - pool_area) * 1000;
	// забор
	cost += C.getFerence() * 2000;
	return cost;
}
double tasks::rope()
{
	C.setRadius(6378100);
	double new_ference = C.getFerence() + 1;
	C.setFerence(new_ference);
	return C.getRadius() - 6378100;  
}