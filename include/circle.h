// Copyright 2026 Salykina Alena

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double radius;
    double ference;
    double area;

 public:
    explicit Circle(double radius);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;

    void setRadius(double n_radius);
    void setFerence(double n_ference);
    void setArea(double n_area);
};

#endif  // INCLUDE_CIRCLE_H_
