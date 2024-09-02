#include <gtest/gtest.h>
#include "rgb2hsv.h"

void rgb2hsv_test(rgb in, hsv expected)
{
  hsv actual;
  convert_rgb_to_hsv(&in, &actual);
  EXPECT_EQ(actual.h, expected.h);
  EXPECT_EQ(actual.s, expected.s);
  EXPECT_EQ(actual.v, expected.v);
}

TEST(Rgb2HsvTest, Red)
{
  rgb2hsv_test({255, 0, 0}, {0, 255, 255});
}

TEST(Rgb2HsvTest, Green)
{
  rgb2hsv_test({0, 255, 0}, {120, 255, 255});
}

TEST(Rgb2HsvTest, Blue)
{
  rgb2hsv_test({0, 0, 255}, {240, 255, 255});
}

TEST(Rgb2HsvTest, White)
{
  rgb2hsv_test({255, 255, 255}, {0, 0, 255});
}

TEST(Rgb2HsvTest, Black)
{
  rgb2hsv_test({0, 0, 0}, {0, 0, 0});
}

TEST(Rgb2HsvTest, RandomRedMax)
{
  rgb2hsv_test({135, 6, 30}, {349, 243, 135});
}

TEST(Rgb2HsvTest, RandomGreenMax)
{
  rgb2hsv_test({38, 143, 140}, {178, 187, 143});
}

TEST(Rgb2HsvTest, RandomBlueMax)
{
  rgb2hsv_test({1, 72, 83}, {188, 251, 83});
}
