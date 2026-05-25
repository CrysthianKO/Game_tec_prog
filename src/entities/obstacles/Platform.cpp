#include "Platform.hpp"

Platform::Platform() {

}

Platform::~Platform() {
}

//void Platform::update(sf::Time deltaTime) {
//
//}

//void Platform::draw(sf::RenderWindow* window) {
//}

//sf::FloatRect Platform::getBounds() const {
//	//temporiariamente retorna um retângulo vazio, já que a plataforma ainda não tem uma sprite ou forma definida
//	return sf::FloatRect();
//}

ObstacleType Platform::getObstacleType() const {
	return ObstacleType::OT_PLATFORM;
}