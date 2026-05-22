#include "Enemy.hpp"

Enemy::Enemy(){

}

Enemy::Enemy(const sf::Texture& texture) : Personagem(texture) {

}

Enemy::~Enemy() {

}

PersonagemType Enemy::getPersonagemType() const {
	return PersonagemType::PT_ENEMY;
}