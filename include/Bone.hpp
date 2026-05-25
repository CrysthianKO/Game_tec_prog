#pragma once
#include <SFML/Graphics.hpp>
#include "Collectable.hpp"

class Bone : public Collectable{
public:
	Bone();
	virtual ~Bone();
	//virtual sf::FloatRect getBounds() const;
	virtual void respawn();
	int getScoreValue();
	//virtual void update(sf::Time deltaTime);
	void updateAnimation(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	virtual CollectableType getCollectableType() const;

private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	int mScoreValue;
	sf::Time mAnimationTimer;
	sf::IntRect mCurrentFrame;
};