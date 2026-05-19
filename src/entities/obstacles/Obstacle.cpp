#include "Obstacle.hpp"

Obstacle::Obstacle() {

}

Obstacle::~Obstacle() {

}

EntityType Obstacle::getEntityType() const {
	return EntityType::ET_OBSTACLE;
}