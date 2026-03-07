// Copyright 2022 UNN-CS
#include <iostream>
#include <cstdint>
#include <math.h>
#include "circle.h"

Circle::Circle() {
    this->ference = 0.0;
    this->area = 0.0;
    this->radius = 0.0;
}

Circle::Circle(double getR) {
    this->setRadius(getR);
}

void Circle::setRadius(double getR) {
    this->radius = getR;
    double temp = radius * radius;
    this->ference = 2 * PI * this->radius;
    this->area = PI * temp;
}

void Circle::setArea(double getA) {
    this->area = getA;
    double temp = this->area / PI;
    this->radius = sqrt(temp);
    this->ference = 2 * PI * this->radius;
}

void Circle::setFerence(double getF) {
    this->ference = getF;
    this->radius = this->ference / (2 * PI);
    this->area = PI * (radius * radius);
}

double Circle::getRadius() {
    return this->radius;
}

double Circle::getFerence() {
    return this->ference;
}

double Circle::getArea() {
    return this->area;
}


