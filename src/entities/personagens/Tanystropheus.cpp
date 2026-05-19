#include "Tanystropheus.hpp"

Tanystropheus::Tanystropheus() {

}

Tanystropheus::~Tanystropheus() {

}

void Tanystropheus::update(sf::Time deltaTime) {

}

void Tanystropheus::draw(sf::RenderWindow* window) {

}

sf::FloatRect Tanystropheus::getBounds() const {
	//temporiariamente retorna um retângulo vazio, já que o tanystropheus ainda não tem uma sprite ou forma definida
	return sf::FloatRect();
}

EnemyType Tanystropheus::getEnemyType() const {
	return EnemyType::EN_TANYSTROPHEUS;
}