#pragma once

#include "entities/obstacles/Obstacle.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Player;
}
namespace Obstacles {

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
  void obstruct(Characters::Player* pPlayer, sf::FloatRect intercession);
};

}  // namespace Obstacles
}  // namespace Entities
}  // namespace DinoGame
