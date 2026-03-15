#include "circle.h"
#include "../include/tasks.h"

double EarthTask() {
    Circle earth = Circle(RADIUS_OF_EARTH);
    earth.setRadius(RADIUS_OF_EARTH + 1);
    return earth.getRadius() - RADIUS_OF_EARTH;
}

double Pool() {
    Circle pool = Circle(RADIUS_OF_POOL);
    Circle poolWithRoad = Circle(RADIUS_OF_POOL + WIDTH_OF_ROAD);
    double costOfRoad = (poolWithRoad.getArea() - pool.getArea()) * COST_OF_CONCRETE_COATING;
    double costOfFence = poolWithRoad.getFerence() * COST_OF_METER_FENCE;
    return costOfFence + costOfRoad;
}