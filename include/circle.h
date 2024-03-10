// Copyright 2024 Kochetov Nikolay
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>


#endif  // INCLUDE_CIRCLE_H_
#include <string>

class Circle {
 private:
    double _radius;
    double _area;
    double _ference;

 public:
    explicit Circle(double radius);

    [[nodiscard]] double GetRadius() const;
    [[nodiscard]] double GetArea() const;
    [[nodiscard]] double GetFerence() const;

    void SetRadius(double radius);
    void SetArea(double area);
    void SetFerence(double ference);

 private:
    static void ThrowErrorIfValueIsNotPositive(
            double value,
            const std::string& nameOfVariable);
};
