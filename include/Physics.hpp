#pragma once
#include <SFML/Graphics.hpp>

class Physics {
public:
	Physics();
	~Physics();
public:
	static const float gravity;
	static void applyGravity(sf::Vector2f& velocity, sf::Time deltaTime);
};