#include "entities/projectile/Projectile.hpp"

namespace DinoGame {
namespace Entities {
Projectile::Projectile() : Entity(), active(false) {}

Projectile::~Projectile() {}

void Projectile::setActive(bool a) { active = a; }

EntityType Projectile::getEntityType() const {
  return EntityType::ET_PROJECTILE;
}

}  // namespace Entities
}  // namespace DinoGame
