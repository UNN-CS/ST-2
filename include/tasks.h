// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double GetRopeGapAfterAddingLength(double added_length_m);

double GetPoolConcreteCost(double pool_radius_m,
                           double path_width_m,
                           double cost_per_square_meter);

double GetPoolFenceCost(double pool_radius_m,
                        double path_width_m,
                        double cost_per_meter);

#endif  // INCLUDE_TASKS_H_
