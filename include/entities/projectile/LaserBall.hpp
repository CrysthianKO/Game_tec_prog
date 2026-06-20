#pragma once
#include "entities/projectile/Projectile.hpp"

namespace DinoGame {
namespace Entities {

class DinoBoss;

class LaserBall : public Projectile {
 private:
  bool lightning;
  sf::Vector2f mStart;
  float maxDistance;
  float laserSpeed;
  float mElapsedTime;
  DinoBoss* pOwner;

 public:
  LaserBall();
  virtual ~LaserBall();
  void execute();
  void save();
  void respawn();
  void setStart(sf::Vector2f pos);
};

}  // namespace Entities
}  // namespace DinoGame
