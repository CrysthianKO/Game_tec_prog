#pragma once
#include "Obstacle.hpp"

class Mushroom : public Obstacle {
public:
	Mushroom();
	virtual ~Mushroom();
	//virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	//virtual sf::FloatRect getBounds() const;
	virtual ObstacleType getObstacleType() const;
};