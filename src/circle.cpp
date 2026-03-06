// Copyright 2022 UNN-CS
#include <cstdint>
#include "circle.h"

Circle::Circle (double r) {
    setRadius(r);
}

void Circle::setRadius(double r) {
    radius = r;
    ference = 2*pi*radius;
    area = pi*radius*radius;
}

void Circle::setFerence(double f){
    ference = f;
    radius = ference / (2*pi);
    area = pi*radius*radius;
}

void Circle::setArea(double a){
    area = a;
    radius = area / (pi*radius*radius);
    ference = 2*pi*radius;
}

double Circle::getRadius(){
    return radius;
}

double Circle::getFerence(){
    return ference;
}

double Circle::getArea(){
    return area;
}