#include "Player.hpp"

Player::Player(
  const sf::Texture& texture
): mSprite(texture)
{
  mSprite.setPosition({100.f, 100.f});
  mSprite.setOrigin({ 32.f, 32.f });
  mSprite.setScale({1.f, 1.f});
  mSprite.setTextureRect(sf::IntRect({ 0,0 }, { 64, 64 }));
}

void Player::draw(sf::RenderWindow& window) const { window.draw(mSprite); }

void Player::update(sf::Time dt) {
  sf::Vector2f movement(0.f, 0.f);
  sf::Vector2f accelaration(0.f, 9.f);
  sf::Vector2f velocity(0.f, 0.f);

  if (mIsMovingUp) movement.y -= PlayerSpeed;
  if (mIsMovingDown) movement.y += PlayerSpeed;
  if (mIsMovingLeft) movement.x -= PlayerSpeed;
  if (mIsMovingRight) movement.x += PlayerSpeed;

  mSprite.move(movement * dt.asSeconds());
}

void Player::handleInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::Key::W)
    mIsMovingUp = isPressed;
  else if (key == sf::Keyboard::Key::S)
    mIsMovingDown = isPressed;
  else if (key == sf::Keyboard::Key::A)
    mIsMovingLeft = isPressed;
  else if (key == sf::Keyboard::Key::D)
    mIsMovingRight = isPressed;
}
