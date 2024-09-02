#include "rgb2hsv.h"
#include <stdio.h>

void convert_rgb_to_hsv(rgb *in, hsv *out)
{
  uint16_t r = in->r;
  uint16_t g = in->g;
  uint16_t b = in->b;

  uint16_t max = MAX(r, MAX(g, b));
  uint16_t min = MIN(r, MIN(g, b));

  uint16_t diff_max_min = max - min;

  uint16_t v = max;
  uint16_t s = 0 < max ? 255 * diff_max_min / max : 0;

  int16_t h_;
  if(diff_max_min == 0)
  {
    h_ = 0;
  }
  else if(max == r)
  {
    h_ = 60 * (g - b) / diff_max_min;
  }
  else if(max == g)
  {
    h_ = 60 * (b - r) / diff_max_min + 120;
  }
  else // max == b
  {
    h_ = 60 * (r - g) / diff_max_min + 240;
  }

  if(h_ < 0) h_ += 360;
  uint16_t h = h_ % 360;

  out->h = h;
  out->s = s;
  out->v = v;
}
