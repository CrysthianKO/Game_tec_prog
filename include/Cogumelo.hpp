#pragma once
#include "Obstacle.hpp"

class Cogumelo : public Obstacle {
public:
	Cogumelo();
	virtual ~Cogumelo();
	virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	virtual sf::FloatRect getBounds() const;
	virtual ObstacleType getObstacleType() const;
};