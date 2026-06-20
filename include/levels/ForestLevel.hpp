#pragma once
#include <SFML/Graphics.hpp>

#include "levels/Level.hpp"

namespace DinoGame {
namespace Levels {

class ForestLevel : public Level {
 private:
  const int maxMidEnemies;
  const int maxMidObstacles;

 public:
  ForestLevel();
  ~ForestLevel();
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
