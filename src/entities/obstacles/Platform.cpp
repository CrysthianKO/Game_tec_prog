#include "entities/obstacles/Platform.hpp"

#include "SFML/System/Vector2.hpp"

float Platform::position(0.f);

Platform::Platform() {
  height = 580.f;
  this->setTexture("PLATFORM");
  // TEXTURA BAIXADA DO SITE  https://szadiart.itch.io/pixel-dark-forest
  position += 1185.f;
  mSprite.setPosition(position, height);
  targetPosition = sf::Vector2f(position, height);
  mSprite.setScale(sf::Vector2f(1.7f, 1.7f));
  mSprite.setTextureRect(sf::IntRect({0, 0}, {128, 23}));
}
Platform::~Platform() { position = 0.f; }

void Platform::execute() {
  float dt = pTM->getDeltaTime();
  pPhysics->applyGravity(mVelocity);
  pPhysics->applyLevitation(mVelocity);
  pPhysics->applyDampedOscillator(mVelocity, mSprite.getPosition(),
                                  targetPosition);
  mSprite.move(mVelocity * dt);
}
void Platform::save() {}

void Platform::obstruct(Player* pPlayer, sf::FloatRect intercession) {
  bool verticalImpact = intercession.width > intercession.height;
  if (verticalImpact) {
    bool hitTop = pPlayer->getPosition().y < mSprite.getPosition().y;
    if (hitTop) {
      pPlayer->move(sf::Vector2f(0.f, -intercession.height + 9.f));
      pPlayer->setOnGround(true);
      mVelocity.y = 100.f;

    } else {  // foi embaixo
      pPlayer->move(sf::Vector2f(0.f, intercession.height));
      pPlayer->setOnGround(false);
    }

  } else {
    bool hitLeft = pPlayer->getPosition().x < mSprite.getPosition().x;
    if (hitLeft) {
      pPlayer->move(sf::Vector2f(-intercession.width, 0.f));
    } else {
      pPlayer->move(sf::Vector2f(intercession.width, 0.f));
    }
  }
}

ObstacleType Platform::getObstacleType() const {
  return ObstacleType::OT_PLATFORM;
}
