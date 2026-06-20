#include "entities/characters/Character.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {

Character::Character()
    : mOnGround(false), alive(true), mSpeed(0.f), mNumberLives(5) {}
Character::~Character() {}

void Character::lifeCheck() {
  if (mNumberLives <= 0) {
    alive = false;
  }
}

void Character::setOnGround(bool onG) { mOnGround = onG; }
int Character::getNumberLives() const { return mNumberLives; }

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
