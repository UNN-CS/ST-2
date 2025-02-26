// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double radius;
    double ference;
    double area;
    void updateFromRadius();
    void updateFromFerence();
    void updateFromArea();

 public:
    explicit Circle(double radius);
    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);
    [[nodiscard]] double getRadius() const;
    [[nodiscard]] double getFerence() const;
    [[nodiscard]] double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
