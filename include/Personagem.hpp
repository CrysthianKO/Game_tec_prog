#pragma once
#include <SFML/Graphics.hpp>
#include "Entidade.hpp"

class Personagem : public Entidade{
public:	
	Personagem();
	Personagem(const sf::Texture& texture);
	virtual ~Personagem();
	virtual void update(sf::Time deltaTime) = 0;
	//virtual void draw(sf::RenderWindow* window) = 0;
	virtual sf::FloatRect getBounds() const = 0;
	virtual PersonagemType getPersonagemType() const = 0;
	virtual EntityType getEntityType() const;
};