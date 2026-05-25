#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

#include "Entity.hpp"

class Collectable : public Entity {
 public:
  Collectable();
  virtual ~Collectable();
  //virtual void update(sf::Time deltaTime) = 0;
  //virtual void draw(sf::RenderWindow* window) = 0;
  //virtual sf::FloatRect getBounds() const = 0;
  virtual void respawn() = 0;
  virtual EntityType getEntityType() const;
  virtual CollectableType getCollectableType() const = 0;
};
