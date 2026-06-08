#include "entities/obstacles/Platform.hpp"

#include "SFML/System/Vector2.hpp"

Platform::Platform(float xPos) {
  float yPos = rand() % (500 - 620 + 1) + 500;
  sf::Vector2f vecPos = {xPos, yPos};
  mSprite.setPosition(vecPos);
  mSprite.setScale(sf::Vector2f(1.7f, 1.7f));
  mSprite.setTextureRect(sf::IntRect({0, 0}, {128, 23}));
}
Platform::~Platform() {}

void Platform::execute() {}
void Platform::save() {}

void Platform::obstruct(Player* pPlayer, sf::FloatRect intercession) {
  bool verticalImpact = intercession.width > intercession.height;
  if (verticalImpact) {
    bool hitTop = pPlayer->getPosition().y < this->getPosition().y;
    if (hitTop) {
      pPlayer->move(sf::Vector2f(0.f, -intercession.height + 9.f));
      pPlayer->setOnGround(true);

    } else {  // foi embaixo
      pPlayer->move(sf::Vector2f(0.f, intercession.height));
      pPlayer->setOnGround(false);
    }

  } else {
    bool hitLeft = pPlayer->getPosition().x < this->getPosition().x;
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
