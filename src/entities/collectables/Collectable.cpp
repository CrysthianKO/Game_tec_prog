#include "Collectable.hpp"

Collectable::Collectable(){

}

Collectable::Collectable(const sf::Texture& texture) : Entidade(texture) {

}

Collectable::~Collectable(){

}

EntityType Collectable::getEntityType() const {
	return EntityType::ET_COLLECTABLE;
}