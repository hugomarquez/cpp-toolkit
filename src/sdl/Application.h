#pragma once
/**
 * @file Application.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Starting point for an App
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <SDL.h>

#include "iApplication.h"
#include "Window.h"
#include "Renderer.h"
#include "Texture.h"
#include "Timer.h"

namespace hm {
  class Application : public IApplication {
    public:
      Application(Window& w, Renderer& r);
      ~Application();

      int onExecute() override;
      bool onInit() override;
      void onEvent() override;
      void onLoop() override;
      void onRender() override;
      void onCleanup() override;
    private:
      Window& window;
      Renderer& renderer;
  };
}