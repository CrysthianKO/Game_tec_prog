#pragma once
#include <SFML/Graphics.hpp>

#include "Ente.hpp"
#include "EntityType.hpp"
#include "SFML/System/Vector2.hpp"

class Entity : public Ente {
 protected:
  sf::Sprite mSprite;

 public:
  Entity();
  virtual ~Entity();
  void setTexture(string id);
  void draw();
  virtual void execute() = 0;
  virtual void save() = 0;
  sf::FloatRect getGlobalBounds();
  sf::Vector2f getPosition();
  void setPosition(sf::Vector2f pos);
  virtual EntityType getEntityType() const = 0;
};
