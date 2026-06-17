#pragma once
#include <SFML/Graphics.hpp>

#include "entities/Entity.hpp"
#include "entities/EntityType.hpp"

class Character : public Entity {
 protected:
  int mNumberLives;
  float mSpeed;
  bool mOnGround;
  bool alive;
 public:
  Character();
  virtual ~Character();
  void lifeCheck();
  void setOnGround(bool onG);
  int getNumberLives() const;
  EntityType getEntityType() const;
  virtual CharacterType getCharacterType() const = 0;
};
