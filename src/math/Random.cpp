#include "include/hm/math/Random.h"

namespace hm {
  Random *Random::instance = nullptr;

  Random::Random()
  {
    for (int i = 0; i < 5; i++) {
      intRange(i, i * 3);
    }
  }
  Random *Random::getInstance()
  {
    if (instance == nullptr) {
      instance = new Random();
      return instance;
    }
    return instance;
  }

  int Random::intRange(int l, int h)
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(l, h);
    return dist(gen);
  }

  Random::operator float()
  {
    static u32 seed = 0x13371337;
    float res;
    u32 tmp;
    seed *= 16807;  
    tmp = seed ^ (seed >> 4) ^ (seed << 15);  
    *((u32 *) &res) = (tmp >> 9) | 0x3F800000;
    return (res - 1.0f);
  }
}