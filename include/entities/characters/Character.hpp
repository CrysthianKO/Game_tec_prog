#pragma once
#include <SFML/Graphics.hpp>

#include "entities/Entity.hpp"
#include "entities/EntityType.hpp"

class Character : public Entity {
 protected:
  int mNumberLives;
  float mSpeed;
  bool mOnGround;

 public:
  Character();
  virtual ~Character();
  void setOnGround(bool onG);
  EntityType getEntityType() const;
  virtual CharacterType getCharacterType() const = 0;
};
