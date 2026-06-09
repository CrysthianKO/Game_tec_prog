#include "entities/Entity.hpp"

#include "SFML/System/Vector2.hpp"

Entity::Entity() : mDestroyable(true) {} 
Entity::~Entity() { cout << "Apagando Entity ID: " << mId << " da memoria." << endl; }

void Entity::setTexture(string id) {
  sf::Texture* texture = pGM->getTexture(id);
  mSprite.setTexture(*texture);
}
void Entity::draw() { pGM->drawEnte(&this->mSprite); }

sf::FloatRect Entity::getGlobalBounds() { return mSprite.getGlobalBounds(); }

sf::Vector2f Entity::getPosition() { return mSprite.getPosition(); }

void Entity::setPosition(sf::Vector2f pos) { mSprite.setPosition(pos); }
