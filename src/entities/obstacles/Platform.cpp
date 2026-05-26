#include "Platform.hpp"

<<<<<<< HEAD
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
=======
Platform::Platform(const sf::Texture& texture) : Obstacle(texture), height(0) {
  mSprite.setTextureRect(sf::IntRect({0, 0}, {32, 16}));
  mSprite.setOrigin({16.f, 8.f});
  mSprite.setScale({5.f, 5.f});
  mSprite.setPosition({900, 400});
}
Platform::~Platform() {}

void Platform::execute() {}
void Platform::save() {}

void Platform::obstruct(Player* pPlayer) {}

sf::FloatRect Platform::getBounds() const {
  // temporiariamente retorna um retângulo vazio, já que a plataforma ainda n
  // tem uma sprite ou forma definida
  return sf::FloatRect();
}

// ObstacleType Platform::getObstacleType() const {
//   return ObstacleType::OT_PLATAFORMA;
// }
>>>>>>> 4795ee6bbd3d3fcd1a4b5ea5a06f8eca20a8fb09
