#pragma once
#include "Entidade.hpp"

class Obstacle : public Entidade {
public:
	Obstacle();
	virtual ~Obstacle();
	virtual void update(sf::Time deltaTime) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual sf::FloatRect getBounds() const = 0;
	virtual ObstacleType getObstacleType() const = 0;
	virtual EntityType getEntityType() const;
};