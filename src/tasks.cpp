#include "circle.h"

double Earth_Roop() {
    Circle roop;
    
    double earth_rad = 6378.1;
    roop.setRadius(earth_rad + 0.001);

    return roop.getFerence();
}

double Pool(){
    Circle pool;
    pool.setRadius(3.0);
    double track_ext_rad = pool.getRadius() + 1.0;
    double track_area = track_ext_rad * track_ext_rad * PI - pool.getArea();
    double track_cost = track_area * 1000;

    Circle bound;
    bound.setRadius(pool.getRadius() + 1.0);
    double bound_cost = bound.getFerence() * 2000;

    return track_cost + bound_cost;

}
