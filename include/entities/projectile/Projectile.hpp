#pragma once
#include "entities/Entity.hpp"

namespace DinoGame {
namespace Entities {

class Projectile : public Entity {
 protected:
  bool active;

 public:
  Projectile();
  virtual ~Projectile();
  void setActive(bool a);
  virtual void execute() = 0;
  virtual void respawn() = 0;
  virtual EntityType getEntityType() const;
};
}  // namespace Entities
}  // namespace DinoGame
