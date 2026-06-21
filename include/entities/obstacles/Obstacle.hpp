#pragma once
#include "entities/Entity.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Player;
}
namespace Obstacles {

class Obstacle : public Entity {
 protected:
  bool harmful;

 public:
  Obstacle();
  ~Obstacle();

  virtual void execute() = 0;
  virtual void save() = 0;
  virtual void obstruct(Characters::Player* pPlayer,
                        sf::FloatRect intercession) = 0;  // OBSTACULIZAR
  //
};

}  // namespace Obstacles
}  // namespace Entities
}  // namespace DinoGame
