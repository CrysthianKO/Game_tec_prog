#pragma once
#include <SFML/Graphics.hpp>

#include "Character.hpp"

class Enemy : public Character {
 public:
  Enemy();
  virtual ~Enemy();
  virtual void update(sf::Time deltaTime) = 0;
  virtual void draw(sf::RenderWindow* window) = 0;
  virtual sf::FloatRect getBounds() const = 0;
  virtual EnemyType getEnemyType() const = 0;
  virtual CharacterType getCharacterType() const;
};
