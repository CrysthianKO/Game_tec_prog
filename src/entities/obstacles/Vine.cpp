#include "entities/obstacles/Vine.hpp"

Vine::Vine(float xPos) {
  sf::Vector2f vecPos = {xPos, 30.f};
  mSprite.setPosition(vecPos);
  mSprite.setTextureRect(sf::IntRect({0, 0}, {32, 64}));
}
Vine::~Vine() {}

void Vine::execute() {}
void Vine::save() {}
void Vine::obstruct(Player* pPlayer) {}
