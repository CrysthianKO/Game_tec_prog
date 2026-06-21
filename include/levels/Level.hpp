#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "entities/Ente.hpp"
#include "entities/ListEntities.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Player;
}
}  // namespace Entities
namespace Managers {
class CollisionManager;
}

namespace Lists {
class ListEntities;
}

namespace Levels {

struct BackgroundLayer {  // Struct para guardar o background e seus layers
  sf::Sprite sprite;
  float speedFactor;  // velocidade que cada componente irá se mover
};
using namespace std;

class Level : public Ente {
 protected:
  Managers::CollisionManager* pCM;
  vector<BackgroundLayer> mLayers;
  vector<sf::Sprite> mGround;
  float mGroundLevel;
  Lists::ListEntities* pListEntities;

  sf::Font mFont;
  sf::Text txtPlayer1;
  sf::Text txtPlayer2;

 public:
  Level();
  virtual ~Level();

  Level(const Level& other) = delete;
  Level& operator=(const Level& other) = delete;

  virtual void execute() = 0;
  void includePlayer(Entities::Characters::Player* pE);
  void playerHUD();
  void drawBackground();
  void drawGround();
  void drawHUD(Entities::Characters::Player* p1,
               Entities::Characters::Player* p2);
  float getGround();
  float getWall();

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

}  // namespace Levels
}  // namespace DinoGame
