#include "SDL.h"
#include <hm/utils/types.h>

namespace hm {
  class Timer {
    public:
      static int fps;
      static int delay;

      u32 start; //!< Time in ms when frame starts
      u32 last; //!< Last frame start time in ms
      u32 time; //!< Time it took to run the loop.
      u32 deltaTime();
      void forceDelay();
  };
}
