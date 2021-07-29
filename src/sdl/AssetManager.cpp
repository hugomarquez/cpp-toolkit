#include "AssetManager.h"
#include <hm/system/Exception.h>

namespace hm {
  AssetManager* AssetManager::instance = 0;

  void AssetManager::addTexture(Texture *t)
  {
    m_textures[t->getId()] = t;
  }

  bool AssetManager::removeTexture(std::string id)
  {
    m_textures.erase(id);
    return m_textures.count(id) == 0 ? true : false;
  }

  Texture *AssetManager::getTexture(std::string id)
  {
    if (m_textures.count(id)) {
      return m_textures[id];
    } else {
      throw Exception("Asset with ID[ " + id + " ] not found!");
    }
  }
}
