#pragma once
/**
 * @file Rectangle.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Wrapper around SDL_Rect
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <SDL.h>
#include <SDL_image.h>

namespace hm {
  class Rectangle {
    public:
      int x, y, w, h;
      Rectangle(int x, int y, int w, int h);
      SDL_Rect getSDLRect();
  };
}