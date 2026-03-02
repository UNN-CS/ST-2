// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

const double pi=3.14;

Circle::Circle(double r){
    setRadius(r);
}

void Circle::setRadius(double r){
    radius = r;
    frence = 2*pi*radius;
    area = std::pi*pow(radius, 2);
}

void Circle::setFerence(double f){
    ference = f;
    radius = f/(2*pi);
    area = pi*pow(radius, 2);
}

void Circle::setArea(double a){
    area = a;
    radius =  std::sqrt(area/pi);
    ference = 2*pi*radius;
}

double Circle::getRadius() const {
    return radius;
}
double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
