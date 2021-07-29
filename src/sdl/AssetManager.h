#pragma once
/**
 * @file AssetManager.h
 * @author Hugo Marquez (hugomarquez.dev@gmail.com)
 * @brief Manages assets, fonts and textures
 * @version 0.0.1
 * @date 2020-04-11
 * 
 * @copyright Copyright (c) 2020
 */

#include <map>
#include <string>
#include <SDL_ttf.h>
#include "Texture.h"

namespace hm {
  class Texture; // Forward declaration
  class AssetManager {
    public:
      // Singleton Manager
      static AssetManager *getInstance()
      {
        if (instance == nullptr) {
          instance = new AssetManager();
          return instance;
        }
        return instance;
      }

      // Fonts
      //static void addFont(std::string id, File &f, int size);
      //static TTF_Font* getFont(std::string id);

      // Textures
      void addTexture(Texture *t);
      Texture *getTexture(std::string id);
      bool removeTexture(std::string id);

      // Clear all resources
      static void clear();
    
    private:
      // Singleton Manager
      AssetManager() {}
      static AssetManager *instance;
      
      // Resources/Assets
      std::map<std::string, TTF_Font*> m_fonts;
      std::map<std::string, Texture*> m_textures;
  };
}
