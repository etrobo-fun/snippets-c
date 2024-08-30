#include "moving_average_filter.h"

static int inputs[SIZE];

void init_average_filter(void)
{
  for(int i = 0; i < SIZE; i++)
  {
    inputs[i] = 0;
  }
}

int average_filter(int input)
{
  // 更新
  for(int i = 0; i < SIZE - 1; i++)
  {
    inputs[i + 1] = inputs[i];
  }
  inputs[0] = input;

  int sum = 0;

  // 直近の総和を計算
  for(int i = 0; i < SIZE; i++)
  {
    sum += inputs[i];
  }

  return sum / SIZE;
}
