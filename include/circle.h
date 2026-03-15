// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 public:
    explicit Circle(double radius);

    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;

 private:
    static constexpr double kPi = 3.14159265358979323846;

    double radius_;
    double ference_;
    double area_;

    void updateFromRadius();
};


#endif  // INCLUDE_CIRCLE_H_
