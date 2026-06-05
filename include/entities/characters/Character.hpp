#pragma once
#include <SFML/Graphics.hpp>

#include "SFML/System/Vector2.hpp"
#include "entities/Entity.hpp"
#include "entities/EntityType.hpp"

class Character : public Entity {
 protected:
  int mNumberLives;
  float mSpeed;
  sf::Vector2f mVelocity;
  bool mOnGround;

 public:
  Character();
  virtual ~Character();
  void setOnGround(bool onG);
  EntityType getEntityType() const;
  virtual CharacterType getCharacterType() const = 0;

 protected:
  virtual void setup() = 0;
};
