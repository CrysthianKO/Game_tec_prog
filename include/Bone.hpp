#pragma once
#include <SFML/Graphics.hpp>

class Bone
{
public:
	Bone();
	~Bone();
	sf::FloatRect getBounds() const;
	void respawn();
	int getScoreValue();
	void update(sf::Time deltaTime);
	void updateAnimation(sf::Time deltaTime);
	void draw(sf::RenderWindow* window);
private:
	sf::Texture mTexture;
	sf::Sprite mSprite;
	int mScoreValue;
	sf::Time mAnimationTimer;
	sf::IntRect mCurrentFrame;
};