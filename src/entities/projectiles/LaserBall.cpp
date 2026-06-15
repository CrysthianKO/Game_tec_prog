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
