#pragma once
#include <SFML/Graphics.hpp>
#include "Projectable.hpp"

class LaserBall : public Projectable {
public:
	LaserBall();
	virtual ~LaserBall();
	virtual void update(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	virtual sf::FloatRect getBounds() const;
	virtual ProjectableType getProjectableType() const;
};