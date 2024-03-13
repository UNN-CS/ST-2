// Copyright 2024 Smirnov Leonid

#pragma once

class Circle {
 private:
    static const double PI;
    double radius;
    double ference;
    double area;
    static double CheckingTheInputData(double radius);

 public:
    explicit Circle(double raduisValue = 0);
    double GetRadius() const;
    double GetFerence() const;
    double GetArea() const;

    void SetRadius(double value);
    void SetFerence(double value);
    void SetArea(double value);
};
