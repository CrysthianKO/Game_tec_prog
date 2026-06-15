#pragma once
#include <SFML/Graphics.hpp>

#include "entities/projectile/Projectile.hpp"

class LaserBall : public Projectile {
 private:
  bool lightning;
  Entity* pOwner;
  float startX;
  float maxDistance;
  float laserSpeed;

 public:
  LaserBall();
  virtual ~LaserBall();
  void execute() override;
  void saveData() override;
  void setTarget(Entity* pE) override;
  void respawn() override;
};
