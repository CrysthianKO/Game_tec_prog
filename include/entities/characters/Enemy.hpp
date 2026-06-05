#pragma once
#include <SFML/Graphics.hpp>

#include "Character.hpp"

class Enemy : public Character {
 protected:
  int badLevel;

 public:
  Enemy();
  virtual ~Enemy();
  // virtual void update(sf::Time deltaTime) = 0;
  virtual void damage() = 0;
  virtual EnemyType getEnemyType() const = 0;
  CharacterType getCharacterType() const;
};
