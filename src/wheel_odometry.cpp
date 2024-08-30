#include "wheel_odometry.h"

static int32_t last_left = 0, last_right = 0, now_left = 0, now_right = 0;
static double v_r, v_l, v, last_v = 0, theta = 0, last_theta = 0, x = 0, y = 0;

void calc_odometry(int32_t left_count, int32_t right_count)
{
  last_v = v;
  last_theta = theta;

  last_left = now_left;
  last_right = now_right;

	now_left = left_count;
	now_right = right_count;

  v_l = (now_left  - last_left) * (TIRE_WIDTH / 2);
  v_r = (now_right  - last_right) * (TIRE_WIDTH / 2);

  v = (v_r + v_l) / 2;
  theta += (v_r - v_l) / TREAD_WIDTH;

  x += (v * cos(theta) + last_v * cos(last_theta)) / 2 * DELTA_T;
  y += (v * sin(theta) + last_v * sin(last_theta)) / 2 * DELTA_T;
}
