#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "entities/Ente.hpp"
#include "entities/ListEntities.hpp"

struct BackgroundLayer {  // Struct para guardar o background e seus layers
  sf::Sprite sprite;
  float speedFactor;  // velocidade que cada componente irá se mover
};

class Level : public Ente {
 protected:
  vector<BackgroundLayer> mLayers;
  ListEntities mListEntities;
  float mGroundLevel;

 public:
  Level();
  ~Level();
  virtual void execute() {}
  void drawBackground();

 protected:
  void addBackgroundLayer(string id, float speed);
  sf::Texture* getTexture(string id);

  void createEasyEnemies();
  void createPlatforms();

  virtual void createEnemies() = 0;
  virtual void createObstacles() = 0;
  void createScenario() {}
};
