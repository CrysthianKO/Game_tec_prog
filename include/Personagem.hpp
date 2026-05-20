#pragma once
#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Personagem : public Entity {
 public:
  Personagem(const sf::Texture& texture) : Entity(texture) {}
  virtual ~Personagem();
  virtual void update(sf::Time deltaTime) = 0;
  virtual void draw(sf::RenderWindow* window) = 0;
  virtual sf::FloatRect getBounds() const = 0;
};
