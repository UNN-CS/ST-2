// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
 private:
     double radius_;
     double ference_;
     double area_;
 public:
     Circle() {}
     explicit Circle(double r) { this->setRadius(r); }
     void setRadius(double radius);
     void setFerence(double ference);
     void setArea(double area);
     double getRadius();
     double getFerence();
     double getArea();
};

#endif  // INCLUDE_CIRCLE_H_
