#pragma once
#include <SFML/Graphics.hpp>

#include "levels/Level.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Enemy;
}
}  // namespace Entities
namespace Levels {

class ExtinctionLevel : public Level {
 private:
  const int maxBoss;
  const int maxHardObstacles;

 public:
  ExtinctionLevel();
  ~ExtinctionLevel();
  void setup();
  void render();
  void execute();

 protected:
  void createObstacles();
  void createScenario();
  void createEnemies();
  void createProjectiles(vector<Entities::Characters::Enemy*>& rTempBosses);
};

}  // namespace Levels
}  // namespace DinoGame
