#pragma once

#include "entities/EntityType.hpp"
#include "entities/characters/Player.hpp"
#include "entities/obstacles/Obstacle.hpp"
class Platform : public Obstacle {
 private:
  static float position;
  float height;
  sf::Vector2f targetPosition;

 public:
  Platform();
  ~Platform();

  void execute();
  void save();
  void obstruct(Player* pPlayer, sf::FloatRect intercession);
  ObstacleType getObstacleType() const;
};
