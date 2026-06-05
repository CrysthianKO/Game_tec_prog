#pragma once
#include "entities/Entity.hpp"
#include "entities/EntityType.hpp"
#include "entities/characters/Player.hpp"

class Obstacle : public Entity {
 protected:
  bool harmful;

 public:
  Obstacle();
  ~Obstacle();

  virtual void execute() = 0;
  virtual void save() = 0;
  virtual void obstruct(Player* pPlayer) = 0;  // OBSTACULIZAR
  EntityType getEntityType() const;
};
