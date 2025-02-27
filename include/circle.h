// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>

class Circle {
 public:
  explicit Circle(double radius);

  void setRadius(double radius);
  void setCircumference(double circumference);
  void setArea(double area);

  double getRadius() const;
  double getCircumference() const;
  double getArea() const;

 private:
  double radius;
  double circumference;
  double area;

  void calculateFromRadius();
  void calculateFromCircumference();
  void calculateFromArea();
};

#endif // INCLUDE_CIRCLE_H_
