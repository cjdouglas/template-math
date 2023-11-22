#pragma once

#include <cassert>
#include <type_traits>
#include <utility>

namespace tmath {
namespace {
template <typename T>
static void assert_non_zero(const T& val) {
  if (!std::is_arithmetic_v<T>) {
    return;
  }

  if (val == 0) {
    throw std::logic_error("cannot divide by zero");
  }
}
}  // namespace

// Forward declarations
template <typename T>
struct TVal;

// Type traits

template <typename T, typename U>
using is_add_compatible_t = decltype(std::declval<T>() + std::declval<U>());

template <typename T, typename U, typename = std::void_t<>>
struct is_add_compatible : std::false_type {};

template <typename T, typename U>
struct is_add_compatible<T, U, std::void_t<is_add_compatible_t<T, U>>>
    : std::true_type {};

template <typename T, typename U>
using is_sub_compatible_t = decltype(std::declval<T>() - std::declval<U>());

template <typename T, typename U, typename = std::void_t<>>
struct is_sub_compatible : std::false_type {};

template <typename T, typename U>
struct is_sub_compatible<T, U, std::void_t<is_sub_compatible_t<T, U>>>
    : std::true_type {};

template <typename T, typename U>
using is_div_compatible_t = decltype(std::declval<T>() / std::declval<U>());

template <typename T, typename U, typename = std::void_t<>>
struct is_div_compatible : std::false_type {};

template <typename T, typename U>
struct is_div_compatible<T, U, std::void_t<is_div_compatible_t<T, U>>>
    : std::true_type {};

template <typename T, typename U>
using is_mul_compatible_t = decltype(std::declval<T>() * std::declval<U>());

template <typename T, typename U, typename = std::void_t<>>
struct is_mul_compatible : std::false_type {};

template <typename T, typename U>
struct is_mul_compatible<T, U, std::void_t<is_mul_compatible_t<T, U>>>
    : std::true_type {};

// Arithmetic operators

template <class Derived>
class Op {
 public:
  template <typename T, typename U = T>
  std::common_type_t<T, U> apply(const T& a, const U& b) {
    return static_cast<Derived*>(this)->apply_(a, b);
  }

 private:
  Op() = default;
  friend Derived;
};

template <typename T, typename U = T>
class Add : public Op<Add<T, U>> {
  std::enable_if_t<is_add_compatible<T, U>::value, std::common_type_t<T, U>>
  apply_(const T& a, const U& b) {
    return a + b;
  }
  friend class Op<Add<T, U>>;
};

template <typename T, typename U = T>
class Sub : public Op<Sub<T, U>> {
  std::enable_if_t<is_sub_compatible<T, U>::value, std::common_type_t<T, U>>
  apply_(const T& a, const U& b) {
    return a - b;
  }
  friend class Op<Sub<T, U>>;
};

template <typename T, typename U = T>
class Div : public Op<Div<T, U>> {
  std::enable_if_t<is_div_compatible<T, U>::value, std::common_type_t<T, U>>
  apply_(const T& a, const U& b) {
    assert_non_zero(b);
    return a / b;
  }
  friend class Op<Div<T, U>>;
};

template <typename T, typename U = T>
class Mul : public Op<Mul<T, U>> {
  std::enable_if_t<is_mul_compatible<T, U>::value, std::common_type_t<T, U>>
  apply_(const T& a, const U& b) {
    return a * b;
  }
  friend class Op<Mul<T, U>>;
};

// Utilities, etc

// A simple template-based value wrapper (currently NOT compatible with Op)
template <typename T>
struct TVal {
  static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type");

  constexpr TVal<T>() : val_{} {}

  TVal<T>(T val) : val_(val) {}

  T operator()() { return val_; }

  template <typename U>
  std::enable_if_t<std::is_arithmetic_v<U>, TVal<std::common_type_t<T, U>>>
  operator+(const U& other) const {
    return TVal<std::common_type_t<T, U>>(val_ + other);
  }

  template <typename U>
  std::enable_if_t<std::is_arithmetic_v<U>, TVal<std::common_type_t<T, U>>>
  operator-(const U& other) const {
    return TVal<std::common_type_t<T, U>>(val_ - other);
  }

  template <typename U>
  std::enable_if_t<std::is_arithmetic_v<U>, TVal<std::common_type_t<T, U>>>
  operator*(const U& other) const {
    return TVal<std::common_type_t<T, U>>(val_ * other);
  }

  template <typename U>
  std::enable_if_t<std::is_arithmetic_v<U>, TVal<std::common_type_t<T, U>>>
  operator/(const U& other) const {
    return TVal<std::common_type_t<T, U>>(val_ / other);
  }

  template <typename U>
  TVal<std::common_type_t<T, U>> operator+(const TVal<U>& other) const {
    return TVal<std::common_type_t<T, U>>(val_ + other.val_);
  }

  template <typename U>
  TVal<std::common_type_t<T, U>> operator-(const TVal<U>& other) const {
    return TVal<std::common_type_t<T, U>>(val_ - other.val_);
  }

  template <typename U>
  TVal<std::common_type_t<T, U>> operator*(const TVal<U>& other) const {
    return TVal<std::common_type_t<T, U>>(val_ * other.val_);
  }

  template <typename U>
  TVal<std::common_type_t<T, U>> operator/(const TVal<U>& other) const {
    return TVal<std::common_type_t<T, U>>(val_ / other.val_);
  }

 private:
  friend struct TVal;
  T val_;
};
}  // namespace tmath
