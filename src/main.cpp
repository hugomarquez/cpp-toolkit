#include "sdl/Application.h"

#include <hm/system/File.h>
#include <hm/system/Logger.h>

int main(int argc, char const *argv[])
{
  // TODO: abstract this to sdl/application
  hm::Logger::setLevel(1);
  hm::File::base_path = "add-path";
  hm::Timer::fps = 60;
  hm::Timer::delay = 1000.0f / hm::Timer::fps;

  int v = 0;
  try {
    hm::Window w("Demo Application", 500, 500, 6);
    hm::Renderer r(w, -1);
    
    hm::Application *app = new hm::Application(w, r);
    v = app->onExecute();

  } catch(const std::exception& e) {
    hm::Logger::error(e.what());
    v = 1;
  }
  return v;
}
