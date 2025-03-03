// Copyright 2025

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

const double PI = 3.14159265359;

class Circle {
 private:
    double radius;
    double ference;
    double area;

    void recalculateFromRadius();
    void recalculateFromFerence();
    void recalculateFromArea();

 public:
    Circle(double r);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius();
    double getFerence();
    double getArea();
};

#endif // INCLUDE_CIRCLE_H_
