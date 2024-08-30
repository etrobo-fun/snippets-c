#ifndef RGB2HSV_H
#define RGB2HSV_H

#include <stdint.h>

#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)

typedef struct
{
  uint16_t r;
  uint16_t g;
  uint16_t b;
} rgb;

typedef struct
{
  uint16_t h; // 色相
  uint16_t s; // 彩度
  uint16_t v; // 明度
} hsv;

void convert_rgb_to_hsv(rgb *in, hsv *out);

#endif
