#include "Application.h"

#include <hm/utils/Color.h>
#include <hm/system/File.h>
#include <hm/system/Logger.h>

namespace hm {
  Application::Application(Window& w, Renderer& r) : window(w), renderer(r){}
  Application::~Application(){ /** nothing to do here */ }

  bool Application::onInit()
  {
    // Start SDL 
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      return false;
    }

    // Create our window
    if (!window.createSDLWindow()) {
      return false;
    }

    // Create our renderer
    if (!renderer.createSDLRenderer()) {
      return false;
    }

    renderer.setDrawColor(Color::secondary);
    
    Logger::debug("SDL initialized");
    running = true;
    
    // File
    std::string f = "assets/spritelib/platform/char10.png";
    // Textures
    Texture *dino = new Texture("dino", f, renderer);
    
    if (dino->load() == false) {
      return false;
    }

    return true;
  }

  int Application::onExecute()
  {
    if(onInit() == false) {
      Logger::debug("Stop running!");
      return -1;
    }

    Timer timer;

    while(running) {
      onEvent();
      onLoop();
      onRender();
      
      // Force FPS delay
      timer.forceDelay();
    }

    onCleanup();
    return 0;
  }

  void Application::onLoop(){}

  void Application::onRender()
  {
    // clear the renderer to the draw color
    renderer.clear();

    Texture * t = AssetManager::getInstance()->getTexture("dino");
    
    Rectangle src(0, 72, 130, 72);
    Rectangle dest(0, 0, 130, 72);

    t->draw(src, dest);
    t->drawFrame(src, dest, 1, int(((SDL_GetTicks() / 100) % 4)));
    // draw to the screen
    renderer.present();
  }

  void Application::onCleanup()
  {
    window.destroySDLWindow();
    renderer.destroySDLRenderer();
    SDL_Quit();
  }

  void Application::onEvent()
  {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          Logger::debug("bye... ");
          running = false;
          break;
        default:
          break;
      }
    }
  }
}
