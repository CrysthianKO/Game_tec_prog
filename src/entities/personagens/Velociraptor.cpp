#include "Velociraptor.hpp"

Velociraptor::Velociraptor() {

}

Velociraptor::~Velociraptor() {

}

void Velociraptor::update(sf::Time deltaTime) {

}

void Velociraptor::draw(sf::RenderWindow* window) {

}

sf::FloatRect Velociraptor::getBounds() const {
	//temporiariamente retorna um retângulo vazio, já que o cogumelo ainda não tem uma sprite ou forma definida
	return sf::FloatRect();
}

EnemyType Velociraptor::getEnemyType() const {
	return EnemyType::EN_VELOCIRAPTOR;
}