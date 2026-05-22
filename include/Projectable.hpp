#pragma once
#include "Entidade.hpp"

class Projectable : public Entidade {
public:
	Projectable();
	Projectable(const sf::Texture& texture);
	virtual ~Projectable();
	virtual void update(sf::Time deltaTime) = 0;
	//virtual void draw(sf::RenderWindow* window) = 0;
	virtual sf::FloatRect getBounds() const = 0;
	virtual EntityType getEntityType() const;
	virtual ProjectableType getProjectableType() const = 0;
};