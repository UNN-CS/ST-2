//
// Created by Андрей Юрин on 08.03.2024.
//

#ifndef ST_2_CIRCLE_Е_H
#define ST_2_CIRCLE_Е_H


#include <iostream>

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
    static void ThrowErrorIfValueIsNotPositive(double value, const std::string& nameOfVariable) ;

};

#endif //ST_2_CIRCLE_Е_H
