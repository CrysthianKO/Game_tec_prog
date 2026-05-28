#include "entities/obstacles/Platform.hpp"

Platform::Platform() : height(0) {}
Platform::~Platform() {}

void Platform::execute() {}
void Platform::save() {}

void Platform::obstruct(Player* pPlayer) {}

sf::FloatRect Platform::getBounds() const {
  // temporiariamente retorna um retângulo vazio, já que a plataforma ainda n
  // tem uma sprite ou forma definida
  return sf::FloatRect();
}

ObstacleType Platform::getObstacleType() const {
  return ObstacleType::OT_PLATFORM;
}
