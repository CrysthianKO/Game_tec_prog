#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Character : public Entity {
 protected:
  int number_lives;

 public:
  Character(const sf::Texture& texture) : Entity(texture) {}
  virtual ~Character() {}
  // void saveDataBuffer() {}
  virtual void execute() = 0;
  virtual void save() = 0;
  virtual void move() = 0;
};
