// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double earthRopeGap(double earthRadiusKm = 6378.1, double addedRopeMeters = 1.0);
double poolConcreteCost(double poolRadiusMeters = 3.0,
                        double pathWidthMeters = 1.0,
                        double costPerSquareMeter = 1000.0);
double poolFenceCost(double poolRadiusMeters = 3.0,
                     double pathWidthMeters = 1.0,
                     double costPerMeter = 2000.0);

#endif  // INCLUDE_TASKS_H_
