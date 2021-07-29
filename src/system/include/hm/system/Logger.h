#pragma once

/**
 * @file logger.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Simple wrapper around spdlog
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <string>

namespace hm {
  class Logger {
    public:
      // Singleton Manager
      static Logger *getInstance()
      {
        if (instance == nullptr) {
          instance = new Logger();
          return instance;
        }
        return instance;
      }
      
      static void setLevel(int level);
      static void debug(std::string msg);
      static void info(std::string msg);
      static void warn(std::string msg);
      static void error(std::string msg);
      static void critical(std::string msg);
    
    private:
      Logger(){ setLevel(1);}
      static Logger *instance;
  };
}
