#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Mamenchissauro : public Enemy {
public:
	Mamenchissauro();
	virtual ~Mamenchissauro();
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::RenderWindow* window);
	virtual sf::FloatRect getBounds() const;
	virtual EnemyType getEnemyType() const;
};