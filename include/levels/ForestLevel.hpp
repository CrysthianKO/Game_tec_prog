#pragma once
#include <SFML/Graphics.hpp>

#include "levels/Level.hpp"

class ForestLevel : public Level {
 private:
  int maxMidEnemies;

 public:
  ForestLevel();
  ~ForestLevel();
  void setup();
  void execute();

 protected:
  void createMidEnemies();
  void createMidObst();

  void createEnemies();
  void createObstacles();
};
