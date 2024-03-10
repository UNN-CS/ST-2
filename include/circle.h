// Copyright 2024 Khramov Ivan
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cmath>
#include <stdexcept>

class Circle {
 private:
    static const double PI;

    double radius;
    double ference;
    double area;
 public:
    explicit Circle(double radius = 0);

    void SetFerence(double ference);
    void SetRadius(double radius);
    void SetArea(double area);

    double GetRadius() const;
    double GetFerence() const;
    double GetArea() const;

    void ComputeFerence();
    void ComputeArea();

    static double CheckValueError(double value);
};


#endif  // INCLUDE_CIRCLE_H_
