#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include "entities/Entity.hpp"

class Projectable : public Entity {
 protected:
  bool active;
  float mRange;
  sf::Vector2f mInicialPos;
  sf::Vector2f mVelocity;
  sf::Vector2f mAcceleration;

 public:
  Projectable();
  virtual ~Projectable();
  void spawn(sf::Vector2f iniPos, bool left);
  void execute();
  void save() {}
  EntityType getEntityType() const;
};
