#ifndef PID_CONTROL_H
#define PID_CONTROL_H

#define KP 0.9
#define KI 0
#define KD 0
#define DELTA_T 0.01

double calc_pid_control(double input);

#endif
