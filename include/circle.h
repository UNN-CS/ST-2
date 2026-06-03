// Copyright 2024 Nazyrov A.A.

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

namespace geometry {

class Circle {
 private:
  double radius_;
  double circumference_;
  double area_;

  void updateFromRadius();
  void updateFromCircumference();
  void updateFromArea();

 public:
  explicit Circle(double radius);

  void setRadius(double radius);
  void setCircumference(double circumference);
  void setArea(double area);

  double getRadius() const;
  double getCircumference() const;
  double getArea() const;
};

}  // namespace geometry

#endif  // INCLUDE_CIRCLE_H_
