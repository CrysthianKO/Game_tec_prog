#include "entities/characters/Pterodactyl.hpp"

#include "SFML/System/Vector2.hpp"
#include "managers/Physics.hpp"
#include "managers/TimeManager.hpp"

Pterodactyl::Pterodactyl() {
  mVelocity = {0.f, 0.f};
  mSpeed = 2.7f;
  mWalkingTime = 0;
  mMovingRight = true;
  mRange = 120.f;
  mSprite.scale(sf::Vector2f(2.3, 2.3));
  float xPos =
      rand() % (520 - 1100 + 1) + 520;  // (inicial - final + 1) + inicial
  float yPos = rand() % (400 - 470 + 1) + 400;
  mSpawnX = xPos;
  mSprite.setPosition(xPos, yPos);
  mSprite.setTextureRect(sf::IntRect({0, 0}, {31, 17}));
}
Pterodactyl::~Pterodactyl() {}

void Pterodactyl::execute() {
  float dt = TimeManager::getInstance().getDeltaTime();

  float leftWall = mSpawnX - mRange;
  float rightWall = mSpawnX + mRange;

  if (mSprite.getPosition().x > rightWall) {
    mMovingRight = false;
    mWalkingTime = 0.f;
  }
  if (mSprite.getPosition().x < leftWall) {
    mMovingRight = true;
    mWalkingTime = 0.f;
  }

  sf::Vector2f moviment = {0.f, 0.f};

  if (mMovingRight)
    mVelocity.x += mSpeed;
  else
    mVelocity.x -= mSpeed;

  Physics::applyGravity(&mVelocity);

  if (getPosition().y > 500.f) {
    mVelocity.y = -400.f;
  }
  if (mVelocity.x > 120.f) {
    mVelocity.x = 120.f;
  } else if (mVelocity.x < -120.f) {
    mVelocity.x = -120.f;
  }
  moviment = mVelocity * dt;
  mSprite.move(moviment);
}
void Pterodactyl::save() {}
void Pterodactyl::damage() {}

EnemyType Pterodactyl::getEnemyType() const {
  return EnemyType::EN_PTERODACTYL;
}
