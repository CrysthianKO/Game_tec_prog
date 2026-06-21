#pragma once
#include <SFML/Graphics.hpp>

#include "Ente.hpp"
#include "SFML/System/Vector2.hpp"
#include "managers/Physics.hpp"

namespace DinoGame {
namespace Entities {

class Entity : public Ente {
 protected:
  sf::Sprite mSprite;
  bool mDestroyable;
  Managers::Physics* pPhysics;
  sf::Vector2f mVelocity;

 protected:
  void setTexture(std::string id);

 public:
  Entity();
  virtual ~Entity();
  void setDestroyable(bool d) { mDestroyable = d; }
  bool isDestroyable() const { return mDestroyable; }
  void draw();
  virtual void execute() = 0;
  virtual void save() = 0;
  sf::FloatRect getGlobalBounds();
  sf::Vector2f getPosition();
  void setPosition(sf::Vector2f pos);
  void setVelocity(sf::Vector2f vel);
};
}  // namespace Entities
}  // namespace DinoGame
