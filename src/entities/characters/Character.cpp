#include "entities/characters/Character.hpp"

Character::Character() : mOnGround(false) {}
Character::~Character() {}

void Character::setOnGround(bool onG) { mOnGround = onG; }
EntityType Character::getEntityType() const { return EntityType::ET_CHARACTER; }
