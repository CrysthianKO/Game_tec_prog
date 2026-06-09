#pragma once
#include <SFML/Graphics.hpp>

#include "Ente.hpp"
#include "EntityType.hpp"
#include "SFML/System/Vector2.hpp"

class Entity : public Ente {
 protected:
  sf::Sprite mSprite;
  bool mDestroyable;
 public:
  Entity();
  virtual ~Entity();
  void setDestroyable(bool d) { mDestroyable = d; }
  bool isDestroyable() const { return mDestroyable; }
  void setTexture(string id);
  void draw();
  virtual void execute() = 0;
  virtual void save() = 0;
  sf::FloatRect getGlobalBounds();
  sf::Vector2f getPosition();
  void setPosition(sf::Vector2f pos);
  virtual EntityType getEntityType() const = 0;
};
