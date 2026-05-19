#include "Fogo.hpp"

Fogo::Fogo() {

}

Fogo::~Fogo() {

}

void Fogo::update(sf::Time deltaTime) {

}

void Fogo::draw(sf::RenderWindow* window) {

}

sf::FloatRect Fogo::getBounds() const {
	//temporiariamente retorna um retângulo vazio, já que o cogumelo ainda não tem uma sprite ou forma definida
	return sf::FloatRect();
}

ObstacleType Fogo::getObstacleType() const {
	return ObstacleType::OT_FOGO;
}