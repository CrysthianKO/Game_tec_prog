#include "entities/obstacles/Vine.hpp"

Vine::Vine(float xPos) {
  sf::Vector2f vecPos = {xPos, 440.f};
  mSprite.setPosition(vecPos);
  mSprite.setScale(sf::Vector2f(1.8f, 1.8f));
  mSprite.setTextureRect(sf::IntRect({0, 0}, {32, 64}));
}
Vine::~Vine() {}

void Vine::execute() {}
void Vine::save() {}
void Vine::obstruct(Player* pPlayer, sf::FloatRect intercession) {
  pPlayer->slow();
}
