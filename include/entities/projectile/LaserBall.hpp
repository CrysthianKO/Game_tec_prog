#pragma once
#include <SFML/Graphics.hpp>

#include "SFML/System/Vector2.hpp"
#include "entities/projectile/Projectile.hpp"

class LaserBall : public Projectile {
 private:
  bool lightning;
  sf::Vector2f mStart;
  float maxDistance;
  float laserSpeed;
  float mElapsedTime;

 public:
  LaserBall();
  virtual ~LaserBall();
  void execute();
  void save();
  void respawn();
  void setStart(sf::Vector2f pos);
};
