// Copyright 2022 UNN-CS
#define _USE_MATH_DEFINES
#include <cmath>  // меняем math.h на cmath
#include <cstdint>

#include "circle.h"  // свой заголовок должен быть первым после системных

Circle::Circle(double radius) {  // добавляем пробел перед {
  this->radius = radius;
  this->ference = 2 * M_PI * radius;
  this->area = M_PI * radius * radius;
}

double Circle::getRadius() {
  return radius;
}

double Circle::getFerence() {
  return ference;
}

double Circle::getArea() {
  return area;
}

void Circle::setRadius(double radius) {
  this->radius = radius;
  this->ference = 2 * M_PI * radius;
  this->area = M_PI * radius * radius;
}

void Circle::setFerence(double ference) {
  this->ference = ference;
  this->radius = ference / (2 * M_PI);
  this->area = M_PI * this->radius * this->radius;
}

void Circle::setArea(double area) {
  this->area = area;
  this->radius = sqrt(area / M_PI);
  this->ference = 2 * M_PI * this->radius;
}

double Circle::calculationFerence() {
  return 2 * M_PI * radius;
}

double Circle::calculationArea() {
  return M_PI * radius * radius;
}

double Circle::calculationRadius() {
  return radius;
}
