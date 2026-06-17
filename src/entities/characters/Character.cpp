#include "entities/characters/Character.hpp"

Character::Character() : mOnGround(false), alive(true), mSpeed(0.f), mNumberLives(5) {}
Character::~Character() {}

void Character::lifeCheck()
{
	if (mNumberLives <= 0) {
		alive = false;
	}
}

void Character::setOnGround(bool onG) { mOnGround = onG; }
int Character::getNumberLives() const
{
	return mNumberLives;
}
EntityType Character::getEntityType() const { return EntityType::ET_CHARACTER; }
