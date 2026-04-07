#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Player {
 public:
  Player();
  void handleInput(sf::Keyboard::Key key, bool isPressed);
  void update(sf::Time dt);
  void draw(sf::RenderWindow& window) const;

  // sf::FloatRect getBounds() const { return mShape.getGlobalBounds(); };

 private:
  sf::Texture mTexture;
  sf::Sprite mSprite;

  bool mIsMovingUp = false;
  bool mIsMovingDown = false;
  bool mIsMovingLeft = false;
  bool mIsMovingRight = false;
  const float PlayerSpeed = 100.f;
};
