#include "Rectangle.h"

namespace hm {
  Rectangle::Rectangle(int x, int y, int w, int h) : x(x), y(y), w(w), h(h)
  {}

  SDL_Rect Rectangle::getSDLRect()
  {
    SDL_Rect rect{x, y, w, h};
    return rect;
  }
}
