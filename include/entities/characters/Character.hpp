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
  // void saveDataBuffer() {}
  virtual void execute() = 0;
  virtual void save() = 0;
  virtual void move() = 0;
  EntityType getEntityType() const;
  virtual CharacterType getCharacterType() const = 0;
};
