#pragma once
#include "Obstacle.hpp"

class Platform : public Obstacle {
public:
	Platform();
	virtual ~Platform();
	//virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	//virtual sf::FloatRect getBounds() const;
	virtual ObstacleType getObstacleType() const;
};