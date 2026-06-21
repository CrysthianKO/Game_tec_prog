#include "entities/projectile/Projectile.hpp"

#include "entities/characters/Enemy.hpp"

namespace DinoGame {
namespace Entities {
Projectile::Projectile() : Entity(), active(false), pOwner(NULL) {}

Projectile::~Projectile() {}

void Projectile::setOwner(Characters::Enemy* pE) {
  if (!pE) throw "Ponteiro inimigo para projetil vazio.";
  pOwner = pE;
}
void Projectile::setActive(bool a) { active = a; }

void Projectile::collide() {
  pOwner->incrementNumberLives();
  mSprite.setPosition(sf::Vector2f(-999999.f, -99999.f));
}

}  // namespace Entities
}  // namespace DinoGame
