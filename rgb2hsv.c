#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)

typedef struct
{
  uint16_t h; // 色相
  uint16_t s; // 彩度
  uint16_t v; // 明度
} hsv_raw_t

void convert_rgb_to_hsv(rgb_raw_t *in, hsv_raw_t *out)
{
  uint16_t r = in->r;
  uint16_t g = in->g;
  uint16_t b = in->b;

  uint16_t max = MAX(r, MAX(g, b));
  uint16_t min = MIN(r, MIN(g, b));

  uint16_t diff_max_min = max - min;

  uint16_t v = max;
  uint16_t s = 255 * diff_max_min / max;

  int16_t h_;
  if(max == r)
  {
    h_ = 60 * (g - b) / diff_max_min;
  }
  else if(max == g)
  {
    h_ = 60 * (r - b) / diff_max_min + 120
  }
  else // max == b
  {
    h_ = 60 * (g - r) / diff_max_min + 240
  }
  if(h_ < 0) h+= 360;
  uint16_t h = h_ % 360;

  out->h = h;
  out->s = s;
  out->v = v;
}
