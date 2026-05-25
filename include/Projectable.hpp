#pragma once
#include "Entity.hpp"

class Projectable : public Entity {
public:
	Projectable();
	virtual ~Projectable();
	//virtual void update(sf::Time deltaTime) = 0;
	//virtual void draw(sf::RenderWindow* window) = 0;
	//virtual sf::FloatRect getBounds() const = 0;
	virtual EntityType getEntityType() const;
	virtual ProjectableType getProjectableType() const = 0;
};