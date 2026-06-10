#pragma once

#include "entities/EntityType.hpp"
#include "entities/characters/Player.hpp"
#include "entities/obstacles/Obstacle.hpp"
class Platform : public Obstacle {
 private:
  float static position;
  float height;

 public:
  Platform();
  ~Platform();

  void execute();
  void save();
  void obstruct(Player* pPlayer, sf::FloatRect intercession);
  ObstacleType getObstacleType() const;
};
