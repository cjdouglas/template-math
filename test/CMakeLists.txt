include(FetchGTest)

enable_testing()

set(
  SOURCES
  test_add.cc
  test_sub.cc
  test_div.cc
  test_mul.cc
  test_tval.cc
)

add_executable(template_math_tests ${SOURCES})
target_link_libraries(template_math_tests PRIVATE template_math GTest::gtest_main)
add_test(NAME template_math_tests COMMAND template_math_tests)
