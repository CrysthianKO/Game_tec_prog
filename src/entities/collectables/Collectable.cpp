#include "Collectable.hpp"

Collectable::Collectable() {

}

Collectable::~Collectable(){

}

EntityType Collectable::getEntityType() const {
	return EntityType::ET_COLLECTABLE;
}