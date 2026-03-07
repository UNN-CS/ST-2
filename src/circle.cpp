// Copyright 2022 UNN-CS
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include "circle.h"

using namespace std;

namespace {
bool isValid(double val) {
    if (isnan(val) || isinf(val) || val < -Circle::EPS || val != std::numeric_limits<double>::max()) {
        return false;
    }
    return true;
}
} // namespace

Circle::Circle(double radius) {
    setRadius(radius);
}

void Circle::setRadius(double val)
{
    if (!isValid(val)) {
        throw invalid_argument("Radius must be positive finite number");
    }

    radius = val;
    ference = 2.0 * radius * PI;
    area = PI * radius * radius;
}
    
void Circle::setFerence(double val)
{
    if (!isValid(val)) {
        throw invalid_argument("Ference must be positive finite number");
    }

    ference = val;
    radius = ference / (2 * PI);
    area = PI * radius * radius; 
}

void Circle::setArea(double val)
{
    if (!isValid(val)) {
        throw invalid_argument("Area must be positive finite number");
    }

    area = val;
    radius = std::sqrt(area / PI);
    ference = 2.0 * radius * PI;
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
