#include "entities/projectile/LaserBall.hpp"

#include "entities/projectile/Projectile.hpp"

LaserBall::LaserBall()
    : Projectile(),
      lightning(false),
      pOwner(NULL),
      startX(0.f),
      maxDistance(500.f),
      laserSpeed(200.f) {
  this->setTexture("LASERBALL");
  active = false;
}

LaserBall::~LaserBall() {}

void LaserBall::save() {}

void LaserBall::execute() {
  if (!active) {
    return;
  }
  float dt = pTM->getDeltaTime();

  mSprite.move(mVelocity * dt);

  if (abs(mSprite.getPosition().x - startX) >= maxDistance) {
    respawn();
  }
}

void LaserBall::respawn() {
  active = false;
  mSprite.setPosition(-99999.f, -99999.f);
  mVelocity = sf::Vector2f(0.f, 0.f);
}
