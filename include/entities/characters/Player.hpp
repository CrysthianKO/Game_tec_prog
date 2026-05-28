#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "entities/characters/Character.hpp"

class Player : public Character {
 private:
  sf::IntRect mCurrentFrame;
  bool mIsMovingUp = false;
  bool mIsMovingDown = false;
  bool mIsMovingLeft = false;
  bool mIsMovingRight = false;
  const float mPlayerSpeed = 500.f;
  sf::Time mAnimationTimer = sf::Time::Zero;
  sf::Vector2f mVelocity{0.f, 0.f};
  bool mIsGrounded = false;

 public:
  Player();
  virtual ~Player() override;
  void execute();
  void save() override {}
  void move() override {}
  void handleInput(sf::Keyboard::Key key, bool isPressed);
  void updateAnimation(sf::Time dt);

  // virtual sf::FloatRect getBounds() const override;
  virtual CharacterType getCharacterType() const override;
  void update(sf::Time dt);

  sf::Vector2f getPosition();
};
