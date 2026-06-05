#pragma once
#include <SFML/Graphics.hpp>

#include "entities/characters/Character.hpp"

class Physics {
 protected:
  Physics();
  ~Physics();

 public:
  static const float gravity;
  static void applyGravity(sf::Vector2f* velocity);

  void moveTo(Character&);
};
