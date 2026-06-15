#include "managers/Physics.hpp"

#include "SFML/System/Vector2.hpp"
#include "managers/TimeManager.hpp"

Physics* Physics::instance = NULL;
const float Physics::gravity = 1950.0f;

Physics::Physics() {}
Physics::~Physics() {}

Physics* Physics::getInstance() {
  if (!instance) {
    instance = new Physics();
  }
  return instance;
}

void Physics::applyGravity(TimeManager* pTM, sf::Vector2f& velocity) {
  float dt = pTM->getDeltaTime();

  velocity.y += gravity * dt;
}
