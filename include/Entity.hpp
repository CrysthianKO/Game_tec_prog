#pragma once
#include <SFML/Graphics.hpp>

#include "Ente.hpp"

class Entity : public Ente {
 protected:
  float x;
  float y;

 public:
  Entity(const sf::Texture& texture) : Ente(texture) {}
  virtual ~Entity() {}
  virtual void execute() = 0;
  virtual void save() = 0;
  virtual sf::FloatRect getBounds() const = 0;
};
