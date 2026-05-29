#include "entities/Entity.hpp"

Entity::Entity() {}
Entity::~Entity() {}

void Entity::setTexture(string id) {
  sf::Texture* texture = pGM->getTexture(id);
  mSprite.setTexture(*texture);
}

void Entity::draw() { pGM->drawEnte(&this->mSprite); }
