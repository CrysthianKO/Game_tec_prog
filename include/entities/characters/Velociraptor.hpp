#pragma once
#include <SFML/Graphics.hpp>

#include "entities/characters/Enemy.hpp"

class Velociraptor : public Enemy {
 private:
  static float position;

 public:
  Velociraptor();
  virtual ~Velociraptor();
  void execute();
  void save();
  void damage();
  EnemyType getEnemyType() const;
};
