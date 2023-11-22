#include <gtest/gtest.h>

#include "template_math.h"

using tmath::TVal;

TEST(TestTVal, TestAdd) {
  const TVal<int> x = 5;
  const TVal<int> y = 3;
  const TVal<int> z = -7;
  const TVal<float> f = 3.5f;
  EXPECT_EQ((x + y)(), 8);
  EXPECT_EQ((x + z)(), -2);
  EXPECT_EQ((z + z)(), -14);
  EXPECT_FLOAT_EQ((x + f)(), 8.5f);
  EXPECT_EQ((x + 3)(), 8);
  EXPECT_FLOAT_EQ((y + 1.2f)(), 4.2f);
}

TEST(TestTVal, TestSub) {
  const TVal<double> x = 4.5;
  const TVal<int> y = -1;
  const TVal<float> z = 1.2f;
  EXPECT_DOUBLE_EQ((x - y)(), 5.5);
  EXPECT_FLOAT_EQ((y - z)(), -2.2f);
  EXPECT_EQ((y - y)(), 0);
  EXPECT_EQ((y - 3)(), -4);
}

TEST(TestTVal, TestDiv) {
  const TVal<int> x = 6;
  const TVal<int> y = 3;
  const TVal<double> z = 2.0;
  EXPECT_EQ((x / y)(), 2);
  EXPECT_DOUBLE_EQ((x / z)(), 3.0);
  EXPECT_FLOAT_EQ((x / 1.5f)(), 4.0f);
}

TEST(TestTVal, TestMul) {
  const TVal<int> x = 6;
  const TVal<int> y = 3;
  const TVal<double> z = 2.0;
  EXPECT_EQ((x * y)(), 18);
  EXPECT_DOUBLE_EQ((y * z)(), 6.0);
  EXPECT_FLOAT_EQ((y * 3.0f)(), 9.0f);
}
