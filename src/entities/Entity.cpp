#include "entities/Entity.hpp"

#include <iostream>

#include "SFML/System/Vector2.hpp"
#include "managers/GraphicsManager.hpp"
#include "managers/Physics.hpp"

using namespace std;

namespace DinoGame {

using namespace Managers;

namespace Entities {

Entity::Entity()
    : mDestroyable(true), pPhysics(Physics::getInstance()), mVelocity(0, 0) {}
Entity::~Entity() {
  cout << "Apagando Entity ID: " << mId << " da memoria." << endl;
}

void Entity::setTexture(string id) {
  sf::Texture* texture = pGM->getTexture(id);
  mSprite.setTexture(*texture);
}
void Entity::draw() { pGM->drawEnte(&this->mSprite); }

sf::FloatRect Entity::getGlobalBounds() { return mSprite.getGlobalBounds(); }

sf::Vector2f Entity::getPosition() { return mSprite.getPosition(); }

void Entity::setPosition(sf::Vector2f pos) { mSprite.setPosition(pos); }
void Entity::setVelocity(sf::Vector2f vel) { mVelocity = vel; }

}  // namespace Entities
}  // namespace DinoGame
