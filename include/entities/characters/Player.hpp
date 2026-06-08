#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "entities/characters/Character.hpp"

struct Moviment {
  bool up;
  bool down;
  bool right;
  bool left;
};

class Player : public Character {
 private:
  bool mRunning;
  Moviment mMoviment;
  sf::IntRect mCurrentFrame;
  float mAnimationTimer;

 public:
  Player();
  virtual ~Player() override;
  void execute();
  void save();
  void move(sf::Vector2f move);
  void slow();
  void bounce();
  void handleInput(sf::Keyboard::Key key, bool isPressed);
  void updateAnimation(float dt);

  // virtual sf::FloatRect getBounds() const override;
  virtual CharacterType getCharacterType() const override;

  sf::Vector2f getVelocity();
};
