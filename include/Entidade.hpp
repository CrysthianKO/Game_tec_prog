#pragma once
#include <SFML/Graphics.hpp>
#include "EntityType.hpp"

class Entidade {
protected:
	int mId;
	static int cont_id;
public:
	Entidade();
	virtual ~Entidade();
	virtual void update(sf::Time deltaTime) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual sf::FloatRect getBounds() const = 0;
	virtual int getId() const;
	virtual void setId(int id);
	virtual EntityType getEntityType() const = 0;
};

