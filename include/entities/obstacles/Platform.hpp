#pragma once

#include "entities/EntityType.hpp"
#include "entities/characters/Player.hpp"
#include "entities/obstacles/Obstacle.hpp"
class Platform : public Obstacle {
 private:
  float height;

 public:
  Platform();
  ~Platform();

  void execute();
  void save();
  void obstruct(Player* pPlayer);
  sf::FloatRect getBounds() const;
  ObstacleType getObstacleType() const;
};
