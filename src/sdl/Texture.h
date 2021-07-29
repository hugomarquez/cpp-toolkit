#pragma once
/**
 * @file Texture.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Wrapper around SDL_Texture
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

// SDL
#include <SDL.h>
#include <SDL_image.h>

#include "iTexture.h"
#include "Renderer.h"
#include "AssetManager.h"
#include "Rectangle.h"

namespace hm {
  class AssetManager; // forward declaration
  class Texture : public ITexture {
    public:
      Texture(std::string id, std::string p, Renderer& r);
      ~Texture();

      bool load() override;
      bool remove() override;
      
      void draw(int x, int y, int w, int h) override;
      void draw(Rectangle &src, Rectangle &dest);

      void drawFrame(int x, int y, int w, int h, int row, int frame) override;
      void drawFrame(Rectangle& src, Rectangle& dest, int row, int frame);

      Renderer& getRenderer() {return renderer;}
      void setSDLTexture(SDL_Texture *sdl);
      std::string getId() {return id;}

    private:
      std::string id;
      std::string path;
      Renderer& renderer;
      AssetManager *aManager = nullptr;
      SDL_Texture *texture = nullptr;
  };
}
