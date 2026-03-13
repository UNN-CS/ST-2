#include <stdexcept>

#include "circle.h"
#include "tasks.h"

double calculateEarthRopeGap(double earth_radius_km, double rope_extra_meters) {
    if (earth_radius_km < 0.0 || rope_extra_meters < 0.0) {
        throw std::invalid_argument("Input values cannot be negative");
    }

    Circle earth(earth_radius_km * 1000.0);
    earth.setFerence(earth.getFerence() + rope_extra_meters);
    return earth.getRadius() - earth_radius_km * 1000.0;
}

double calculateConcreteCost(double pool_radius_m,
                             double path_width_m,
                             double concrete_cost_per_sq_m) {
    if (pool_radius_m < 0.0 || path_width_m < 0.0 || concrete_cost_per_sq_m < 0.0) {
        throw std::invalid_argument("Input values cannot be negative");
    }

    Circle pool(pool_radius_m);
    Circle with_path(pool_radius_m + path_width_m);
    return (with_path.getArea() - pool.getArea()) * concrete_cost_per_sq_m;
}

double calculateFenceCost(double pool_radius_m,
                          double path_width_m,
                          double fence_cost_per_m) {
    if (pool_radius_m < 0.0 || path_width_m < 0.0 || fence_cost_per_m < 0.0) {
        throw std::invalid_argument("Input values cannot be negative");
    }

    Circle with_path(pool_radius_m + path_width_m);
    return with_path.getFerence() * fence_cost_per_m;
}
