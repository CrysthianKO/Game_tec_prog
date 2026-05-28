#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "entities/ListEntities.hpp"
#include "managers/GraphicsManager.hpp"

struct BackgroundLayer {  // Struct para guardar o background e seus layers
  sf::Sprite sprite;
  sf::IntRect textureRect;
  float speedFactor;  // velocidade que cada componente irá se mover
};

class Level {
 protected:
  ListEntities mListEntities;
  static GraphicsManager* pGM;
  float mGroundLevel;

 public:
  Level() {}
  ~Level() {}
  void static setGM(GraphicsManager* pG) { pGM = pG; }
  void setTexture(sf::Sprite* pSprite, string id) {
    pGM->setTexture(pSprite, id);
  }
  virtual void execute();

 protected:
  void createEasyEnemies();
  void createPlatforms();

  virtual void createEnemies() = 0;
  virtual void createObstacles() = 0;
  void createScenario();
  void setTexture() {}
};
