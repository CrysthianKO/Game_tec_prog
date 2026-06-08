#include "managers/Physics.hpp"

#include "SFML/System/Vector2.hpp"
#include "managers/TimeManager.hpp"

const float Physics::gravity = 1950.0f;

Physics::Physics() {}

Physics::~Physics() {}

void Physics::applyGravity(sf::Vector2f* velocity) {
  float dt = TimeManager::getInstance().getDeltaTime();

  velocity->y += gravity * dt;
}
