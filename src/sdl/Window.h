#pragma once
/**
 * @file Window.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief SDL Window abstraction
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <SDL.h>
#include <string>
namespace hm {
  class Window {
    public:
      bool closed = true;
      
      Window(std::string t, int w, int h);
      Window(std::string t, int w, int h, int f);
      Window(std::string t, int x, int y, int w, int h);
      ~Window();

      bool createSDLWindow();
      void destroySDLWindow();
      void setFlags(int f);
      void center();

      // Getters
      std::string getTitle(){ return title;}
      int getX(){ return x;}
      int getY(){ return y;}
      int getWidth(){ return width;}
      int getHeight(){ return height;}
      bool isClosed(){ return closed;}

      int getFlags(){ return flags;}
      SDL_Window *getSDLWindow(){ return window;}

      // Setters
      void setTitle(std::string t){ title = t;}
      void setWidth(int w){ width = w;}
      void setHeight(int h){ height = h;}
      void setX(int x){ this->x = x;}
      void setY(int y){ this->y = y;}
    
    private:
      std::string title;
      int width, height, x, y;
      uint32_t flags;
      SDL_Window *window = nullptr;
  };
}
