#pragma once
#include <SFML/Graphics.hpp>

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "entities/characters/Enemy.hpp"

class Velociraptor : public Enemy {
 private:
  sf::RectangleShape mTriggerHitBox;
  float mWalkingTime;
  bool mMovingRight;
  float mRange;
  sf::Vector2f mVelocity;
  float mSpawnX;

 public:
  Velociraptor();
  virtual ~Velociraptor();
  void execute();
  void save();
  // virtual void draw(sf::RenderWindow* window);
  void damage();
  // virtual sf::FloatRect getBounds() const;
  virtual EnemyType getEnemyType() const;

 private:
  void setup();
};
