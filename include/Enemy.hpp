#pragma once
#include <SFML/Graphics.hpp>
#include "Personagem.hpp"

class Enemy : public Personagem {
public:
	Enemy();
	virtual ~Enemy();
	virtual void update(sf::Time deltaTime) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual sf::FloatRect getBounds() const = 0;
	virtual EnemyType getEnemyType() const = 0;
	virtual PersonagemType getPersonagemType() const;
};