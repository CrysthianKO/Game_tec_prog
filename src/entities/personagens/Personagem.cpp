#include "Personagem.hpp"

Personagem::Personagem() {

}

Personagem::~Personagem() {

}

EntityType Personagem::getEntityType() const {
	return EntityType::ET_PERSONAGEM;
}