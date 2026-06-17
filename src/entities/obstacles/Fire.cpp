#include "entities/obstacles/Fire.hpp"
float Fire::position(0.f);

Fire::Fire() {
  this->setTexture("FIRE");
  // TEXTURE BAIXADA DO SITE https://devkidd.itch.io/pixel-fire-asset-pack
  position += 1285.f;
  mSprite.setPosition(position, 688.f);
  mSprite.setScale(sf::Vector2f(1.7f, 1.7f));
  mSprite.setTextureRect(sf::IntRect({0, 0}, {32, 32}));
  mSprite.setOrigin(16, 16);
}

Fire::~Fire() { position = 0.f; }

void Fire::execute() { pPhysics->applyGravity(mVelocity); }
void Fire::save() {}

void Fire::obstruct(Player* pPlayer, sf::FloatRect intercession) {
  if (pPlayer->getPosition().x < mSprite.getPosition().x) {
    pPlayer->takeDamage(1, -1);
  } else {
    pPlayer->takeDamage(1, 1);
  }
}

ObstacleType Fire::getObstacleType() const { return ObstacleType::OT_FIRE; }
