#include "Personagem.hpp"

Personagem::Personagem(){

}

Personagem::Personagem(const sf::Texture& texture) : Entidade(texture) {

}

Personagem::~Personagem() {

}

EntityType Personagem::getEntityType() const {
	return EntityType::ET_PERSONAGEM;
}