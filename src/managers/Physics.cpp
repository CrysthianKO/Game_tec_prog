#include "managers/Physics.hpp"

#include "SFML/System/Vector2.hpp"
#include "managers/TimeManager.hpp"

const float Physics::gravity = 981.0f;

Physics::Physics() {}

Physics::~Physics() {}

void Physics::applyGravity(sf::Vector2f* velocity) {
  float dt = TimeManager::getInstance().getDeltaTime();
  float gravity = 1950.f;

  velocity->y += gravity * dt;
}
