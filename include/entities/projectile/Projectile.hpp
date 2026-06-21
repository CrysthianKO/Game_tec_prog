#pragma once
#include "entities/Entity.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Enemy;
}

class Projectile : public Entity {
 protected:
  bool active;
  Characters::Enemy* pOwner;

 public:
  Projectile();
  virtual ~Projectile();
  void setActive(bool a);
  void setOwner(Characters::Enemy* pE);
  void collide();
  virtual void execute() = 0;
  virtual void respawn() = 0;
};
}  // namespace Entities
}  // namespace DinoGame
