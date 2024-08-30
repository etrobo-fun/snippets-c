#ifndef WHEEL_ODOMETRY_H
#define WHEEL_ODOMETRY_H

#include <stdint.h>
#include <math.h>

#define DELTA_T 0.01 // [s]
#define TIRE_WIDTH 9.0 // [cm]
#define TREAD_WIDTH 15.0 // [cm]

void calc_odometry(int32_t left_count, int32_t right_count);

#endif
