#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collectable.hpp"

class Bone : public Collectable{
public:
	Bone();
	virtual ~Bone() override;
	virtual sf::FloatRect getBounds() const override;
	virtual void respawn() override;
	int getScoreValue();
	virtual void update(sf::Time deltaTime) override;
	void updateAnimation(sf::Time deltaTime);
	//virtual void draw(sf::RenderWindow* window);
	virtual CollectableType getCollectableType() const override;

private:
	sf::Texture mTexture;
	//sf::Sprite mSprite; mSprite é herdado de Ente
	int mScoreValue;
	sf::Time mAnimationTimer;
	sf::IntRect mCurrentFrame;
};