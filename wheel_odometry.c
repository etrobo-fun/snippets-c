#include <math.h>

#define DELTA_T 0.01 // [s]
#define TIRE_WIDTH 9.0 // [cm]
#define TREAD_WIDTH 15.0 // [cm]

int32_t last_left = 0, last_right = 0, now_left = 0, now_right = 0;
double v_r, v_l, v, last_v = 0, theta = 0, last_theta = 0, x = 0, y = 0;
 
void calc_odometry()
{
  last_v = v;
  last_theta = theta;

  last_left = now_left;
  last_right = now_right;

	now_left = ev3_motor_get_counts(left_motor);
	now_right = ev3_motor_get_counts(right_motor);

  v_l = (now_left  - last_left) * (TIRE_WIDTH / 2);
  v_r = (now_right  - last_right) * (TIRE_WIDTH / 2);

  v = (v_r + v_l) / 2;
  theta += (v_r - v_l) / TREAD_WIDTH;

  x += (v * cos(theta) + last_v * cos(last_thetals)) / 2 * DELTA_T;
  y += (v * sin(theta) + last_v * sin(last_theta)) / 2 * DELTA_T;
}
