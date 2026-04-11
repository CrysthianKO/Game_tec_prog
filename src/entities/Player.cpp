#include "Player.hpp"

#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Time.hpp"

Player::Player(const sf::Texture& texture) : mSprite(texture) {
  mSprite.setPosition({100.f, 100.f});
  mSprite.setOrigin({32.f, 32.f});
  mSprite.setScale({1.f, 1.f});
  mCurrentFrame = sf::IntRect({0, 0}, {64, 64});
  mSprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
}

void Player::draw(sf::RenderWindow& window) const { window.draw(mSprite); }

void Player::update(sf::Time dt) {
  sf::Vector2f movement(0.f, 0.f);
  sf::Vector2f acceslaration(0.f, 9.f);
  sf::Vector2f velocity(0.f, 0.f);

  if (mIsMovingUp) movement.y -= mPlayerSpeed;
  if (mIsMovingDown) movement.y += mPlayerSpeed;
  if (mIsMovingLeft) movement.x -= mPlayerSpeed;
  if (mIsMovingRight) movement.x += mPlayerSpeed;

  mSprite.move(movement * dt.asSeconds());
  updateAnimation(dt);
}

void Player::updateAnimation(sf::Time dt) {
  mAnimationTimer += dt;

  if (mAnimationTimer >= sf::seconds(0.35)) {
    mCurrentFrame.position.x += 64;
    if (mCurrentFrame.position.x >= (64 * 6)) {
      mCurrentFrame.position.x = 0;
    }

    mSprite.setTextureRect(mCurrentFrame);
    mAnimationTimer -= sf::seconds(0.35);
  }
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
