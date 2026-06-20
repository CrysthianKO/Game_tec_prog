#pragma once
#include <SFML/Graphics.hpp>

#include "levels/Level.hpp"

namespace DinoGame {
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
  void createEnemies();
  void createObstacles();
  void createScenario();
};

}  // namespace Levels
}  // namespace DinoGame
