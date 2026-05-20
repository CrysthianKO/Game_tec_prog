#include "Entity.hpp"

#include "Ente.hpp"
#include "SFML/Graphics/Texture.hpp"

Entity::Entity(const sf::Texture& texture) : Ente(texture) {}

Entity::~Entity() {}

int Entity::getId() const { return mId; }
