#include "Obstacle.hpp"

Obstacle::Obstacle(){

}

Obstacle::Obstacle(const sf::Texture& texture) : Entidade(texture) {

}

Obstacle::~Obstacle() {

}

EntityType Obstacle::getEntityType() const {
	return EntityType::ET_OBSTACLE;
}