#pragma once
#include "SFML/Graphics/Texture.hpp"
#include "managers/ResourceManager.hpp"

class TextureManager {
 private:
  // Tipo de dado e chave(key)
  ResourceManager<sf::Texture, std::string>
      mTextures;  // Onde as texturas sao armazenadas

 public:
  TextureManager();
  ~TextureManager();
};
