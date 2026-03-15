// Copyright 2026 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
  double radius_{0.0};
  double ference_{0.0};
  double area_{0.0};

  void recalcFromRadius();
  void recalcFromFerence();
  void recalcFromArea();

 public:
  explicit Circle(double radius = 0.0);

  void setRadius(double radius);
  void setFerence(double ference);
  void setArea(double area);

  double getRadius() const noexcept;
  double getFerence() const noexcept;
  double getArea() const noexcept;
};

#endif  // INCLUDE_CIRCLE_H_
