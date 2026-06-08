#pragma once
#include <SFML/Graphics.hpp>

#include "Character.hpp"

class Enemy : public Character {
 protected:
  int badLevel;
  float mWalkingTime;
  bool mMovingRight;
  float mRange;
  sf::Vector2f mVelocity;
  float mSpawnX;

 public:
  Enemy();
  virtual ~Enemy();
  // virtual void update(sf::Time deltaTime) = 0;
  virtual void damage() = 0;
  virtual EnemyType getEnemyType() const = 0;
  CharacterType getCharacterType() const;
};
