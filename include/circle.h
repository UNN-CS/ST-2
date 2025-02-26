// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <assert.h>
#include <cstdint>
#include <iostream>
#include <math.h>
enum class calculatings { Ference, Area };

class Circle {
  double m_radius = 0.0;
  double m_ference = 0.0;
  double m_area = 0.0;
  static constexpr double pi = 3.1415926;

  void Calculate(calculatings calculating) noexcept {
    switch (calculating) {
    case calculatings::Ference:
      m_ference = 2 * pi * m_radius;
      break;
    case calculatings::Area:
      m_area = pi * m_radius * m_radius;
      break;
    default:
      break;
    }
  }

 public:
  Circle() = default;
  explicit Circle(double radius) noexcept {
    assert(radius > 0.0);
    m_radius = radius;
    Calculate(calculatings::Ference);
    Calculate(calculatings::Area);
  }
  bool SetRadius(double radius) noexcept {
    if (radius > 0.0) {
      m_radius = radius;
      Calculate(calculatings::Ference);
      Calculate(calculatings::Area);
      return true;
    }
    return false;
  }
  bool SetFerence(double ference) noexcept {
    if (ference > 0.0) {
      m_ference = ference;
      m_radius = m_ference / (2 * pi);
      Calculate(calculatings::Area);
      return true;
    }
    return false;
  }

  bool SetArea(double area) noexcept {
    if (area > 0.0) {
      m_area = area;
      m_radius = std::sqrt(m_area / pi);
      Calculate(calculatings::Ference);
      return true;
    }
    return false;
  }
  double GetRadius() const noexcept { return m_radius; }
  double GetFerence() const noexcept { return m_ference; }
  double GetArea() const noexcept { return m_area; }
};

#endif // INCLUDE_CIRCLE_H_
