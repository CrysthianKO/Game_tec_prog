#include "entities/obstacles/Vine.hpp"

float Vine::position(0.f);

Vine::Vine() {
  position += 1060.f;
  sf::Vector2f vecPos = {position, 440.f};
  this->setTexture("VINE");
  // TEXTURA BAIXADA DO SITE  https://szadiart.itch.io/pixel-dark-forest
  mSprite.setPosition(vecPos);
  mSprite.setScale(sf::Vector2f(1.8f, 1.8f));
  mSprite.setTextureRect(sf::IntRect({0, 0}, {32, 64}));
}
Vine::~Vine() { position = 0.f; }

void Vine::execute() {}
void Vine::save() {}
void Vine::obstruct(Player* pPlayer, sf::FloatRect intercession) {
  pPlayer->slow();
}
