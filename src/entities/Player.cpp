#include "Player.hpp"

Player::Player() {
  mTexture.loadFromFile("Media/Massospondylus_idle_spritesheet.png");
  mSprite.setTexture(mTexture);
  mSprite.setPosition(100.f, 100.f);
  mSprite.setScale(1.5f, 1.4f);
}

void Player::draw(sf::RenderWindow& window) const { window.draw(mSprite); }

void Player::update(sf::Time dt) {
  sf::Vector2f movement(0.f, 0.f);
  if (mIsMovingUp) movement.y -= PlayerSpeed;
  if (mIsMovingDown) movement.y += PlayerSpeed;
  if (mIsMovingLeft) movement.x -= PlayerSpeed;
  if (mIsMovingRight) movement.x += PlayerSpeed;
  mSprite.move(movement * dt.asSeconds());
}

void Player::handleInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::W)
    mIsMovingUp = isPressed;
  else if (key == sf::Keyboard::S)
    mIsMovingDown = isPressed;
  else if (key == sf::Keyboard::A)
    mIsMovingLeft = isPressed;
  else if (key == sf::Keyboard::D)
    mIsMovingRight = isPressed;
}
