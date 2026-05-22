#include "Projectable.hpp"

Projectable::Projectable(){

}

Projectable::Projectable(const sf::Texture& texture) : Entidade(texture) {

}

Projectable::~Projectable() {

}

EntityType Projectable::getEntityType() const {
	return EntityType::ET_PROJECTABLE;
}