#include "Renderer.h"

namespace hm {
  Renderer::Renderer(Window& w, int i) : window(w), index(i)
  {
    setFlags(0);
  }

  Renderer::~Renderer()
  { 
    destroySDLRenderer();
  }

  bool Renderer::createSDLRenderer()
  {
    // Create SDL renderer
    renderer = SDL_CreateRenderer(window.getSDLWindow(), index, flags);
    if (renderer == 0) {
      return false;
    }
    return true;
  }

  bool Renderer::setDrawColor(Color& c)
  {
    return SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
  }

  bool Renderer::clear()
  {
    // clear the renderer to the draw color
    return SDL_RenderClear(renderer);
  }

  void Renderer::present()
  {
    // draw to the screen
    SDL_RenderPresent(renderer);
  }

  void Renderer::setFlags(int f)
  {
    switch (f) {
    case 1: flags = SDL_RENDERER_SOFTWARE; break;
    case 2: flags = SDL_RENDERER_ACCELERATED; break;
    case 3: flags = SDL_RENDERER_PRESENTVSYNC; break;
    case 4: flags = SDL_RENDERER_TARGETTEXTURE; break;
    default: flags = 0; break;
    }
  }

  void Renderer::destroySDLRenderer()
  {
    SDL_DestroyRenderer(renderer);
  }
}
