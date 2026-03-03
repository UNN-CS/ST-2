#include "tasks.h"
#include "circle.h"

double calculateGap() {
    const double Earth_radius_in_meters = 6378.1 * 1000.0;
    double Rope_radius_in_meters = Earth_radius_in_meters;

    Circle Earth;
    Earth.setRadius(Earth_radius_in_meters);

    Circle Rope;
    Rope.setRadius(Rope_radius_in_meters);

    double ference_new = Rope.getFerence() + 1;

    Rope.setFerence(ference_new);

    return Rope.getRadius() - Earth.getRadius();
}

PoolCosts calculateCosts() {
    const double cost_of_one_square_meter_of_concrete_pavement = 1000.0;
    const double cost_of_one_linear_meter_of_fence = 2000.0;
    const double width_of_the_concrete_walkway_around_the_pool = 1.0;

    Circle pool;
    pool.setRadius(3.0);

    Circle pool_with_walkway;
    pool_with_walkway.setRadius(3.0 + width_of_the_concrete_walkway_around_the_pool);

    double area_walkway = pool_with_walkway.getArea() - pool.getArea();

    double ference_fence = pool_with_walkway.getFerence();

    double full_cost_concrete_pavement = cost_of_one_square_meter_of_concrete_pavement * area_walkway;
    
    double full_cost_fence = cost_of_one_linear_meter_of_fence * ference_fence;

    return PoolCosts{full_cost_concrete_pavement, full_cost_fence};
}