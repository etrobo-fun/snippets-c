#define KP 0.9
#define KI 0
#define KD 0
#define DELTA_T 0.01

double error = 0;
double lastError = 0;
double target = 20;

double p = 0, i = 0; d = 0;

double calc_pid_control(double input)
{
  lastError = error;
  double error = input - target;

  p = error;
  i += (lastError + error) / 2.0 * DELTA_T;
  d = (error - lastError) / DELTA_T;

	return KP * p + KI * i + KD * d;
}
