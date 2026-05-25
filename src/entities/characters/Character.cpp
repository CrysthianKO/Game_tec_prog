#include "Character.hpp"

Character::Character()
{}

EntityType Character::getEntityType() const
{
	return EntityType::ET_CHARACTER;
}
