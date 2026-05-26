#pragma once
#include "ListEntities.hpp"

class Level {
 protected:
  ListEntities listEntities;

 public:
  Level();
  ~Level();
  virtual void execute();

 protected:
  void createEasyEnemies();
  void createPlatforms();

  virtual void createEnemies() = 0;
  virtual void createObstacles() = 0;
  void createScenario();
};
