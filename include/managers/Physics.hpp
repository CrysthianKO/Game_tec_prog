#pragma once
#include <SFML/Graphics.hpp>

class Physics {
 protected:
  Physics();
  ~Physics();
  static Physics* instance;

 public:
  static Physics* getInstance();
  static const float gravity;
  static void applyGravity(sf::Vector2f& velocity);
};
