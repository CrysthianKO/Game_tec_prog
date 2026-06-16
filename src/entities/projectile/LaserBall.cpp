#include "entities/projectile/LaserBall.hpp"

#include <cmath>

#include "SFML/System/Vector2.hpp"
#include "entities/projectile/Projectile.hpp"

LaserBall::LaserBall()
    : Projectile(),
      lightning(false),
      mStart(0.f, 0.f),
      maxDistance(750.f),
      laserSpeed(100.f),
      mElapsedTime(0.f) {
  this->setTexture("LASERBALL");
  mSprite.setScale(sf::Vector2f(1.7f, 1.7f));
  mSprite.setTextureRect(sf::IntRect({0, 0}, {31, 31}));
  active = false;
}

LaserBall::~LaserBall() {}

void LaserBall::save() {}

void LaserBall::execute() {
  if (!active) {
    return;
  }
  float dt = pTM->getDeltaTime();
  mElapsedTime += dt;

  float nextX = mSprite.getPosition().x + (mVelocity.x * dt);

  float nextY = mStart.y + 30.f * std::sin(mElapsedTime * 6.f);

  mSprite.setPosition(nextX, nextY);

  // Sua lógica de distância máxima (startX) continua aqui embaixo...
  if (abs(mSprite.getPosition().x - mStart.x) >= maxDistance) {
    respawn();
  }
}
void LaserBall::setStart(sf::Vector2f pos) { mStart = pos; }

void LaserBall::respawn() {
  active = false;
  mSprite.setPosition(-99999.f, -99999.f);
  mVelocity = sf::Vector2f(0.f, 0.f);
}
