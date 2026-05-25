#include "Enemy.hpp"

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

CharacterType Enemy::getCharacterType() const {
	return CharacterType::CH_ENEMY;
}