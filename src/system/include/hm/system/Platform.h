#pragma once

/**
 * @file Platform.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Platform detection layer
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifdef _WIN32
  #ifdef _WIN64
    #define HM_PLATFORM "Windows64"
  #else
    #define HM_PLATFORM "Windows32"
  #endif

#elif __APPLE__
  #define HM_PLATFORM "MacOS"

#elif __linux__
  #define HM_PLATFORM "Linux"
#endif

#include <string>
namespace hm {
  class Platform {
    public:
      static const std::string getPlatform();
      
    private:
      Platform(){}
  };
}
