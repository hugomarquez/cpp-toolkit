#pragma once

/**
 * @file Color.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Utility class for colors.
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include "types.h"
#include <string>
#include <sstream>

namespace hm {
  class Color {
    public:
      u8 r, g, b, a;
      u32 hex;

      Color(u32 h);
      Color(u8 r, u8 g, u8 b);
      Color(u8 r, u8 g, u8 b, u8 a);
      
      std::string rgb2hex(bool h);

      static Color primary;
      static Color secondary;
      static Color success;
      static Color danger;
      static Color warning;
      static Color info;
      static Color ligth;
      static Color dark;
      static Color white;
    
    private:
      Color();
  };
}