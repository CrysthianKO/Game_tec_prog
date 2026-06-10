#pragma once
#include <SFML/Graphics.hpp>

#include "levels/Level.hpp"

class ExtinctionLevel : public Level {
 private:
  int maxBoss;
  int maxHardObstacles;

 public:
  ExtinctionLevel();
  ~ExtinctionLevel();
  void setup();
  void render();

 protected:
  void createEnemies();
  void createObstacles();
  void createScenario();
};
