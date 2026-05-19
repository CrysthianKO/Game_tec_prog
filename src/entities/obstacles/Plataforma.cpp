#include "Plataforma.hpp"

Plataforma::Plataforma() {

}

Plataforma::~Plataforma() {

}

void Plataforma::update(sf::Time deltaTime) {

}

void Plataforma::draw(sf::RenderWindow* window) {

}

sf::FloatRect Plataforma::getBounds() const {
	//temporiariamente retorna um retângulo vazio, já que a plataforma ainda não tem uma sprite ou forma definida
	return sf::FloatRect();
}

ObstacleType Plataforma::getObstacleType() const {
	return ObstacleType::OT_PLATAFORMA;
}