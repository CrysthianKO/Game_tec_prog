#pragma once

#include "entities/EntityType.hpp"
#include "entities/characters/Player.hpp"
#include "entities/obstacles/Obstacle.hpp"
class Platform : public Obstacle {
 public:
  Platform(float xPos);
  ~Platform();

  void execute();
  void save();
  void obstruct(Player* pPlayer, sf::FloatRect intercession);
  ObstacleType getObstacleType() const;
};
