#include "Projectable.hpp"

Projectable::Projectable() {

}

Projectable::~Projectable() {

}

EntityType Projectable::getEntityType() const {
	return EntityType::ET_PROJECTABLE;
}