#pragma once
#include "entities/Entity.hpp"

class Projectile : public Entity {
 protected:
  bool active;

 public:
  Projectile();
  virtual ~Projectile();
  void setActive(bool a);
  virtual void run() = 0;
  virtual void saveData() = 0;
  virtual void setTarget(Entity* pE) = 0;
  virtual void respawn() = 0;
};
