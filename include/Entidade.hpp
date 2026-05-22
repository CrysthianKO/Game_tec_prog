#pragma once
#include <SFML/Graphics.hpp>
#include "EntityType.hpp"
#include "Ente.hpp"

class Entidade : public Ente {
protected:
public:
	Entidade();
	Entidade(const sf::Texture& texture);
	virtual ~Entidade();
	virtual void update(sf::Time deltaTime) = 0;
	//virtual void draw(sf::RenderWindow* window) = 0;
	virtual sf::FloatRect getBounds() const = 0;
	virtual EntityType getEntityType() const = 0;
};

