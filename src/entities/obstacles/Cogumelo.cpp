#include "Cogumelo.hpp"

Cogumelo::Cogumelo(){

}

Cogumelo::~Cogumelo() {

}

void Cogumelo::update(sf::Time deltaTime) {

}

//void Cogumelo::draw(sf::RenderWindow* window) {
//
//}

sf::FloatRect Cogumelo::getBounds() const {
	//temporiariamente retorna um retângulo vazio, já que o cogumelo ainda não tem uma sprite ou forma definida
	return sf::FloatRect();
}

ObstacleType Cogumelo::getObstacleType() const {
	return ObstacleType::OT_COGUMELO;
}