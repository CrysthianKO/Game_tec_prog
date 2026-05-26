#pragma once

#include "EntityType.hpp"
#include "Obstacle.hpp"
class Platform : public Obstacle {
 private:
  float height;

 public:
  Platform(const sf::Texture& texture);
  ~Platform();

  void execute();
  void save();
  void obstruct(Player* pPlayer);
  sf::FloatRect getBounds() const;
  ObstacleType getObstacleType() const;
};
