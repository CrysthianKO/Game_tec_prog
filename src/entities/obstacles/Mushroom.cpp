#include "Mushroom.hpp"

Mushroom::Mushroom(){

}

Mushroom::~Mushroom() {
}

//void Mushroom::update(sf::Time deltaTime) {
//
//}

//void Mushroom::draw(sf::RenderWindow* window) {
//}

//sf::FloatRect Mushroom	::getBounds() const {
//	//temporiariamente retorna um retângulo vazio, já que o cogumelo ainda não tem uma sprite ou forma definida
//	return sf::FloatRect();
//}

ObstacleType Mushroom::getObstacleType() const {
	return ObstacleType::OT_MUSHROOM;
}