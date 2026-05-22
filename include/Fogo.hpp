#pragma once
#include "Obstacle.hpp"

class Fogo : public Obstacle {
	Fogo();
	virtual ~Fogo();
	virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	virtual sf::FloatRect getBounds() const;
	virtual ObstacleType getObstacleType() const;
};