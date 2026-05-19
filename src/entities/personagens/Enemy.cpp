#include "Enemy.hpp"

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

PersonagemType Enemy::getPersonagemType() const {
	return PersonagemType::PT_ENEMY;
}