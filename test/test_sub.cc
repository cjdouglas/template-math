#include <gtest/gtest.h>

#include "template_math.h"

using tmath::Sub;

TEST(TestTMathSub, TestPositiveSub) {
  EXPECT_EQ(Sub<int>().apply(5, 3), 2);
  EXPECT_FLOAT_EQ(Sub<float>().apply(10.5f, 3.63f), 6.87f);
  EXPECT_DOUBLE_EQ(Sub<double>().apply(3.72, 1.664), 2.056);
}
