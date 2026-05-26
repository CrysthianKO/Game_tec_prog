#pragma once

#include "Entity.hpp"
#include "Player.hpp"
class Obstacle : public Entity {
 protected:
  bool harmful;

 public:
  Obstacle(const sf::Texture& texture) : Entity(texture) {}
  ~Obstacle() {}

  virtual void execute() = 0;
  virtual void save() = 0;
  virtual void obstruct(Player* pPlayer) = 0;
};
