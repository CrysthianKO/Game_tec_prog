#pragma once
#include <SFML/Graphics.hpp>

#include "Ente.hpp"
#include "EntityType.hpp"

class Entity : public Ente {
 protected:
  int x;
  int y;

 public:
  Entity(const sf::Texture& texture);
  virtual ~Entity();
  virtual void update(sf::Time deltaTime) = 0;
  virtual sf::FloatRect getBounds() const = 0;
  virtual EntityType getEntityType() const = 0;
};
