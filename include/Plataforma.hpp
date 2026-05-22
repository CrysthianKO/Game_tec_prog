#pragma once
#include "Obstacle.hpp"

class Plataforma : public Obstacle {
public:
	Plataforma();
	virtual ~Plataforma();
	virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	virtual sf::FloatRect getBounds() const;
	virtual ObstacleType getObstacleType() const;
};