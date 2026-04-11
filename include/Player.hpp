#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Player {
 public:
  Player(const sf::Texture& texture);
  void handleInput(sf::Keyboard::Key key, bool isPressed);
  void update(sf::Time dt);
  void draw(sf::RenderWindow& window) const;
  void updateAnimation(sf::Time dt);

  // sf::FloatRect getBounds() const { return mShape.getGlobalBounds(); };

 private:
  sf::Sprite mSprite;
  sf::IntRect mCurrentFrame;

  bool mIsMovingUp = false;
  bool mIsMovingDown = false;
  bool mIsMovingLeft = false;
  bool mIsMovingRight = false;
  const float mPlayerSpeed = 100.f;
  sf::Time mAnimationTimer = sf::Time::Zero;
};
