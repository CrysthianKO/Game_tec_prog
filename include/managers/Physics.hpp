#pragma once
#include <SFML/Graphics.hpp>

#include "managers/TimeManager.hpp"

class Physics {
 protected:
  Physics();
  ~Physics();
  static Physics* instance;

 public:
  static Physics* getInstance();
  static const float gravity;
  void applyGravity(TimeManager* pTM, sf::Vector2f& velocity);
};
