#include "entities/characters/DinoBoss.hpp"

#include "entities/projectile/LaserBall.hpp"
#include "managers/TimeManager.hpp"

float DinoBoss::position(0.f);

DinoBoss::DinoBoss() {
  mSpeed = 2.8f;
  mStrength = 3;
  mVelocity.y = 300.f;
  mWalkingTime = 0;
  mMovingRight = true;
  mRange = 160.f;
  this->setTexture("BOSS");
  mSprite.scale(sf::Vector2f(1.8, 1.8));
  position += 865.f;
  mSpawnX = position;
  mSprite.setPosition(position, 500);
  mSprite.setTextureRect(sf::IntRect({0, 0}, {33, 46}));
  mSprite.setOrigin(16.5f, 23.f);
}
DinoBoss::~DinoBoss() {
  if (pLaser) delete pLaser;
}

void DinoBoss::save() {}
void DinoBoss::execute() {
  float dt = pTM->getDeltaTime();
  mTimerShoot -= dt;

  if (mTimerShoot <= 0.0f) {
    pLaser->setPosition(this->getPosition());
    float direcaoX = 1.f;
    if (mSprite.getScale().x < 0.f) {
      direcaoX = -1.f;
    }
    pLaser->setVelocity(sf::Vector2f(direcaoX * 600.f, 0.f));
    pLaser->setActive(true);
    mTimerShoot = 2.5;
  }

  pPhysics->applyGravity(pTM, mVelocity);

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

void DinoBoss::damage() {}

void DinoBoss::setLaserBall(LaserBall* pL) { pLaser = pL; }

EnemyType DinoBoss::getEnemyType() const {
  return EnemyType::EN_MAMENCHISSAURO;
}
