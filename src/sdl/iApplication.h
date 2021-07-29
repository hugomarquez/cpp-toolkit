#pragma once
/**
 * @file iApplication.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Interface for Application class
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

namespace hm {
  class IApplication {
    public:
      virtual ~IApplication(){}

      virtual int onExecute() = 0;
      virtual bool onInit() = 0;
      virtual void onEvent() = 0;
      virtual void onLoop() = 0;
      virtual void onRender() = 0;
      virtual void onCleanup() = 0;

      virtual bool isRunning() { return running;}
    protected:
      bool running = false;
  };
}
