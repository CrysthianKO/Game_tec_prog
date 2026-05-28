#pragma once
#include <SFML/Graphics.hpp>

#include "Ente.hpp"
#include "EntityType.hpp"

class Entity : public Ente {
 protected:
  float x;
  float y;

 public:
  Entity() {}
  virtual ~Entity() {}
  virtual void execute() = 0;
  virtual void save() = 0;
  // virtual sf::FloatRect getBounds() const = 0;
  virtual EntityType getEntityType() const = 0;
};
