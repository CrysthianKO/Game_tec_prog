#include "entities/characters/Character.hpp"

Character::Character() : mOnGround(false), mSpeed(0.f), mNumberLives(5) {}
Character::~Character() {}

void Character::setOnGround(bool onG) { mOnGround = onG; }
EntityType Character::getEntityType() const { return EntityType::ET_CHARACTER; }
