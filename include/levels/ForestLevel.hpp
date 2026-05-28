#pragma once
#include <SFML/Graphics.hpp>

#include "levels/Level.hpp"

class ForestLevel : public Level {
 private:
  BackgroundLayer mLayers[10];
  int maxMidEnemies;

 public:
  ForestLevel();
  ~ForestLevel();

 protected:
  void createMidEnemies();
  void createMidObst();

  void createEnemies();
  void createObstacles();
};
