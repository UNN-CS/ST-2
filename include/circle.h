// Copyright 2024 Timofey Vinichuk
#pragma once
#define M_PI 3.14159265358979323846

class circle{
 private:
    double _radius;
    double _ference;
    double _area;

 public:
    explicit circle(double radius);
    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);
    double getRadius();
    double getFerence();
    double getArea();
};
