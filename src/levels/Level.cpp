#include "levels/Level.hpp"

#include <stdexcept>
#include <vector>

Level::Level() {}

Level::~Level() {}

sf::Texture* Level::getTexture(string id) { return pGM->getTexture(id); }

void Level::addBackgroundLayer(string id, float speed) {
  sf::Texture* texture = getTexture(id);
  if (!texture) {
    throw invalid_argument("Textura vazia para o id " + id);
  }
  BackgroundLayer newLayer;
  texture->setRepeated(
      true);  // Sprite "infinito" para nao acabar quando sair da tela
  newLayer.sprite.setTexture(*texture);
  sf::Vector2u sizeScreen = pGM->getWindowSize();
  newLayer.sprite.setTextureRect(sf::IntRect(0, 0, sizeScreen.x, sizeScreen.y));
  newLayer.speedFactor = speed;
  mLayers.push_back(newLayer);
}

void Level::drawBackground() {
  std::vector<BackgroundLayer>::iterator it = mLayers.begin();
  while (it != mLayers.end()) {
    pGM->drawEnte(&it->sprite);
    it++;
  }
}

void Level::createEasyEnemies() {}
void Level::createPlatforms() {}
