#pragma once

/**
 * @file Exception.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Wrapper around std::exceptions for custom exceptions
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <string>
# include <stdexcept>

namespace hm {
  class Exception : public std::logic_error {
    public:
      Exception(std::string const& msg) : std::logic_error(msg) {}
  };
}
