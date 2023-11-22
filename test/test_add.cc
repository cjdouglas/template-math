#include <gtest/gtest.h>

#include "template_math.h"

using tmath::Add;

TEST(TestTMathAdd, TestPositiveAdd) {
  EXPECT_EQ(Add<int>().apply(5, 3), 8);
  EXPECT_FLOAT_EQ(Add<float>().apply(1.2f, 2.4f), 3.6f);
  EXPECT_DOUBLE_EQ(Add<double>().apply(5.43, 3.33), 8.76);
}

TEST(TestTMathAdd, TestNegativeAdd) {
  EXPECT_EQ(Add<int>().apply(-5, -3), -8);
  EXPECT_FLOAT_EQ(Add<float>().apply(-1.2f, -2.4f), -3.6f);
  EXPECT_DOUBLE_EQ(Add<double>().apply(-5.43, -3.33), -8.76);
}

TEST(TestTMathAdd, TestMixedSignAdd) {
  EXPECT_EQ(Add<int>().apply(-5, 3), -2);
  EXPECT_FLOAT_EQ(Add<float>().apply(-1.2f, 2.4f), 1.2f);
  EXPECT_DOUBLE_EQ(Add<double>().apply(5.43, -3.33), 2.1);
}

TEST(TestTMathAdd, TestZeroAdd) {
  EXPECT_EQ(Add<int>().apply(5, 0), 5);
  EXPECT_FLOAT_EQ(Add<float>().apply(0.0f, -2.4f), -2.4f);
  EXPECT_DOUBLE_EQ(Add<double>().apply(0.0, 0.0), 0.0);
}

TEST(TestTMathAdd, TestMixedTypeAdd) {
  const float f = Add<int, float>().apply(5, 3.0f);
  EXPECT_FLOAT_EQ(f, 8.0f);

  const double d = Add<double, float>().apply(2.5, 3.5f);
  EXPECT_DOUBLE_EQ(d, 6.0);

  const int i = Add<int, int>().apply(5, -3);
  EXPECT_EQ(i, 2);
}
