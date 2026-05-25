#pragma once
#include <SFML/Graphics.hpp>
//#include "EntityType.hpp"
#include "Entity.hpp"

class Character : public Entity {
 protected:
  int number_lives;

 public:
  Character();
  Character(const sf::Texture& texture) : Entity(texture) {}
  virtual ~Character() {}
  // void saveDataBuffer() {}
  //virtual void execute() = 0;
  //virtual void save() = 0;
  //virtual void move() = 0;
  virtual CharacterType getCharacterType() const = 0;
  virtual EntityType getEntityType() const override;
};
