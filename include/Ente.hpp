#pragma once
#include <SFML/Graphics.hpp>

#include "GraphicsManager.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Ente {
 protected:
  int mId;
  static int cont_id;
  static GraphicsManager* pGM;

 public:
  sf::Sprite mSprite;

 public:
  Ente(const sf::Texture& texture) : mId(cont_id++), mSprite(texture) {};
  virtual ~Ente();
  virtual void execute() = 0;
  void draw() { pGM->drawEnte(this->mSprite); }
  void static setGM(GraphicsManager* pG);

  int getId() const { return mId; }
};
