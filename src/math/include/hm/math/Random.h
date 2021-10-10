#pragma once
/**
 * @file random.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief pseudo-random conversion functions 
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <random>
#include <hm/utils/types.h>

namespace hm {
  class Random {
    public:
      static Random *getInstance();
      int intRange(int l, int h);
      operator float();

      template<typename T>
      operator T()
      {
        static u32 seed = 0x9D09742;
        u32 res;
        u32 tmp;
        
        seed *= 16807;
        tmp = seed ^ (seed >> 4) ^ (seed << 15);
        res = (tmp >> 9) | 0x3F800000;
        return static_cast<T>(res);
      }

    private:
      Random();
      static Random *instance;
  };
}
