#include "entities/characters/DinoBoss.hpp"

#include "SFML/Graphics/Color.hpp"
#include "entities/projectile/LaserBall.hpp"
#include "managers/TimeManager.hpp"

namespace DinoGame {
namespace Entities {
class LaserBall;
namespace Characters {

float DinoBoss::position(0.f);

DinoBoss::DinoBoss() {
  pLaser = NULL;
  mColor = sf::Color::White;
  badLevel = rand() % 6 + 3;
  mNumberLives = 4;
  mSpeed = 2.8f;
  mVelocity.y = 300.f;
  mWalkingTime = 0;
  mMovingRight = true;
  mRange = 160.f;
  this->setTexture("BOSS");
  // TEXTURA BAIXADA NO SITE
  // https://splitwing77.itch.io/anthropomorphic-dinosaur-npcs-rpg-maker-mz
  mSprite.scale(sf::Vector2f(1.8, 1.8));
  position += 1365.f;
  mSpawnX = position;
  mSprite.setPosition(position, 500);
  mSprite.setTextureRect(sf::IntRect({0, 0}, {33, 46}));
  mSprite.setOrigin(16.5f, 23.f);
}
DinoBoss::~DinoBoss() { position = 0.f; }

void DinoBoss::save() {}
void DinoBoss::execute() {
  mSprite.setColor(mColor);
  float dt = pTM->getDeltaTime();
  mTimerShoot -= dt;

  if (mTimerShoot <= 0.0f) {
    pLaser->setPosition(this->getPosition());
    pLaser->setStart(this->getPosition());
    float direcaoX = 1.f;
    if (mSprite.getScale().x < 0.f) {
      direcaoX = -1.f;
    }
    pLaser->setActive(true);
    pLaser->setVelocity(sf::Vector2f(direcaoX * 260.f, 0.f));
    mTimerShoot = 2.5;
  }

  pPhysics->applyGravity(mVelocity);

  mWalkingTime += dt;
  if (mWalkingTime > 0.5f) {
    mMovingRight = rand() % 2;
    mWalkingTime = 0.f;
    if (mOnGround) {
      mVelocity.y = -550;
      mOnGround = false;
    }
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
    moviment.x += mSpeed;
    mSprite.setScale(1.8f, 1.8f);
  } else {
    moviment.x -= mSpeed;
    mSprite.setScale(-1.8f, 1.8f);
  }

  moviment.y = mVelocity.y * dt;

  mSprite.move(moviment);

  if (mOnGround) mVelocity.y = 0.f;
}
void DinoBoss::move() {}

void DinoBoss::damage() {
  sf::Color color;
  if (mNumberLives > 3) mColor = sf::Color::White;
  if ((mNumberLives == 2)) mColor = sf::Color::Yellow;
  if ((mNumberLives == 1)) mColor = sf::Color::Red;
  if (mNumberLives <= 0) {
    mSprite.setPosition(-99999.f, -99999.f);
  }
  mNumberLives--;
}

void DinoBoss::setLaserBall(LaserBall* pL) {
  if (!pL)
    throw std::invalid_argument("Ponteio Laser Ball Para DinoBoss nulo!");
  pLaser = pL;
  pLaser->setOwner(this);
}

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
