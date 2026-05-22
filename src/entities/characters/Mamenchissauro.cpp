#include "Mamenchissauro.hpp"


Mamenchissauro::Mamenchissauro() {

}

Mamenchissauro::~Mamenchissauro() {

}

void Mamenchissauro::update(sf::Time deltaTime) {

}

void Mamenchissauro::draw(sf::RenderWindow* window) {

}

sf::FloatRect Mamenchissauro::getBounds() const {
	//temporiariamente retorna um retângulo vazio, já que o mamenchissauro ainda não tem uma sprite ou forma definida
	return sf::FloatRect();
}

EnemyType Mamenchissauro::getEnemyType() const {
	return EnemyType::EN_MAMENCHISSAURO;
}