#pragma once
#include "Obstacle.hpp"

class Fire : public Obstacle {
	Fire();
	virtual ~Fire();
	//virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	//virtual sf::FloatRect getBounds() const;
	virtual ObstacleType getObstacleType() const;
};