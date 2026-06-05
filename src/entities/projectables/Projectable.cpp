#include "Projectable.hpp"

#include "SFML/Graphics/Sprite.hpp"
#include "managers/TimeManager.hpp"

Projectable::Projectable()
    : mAcceleration(0, -12.f), mVelocity(200.f, 0.f), mRange(200.f) {
  this->setTexture("BULLET");
  mSprite.setTextureRect(sf::IntRect({0, 0}, {16, 16}));
}

Projectable::~Projectable() {}

void Projectable::spawn(sf::Vector2f iniPos, bool left) {
  mInicialPos = iniPos;
  if (left) {
    mVelocity = -mVelocity;
  }
}

void Projectable::execute() {
  float dt = TimeManager::getInstance().getDeltaTime();

  float secondsPassed = dt;
  sf::Vector2f finalVelocity = mVelocity + (mAcceleration * secondsPassed);
  sf::Vector2f offSet = finalVelocity * secondsPassed;
  mSprite.move(offSet);
}

EntityType Projectable::getEntityType() const {
  return EntityType::ET_PROJECTABLE;
}
