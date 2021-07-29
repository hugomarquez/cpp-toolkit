#include "Window.h"
#include <hm/system/Logger.h>

namespace hm {
  Window::Window(std::string t, int w, int h) : title(t), width(w), height(h)
  {
    center();
    setFlags(3);
  }

  Window::Window(std::string t, int w, int h, int f) : title(t), width(w), height(h)
  {
    center();
    setFlags(3);
    setFlags(6);
  }

  Window::Window(std::string t, int x, int y, int w, int h) : title(t), width(w), height(h)
  {
    this->x = x;
    this->y = y;
    setFlags(3);
  }

  Window::~Window()
  {
    destroySDLWindow();
  }

  bool Window::createSDLWindow()
  {
    if (SDL_WasInit(SDL_INIT_VIDEO) != 0) {
      window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
      if (window != 0) {
        closed = false;
        Logger::info("Window created successfully!");
        return true;
      } else {
        Logger::warn("Failed to create SDL_Window!");
        return false;
      }
    } else {
      Logger::error("SDL Video is not initialized!");
      return false;
    }
  }

  void Window::center()
  {
    x = SDL_WINDOWPOS_CENTERED;
    y = SDL_WINDOWPOS_CENTERED;
  }

  void Window::setFlags(int f)
  {
    switch (f) {
    case 1: flags = SDL_WINDOW_FULLSCREEN; break;
    case 2: flags |= SDL_WINDOW_OPENGL; break;
    case 3: flags = SDL_WINDOW_SHOWN; break;
    case 4: flags = SDL_WINDOW_HIDDEN; break;
    case 5: flags |= SDL_WINDOW_BORDERLESS; break;
    case 6: flags |= SDL_WINDOW_RESIZABLE; break;
    case 7: flags |= SDL_WINDOW_MINIMIZED; break;
    case 8: flags |= SDL_WINDOW_MAXIMIZED; break;
    default: flags = SDL_WINDOW_SHOWN; break;
    }
  }

  void Window::destroySDLWindow()
  {
    SDL_DestroyWindow(window);
    closed = true;
  }
}
