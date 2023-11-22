#include <gtest/gtest.h>

#include "template_math.h"

using tmath::Div;

TEST(TestTMathDiv, TestPositiveDiv) {
  EXPECT_EQ(Div<int>().apply(6, 3), 2);
  EXPECT_EQ(Div<float>().apply(7.65f, 2.5f), 3.06f);
  EXPECT_EQ(Div<double>().apply(8.5, 16.0), 0.53125);
}

TEST(TestTMathDiv, TestDivByZeroFails) {
  EXPECT_THROW(Div<int>().apply(3, 0), std::logic_error);
  EXPECT_THROW(Div<float>().apply(3.0f, 0.0f), std::logic_error);
  EXPECT_THROW(Div<double>().apply(3.0, 0.0), std::logic_error);
}
