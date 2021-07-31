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

namespace hm {

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
}