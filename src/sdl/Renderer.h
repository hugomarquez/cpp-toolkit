#pragma once
/**
 * @file Renderer.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Wrapper around SDL_Renderer
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <SDL.h>
#include "Window.h"

#include <hm/utils/Color.h>

namespace hm {
  class Renderer {
    public:
      Renderer(Window& w, int i);
      ~Renderer();

      bool createSDLRenderer();
      void destroySDLRenderer();
      bool setDrawColor(Color& c);
      bool clear();
      void present();
      void setFlags(int f);
      
      SDL_Renderer *getSDLRenderer(){ return renderer;}

    private:
      int index;
      uint32_t flags;
      Window& window;
      SDL_Renderer* renderer = nullptr;
  };
}
