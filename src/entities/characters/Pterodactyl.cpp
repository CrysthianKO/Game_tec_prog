#include "entities/characters/Pterodactyl.hpp"

#include "SFML/System/Vector2.hpp"
#include "managers/Physics.hpp"
#include "managers/TimeManager.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {

float Pterodactyl::position(0.f);

Pterodactyl::Pterodactyl() {
  mNumberLives = 2;
  mVelocity = {0.f, 0.f};
  mSpeed = 2.7f;
  mWalkingTime = 0;
  mMovingRight = true;
  mRange = 120.f;
  flyPosition = 460.f;

  this->setTexture("PTERODACYL");
  // TEXTURA BAIXADA DO SITE https://tonguesurgery.itch.io/tiny-dinosaur
  mSprite.scale(sf::Vector2f(2.3, 2.8));
  position += 915.f;
  mSpawnX = position;
  mSprite.setPosition(position, flyPosition);
  mSprite.setTextureRect(sf::IntRect({0, 0}, {31, 17}));
}

Pterodactyl::~Pterodactyl() { position = 0.f; }

void Pterodactyl::execute() {
  float dt = pTM->getDeltaTime();

  mWalkingTime += dt;
  if (mWalkingTime > 0.8f) {
    mMovingRight = rand() % 2;
    mWalkingTime = 0.f;
  }

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

  if (mMovingRight) {
    mVelocity.x += mSpeed;
    mSprite.setScale(2.3f, 2.8f);
  } else {
    mSprite.setScale(-2.3f, 2.8f);
    mVelocity.x -= mSpeed;
  }

  pPhysics->applyGravity(mVelocity);

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
void Pterodactyl::damage() { mSprite.move(sf::Vector2f(10000, 1000)); }

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
