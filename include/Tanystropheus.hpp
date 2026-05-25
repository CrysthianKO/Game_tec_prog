#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Tanystropheus : public Enemy {
public:
	Tanystropheus();
	virtual ~Tanystropheus();
	//virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	//virtual sf::FloatRect getBounds() const;
	virtual EnemyType getEnemyType() const;
};