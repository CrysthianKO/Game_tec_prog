#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "entities/Ente.hpp"
#include "entities/ListEntities.hpp"
// #include "managers/CollisionManager.hpp"

class Player;
class CollisionManager;

struct BackgroundLayer {  // Struct para guardar o background e seus layers
  sf::Sprite sprite;
  float speedFactor;  // velocidade que cada componente irá se mover
};

class Level : public Ente {
 protected:
  CollisionManager* pCM;
  vector<BackgroundLayer> mLayers;
  vector<sf::Sprite> mGround;
  float mGroundLevel;
  ListEntities* pListEntities;

 public:
  Level();
  virtual ~Level();

  Level(const Level& other) = delete;
  Level& operator=(const Level& other) = delete;

  virtual void execute() = 0;
  void includePlayer(Player* pE);
  void drawBackground();
  void drawGround();
  float getGround();

 protected:
  void addBackgroundLayer(string id, float speed);
  void addGroundLayer(string id);
  sf::Texture* getTexture(string id);

  void createEasyEnemies();
  void createPlatforms();

  virtual void createEnemies() = 0;
  virtual void createObstacles() = 0;
  virtual void createScenario() = 0;
};
