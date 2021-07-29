#include "include/hm/system/Logger.h"

#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace hm {
  Logger* Logger::instance = 0;

  void Logger::setLevel(int level)
  {
    switch (level) {
      case 1: spdlog::set_level(spdlog::level::debug); break;
      default: spdlog::set_level(spdlog::level::debug); break;
    }
  }

  void Logger::debug(std::string msg) { spdlog::debug(msg);}
  void Logger::info(std::string msg) { spdlog::info(msg);}
  void Logger::warn(std::string msg) { spdlog::warn(msg);}
  void Logger::error(std::string msg) { spdlog::error(msg);}
  void Logger::critical(std::string msg) { spdlog::critical(msg);}
}