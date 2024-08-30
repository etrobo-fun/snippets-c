#include <gtest/gtest.h>
#include "rgb2hsv.h"

TEST(Rgb2HsvTest, Red)
{
  rgb in = {255, 0, 0};
  hsv out;
  convert_rgb_to_hsv(&in, &out);
  EXPECT_EQ(out.h, 0);
  EXPECT_EQ(out.s, 255);
  EXPECT_EQ(out.v, 255);
}

TEST(Rgb2HsvTest, Green)
{
  rgb in = {0, 255, 0};
  hsv out;
  convert_rgb_to_hsv(&in, &out);
  EXPECT_EQ(out.h, 120);
  EXPECT_EQ(out.s, 255);
  EXPECT_EQ(out.v, 255);
}

TEST(Rgb2HsvTest, Blue)
{
  rgb in = {0, 0, 255};
  hsv out;
  convert_rgb_to_hsv(&in, &out);
  EXPECT_EQ(out.h, 240);
  EXPECT_EQ(out.s, 255);
  EXPECT_EQ(out.v, 255);
}

TEST(Rgb2HsvTest, White)
{
  rgb in = {255, 255, 255};
  hsv out;
  convert_rgb_to_hsv(&in, &out);
  EXPECT_EQ(out.h, 0);
  EXPECT_EQ(out.s, 0);
  EXPECT_EQ(out.v, 255);
}

TEST(Rgb2HsvTest, Black)
{
  rgb in = {0, 0, 0};
  hsv out;
  convert_rgb_to_hsv(&in, &out);
  EXPECT_EQ(out.h, 0);
  EXPECT_EQ(out.s, 0);
  EXPECT_EQ(out.v, 0);
}

TEST(Rgb2HsvTest, Random1)
{
  rgb in = {38, 143, 140};
  hsv out;
  convert_rgb_to_hsv(&in, &out);
  EXPECT_EQ(out.h, 178);
  EXPECT_EQ(out.s, 187);
  EXPECT_EQ(out.v, 143);
}
