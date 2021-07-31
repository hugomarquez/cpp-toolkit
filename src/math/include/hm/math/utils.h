#pragma once
/**
 * @file utils.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Convenience math functions
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <math.h>
#include <limits>

namespace hm {

  const float infinity = std::numeric_limits<float>::infinity();
  const float negInfinity = -std::numeric_limits<float>::infinity();

  inline bool isEqual(float a, float b)
  {
    const double epsilon = 1e-5;
    return std::abs(a - b) <= epsilon * std::abs(a);
  }

  //! Linearly interpolates between a and b by f.
  inline float lerp(float a, float b, float f)
  {
    return a + f * (b - a);
  }

  inline float plerp(float a, float b, float f)
  {
    return (1 - f) * a + f * b;
  }

  template <typename T>
  inline T degrees(T radians)
  {
    return radians * static_cast<T>(180.0 / M_PI);
  }

  template <typename T>
  inline T radians(T degrees)
  {
    return degrees * static_cast<T>(M_PI / 180.0);
  }

  template <typename T>
  inline T max(const T &a, const T &b)
  {
    return (a < b ? b : a);
  }

  template <typename T>
  inline T min(const T &a, const T &b)
  {
    return (a < b ? a : b);
  }

  template <typename T>
  inline T abs(T value)
  {
    if (std::is_integral<T>::value)
      return std::abs(value);
    if (std::is_floating_point<T>::value)
      return std::fabs(value);
    return std::labs(value);
  }

  template <typename T>
  inline T clamp(const T &value, const T &lower, const T &upper)
  {
    return min(upper, max(lower, value));
  }
}
