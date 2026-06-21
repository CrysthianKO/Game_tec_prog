#include "entities/obstacles/Vine.hpp"

#include "entities/characters/Player.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Player;
}
namespace Obstacles {
using namespace Characters;

float Vine::position(0.f);

Vine::Vine() {
  position += 989.f;
  sf::Vector2f vecPos = {position, 440.f};
  this->setTexture("VINE");
  // TEXTURA BAIXADA DO SITE  https://szadiart.itch.io/pixel-dark-forest
  mSprite.setPosition(vecPos);
  mSprite.setScale(sf::Vector2f(1.8f, 1.8f));
  mSprite.setTextureRect(sf::IntRect({0, 0}, {32, 64}));
}
Vine::~Vine() { position = 0.f; }

void Vine::execute() {
  float dt = pTM->getDeltaTime();
  pPhysics->applyGravity(mVelocity);
  pPhysics->applyLevitation(mVelocity);
  mSprite.move(mVelocity * dt);
}
void Vine::save() {}
void Vine::obstruct(Player* pPlayer, sf::FloatRect intercession) {
  pPlayer->slow();
}

}  // namespace Obstacles
}  // namespace Entities
}  // namespace DinoGame
