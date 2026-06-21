#pragma once
#include "entities/Entity.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {

class Character : public Entity {
 protected:
  int mNumberLives;
  float mSpeed;
  bool mOnGround;
  bool alive;

 public:
  Character();
  virtual ~Character();
  void lifeCheck();
  void setOnGround(bool onG);
  void incrementNumberLives();
  int getNumberLives() const;
};

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
