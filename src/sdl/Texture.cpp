#include "Texture.h"

#include <hm/system/File.h>
#include <hm/system/Logger.h>

namespace hm {
  
  Texture::Texture(std::string id, std::string p, Renderer& r) : id(id), path(p), renderer(r)
  {
    aManager = AssetManager::getInstance();
  }

  Texture::~Texture(){}

  bool Texture::load()
  {
    File f(path);
    SDL_Surface *tmp = IMG_Load(f.getPath().c_str());
    if (tmp == 0) {
      Logger::warn("Couldn't find texture.");
      return false;
    }

    SDL_Texture *sdlTexture = SDL_CreateTextureFromSurface(renderer.getSDLRenderer(), tmp);
    SDL_FreeSurface(tmp);

    if (sdlTexture != 0) {
      texture = sdlTexture;
      aManager->addTexture(this);
      return true;
    }
    return false;
  }

  bool Texture::remove()
  {
    return aManager->removeTexture(id);
  }

  void Texture::draw(int x, int y, int w, int h)
  {
    // SDL_Rect is a C struct, use {} for initialization
    SDL_Rect s{x, y, w, h};
    SDL_Rect d{x, y, w, h};
    SDL_RenderCopyEx(renderer.getSDLRenderer(), texture, &s, &d, 0, 0, SDL_FLIP_NONE);
  }

  void Texture::draw(Rectangle& src, Rectangle& dest)
  {
    SDL_Rect s = src.getSDLRect();
    SDL_Rect d = dest.getSDLRect();
    SDL_RenderCopyEx(renderer.getSDLRenderer(), texture, &s, &d, 0, 0, SDL_FLIP_NONE);
  }

  void Texture::drawFrame(int x, int y, int w, int h, int row, int frame)
  {
    SDL_Rect srcRect {w * frame, h * row, w, h};
    SDL_Rect destRect {x, y, w, h};
    SDL_RenderCopyEx(renderer.getSDLRenderer(), texture, &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
  }

  void Texture::drawFrame(Rectangle &src, Rectangle &dest, int row, int frame)
  {
    SDL_Rect s {src.w * frame, src.h * row, src.w, src.h};
    SDL_Rect d = dest.getSDLRect();
    SDL_RenderCopyEx(renderer.getSDLRenderer(), texture, &s, &d, 0, 0, SDL_FLIP_NONE);
  }
}
