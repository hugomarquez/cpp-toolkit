#include "Timer.h"

namespace hm {
  int Timer::fps;
  int Timer::delay;

  u32 Timer::deltaTime()
  {
    start = SDL_GetTicks();
    u32 dt = start - last;
    last = start;
    return dt;
  }

  void Timer::forceDelay()
  {
    time = SDL_GetTicks() - start;
    if (time < delay) {
      SDL_Delay(delay - time);
    }
  }
}
