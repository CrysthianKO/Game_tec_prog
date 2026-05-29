#pragma once
#include <SFML/Graphics.hpp>

#include "entities/Entity.hpp"
#include "entities/EntityType.hpp"

class Character : public Entity {
 protected:
  int number_lives;

 public:
  Character() {}
  virtual ~Character() {}
  EntityType getEntityType() const;
  virtual CharacterType getCharacterType() const = 0;
};
