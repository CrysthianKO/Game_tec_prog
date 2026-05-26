#pragma once
<<<<<<< HEAD
#include <SFML/Graphics.hpp>

class Level {

};
=======
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
>>>>>>> 4795ee6bbd3d3fcd1a4b5ea5a06f8eca20a8fb09
