#pragma once
/**
 * @file iTexture.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Interface for Textures2D
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <string>
namespace hm {
  class ITexture {
    public:
      virtual ~ITexture() {}
      virtual bool load() = 0;
      virtual bool remove() = 0;
      virtual void draw(int x, int y, int w, int h) = 0;
      virtual void drawFrame(int x, int y, int w, int h, int row, int frame) = 0;
    protected:
      std::string id;
  };
}
