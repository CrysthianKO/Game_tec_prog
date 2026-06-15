#include "entities/projectile/Projectile.hpp"

Projectile::Projectile() : Entity(), active(false) {}

Projectile::~Projectile() {}

void Projectile::setActive(bool a) { active = a; }

EntityType Projectile::getEntityType() const {
  return EntityType::ET_PROJECTILE;
}
