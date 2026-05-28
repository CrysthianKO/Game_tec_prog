#pragma once
#include <SFML/Graphics.hpp>

#include "SFML/Graphics/Sprite.hpp"
#include "managers/GraphicsManager.hpp"

class Ente {
 protected:
  int mId;
  static int cont_id;
  static GraphicsManager* pGM;
  sf::Sprite mSprite;

 public:
  Ente() : mId(cont_id++) {}
  virtual ~Ente() {}
  virtual void execute() = 0;
  void draw() { pGM->drawEnte(&this->mSprite); }
  void setTexture(string id) { pGM->setTexture(&this->mSprite, id); }
  void static setGM(GraphicsManager* pG) { pGM = pG; }
  int getId() const { return mId; }
};
