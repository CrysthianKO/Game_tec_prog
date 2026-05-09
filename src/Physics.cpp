#include "Physics.hpp"

const float Physics::gravity = 981.0f;

Physics::Physics() 
{
}

Physics::~Physics() 
{
}

void Physics::applyGravity(sf::Vector2f& velocity, sf::Time deltaTime) {
	velocity.y += gravity * deltaTime.asSeconds();
}