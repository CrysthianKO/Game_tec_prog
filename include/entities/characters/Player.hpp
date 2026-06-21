#pragma once
#include "entities/characters/Character.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Enemy;

struct Moviment {
  bool up;
  bool down;
  bool right;
  bool left;
};

struct KeysConfig {
  sf::Keyboard::Key jump;
  sf::Keyboard::Key run;
  sf::Keyboard::Key up;
  sf::Keyboard::Key down;
  sf::Keyboard::Key left;
  sf::Keyboard::Key right;
};

class Player : public Character {
 private:
  int score;
  bool mRunning;
  Moviment mMoviment;
  KeysConfig mConfig;
  sf::IntRect mCurrentFrame;
  float mAnimationTimer;
  float mDamageTimer;

 public:
  Player();
  Player(int playerNum);
  virtual ~Player();
  void execute();
  void save();
  void move(sf::Vector2f move);
  void setup();
  void slow();
  void bounce();
  void configKeys();
  void takeDamage(int damage, float directionX);
  void collide(Enemy* enemy);
  void handleInput(sf::Keyboard::Key key, bool isPressed);
  void updateAnimation(float dt);
  void setScore(int s);

  int getScore() const;
  sf::Vector2f getVelocity();
};

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
