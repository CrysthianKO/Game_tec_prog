#pragma once
#include <SFML/Graphics.hpp>

#include "managers/TimeManager.hpp"

class Physics {
 private:
  Physics();
  static Physics* instance;

 public:
  ~Physics();
  static Physics* getInstance();
  static const float gravity;
  void applyGravity(TimeManager* pTM, sf::Vector2f& velocity);
};
