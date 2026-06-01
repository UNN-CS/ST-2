// Copyright 2025 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
  double radius;
  double circumference;
  double areaValue;

  void updateCircumference();
  void updateArea();

 public:
  explicit Circle(double initialRadius);

  void setRadius(double newRadius);
  void setFerence(double newCircumference);
  void setArea(double newArea);

  double getRadius() const;
  double getFerence() const;
  double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
