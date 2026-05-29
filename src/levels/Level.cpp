#include "levels/Level.hpp"

#include <ostream>
#include <stdexcept>
#include <vector>

#include "SFML/Graphics/Sprite.hpp"

Level::Level() {}

Level::~Level() {}

void Level::includeList(Entity* pE) { mListEntities.include(pE); }

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
  newLayer.sprite.setTextureRect(sf::IntRect(0, 0, 3000.f, sizeScreen.y));
  newLayer.speedFactor = speed;
  mLayers.push_back(newLayer);
}
void Level::addGroundLayer(string id) {
  sf::Texture* texture = getTexture(id);
  if (!texture) {
    throw invalid_argument("Textura vazia para o id " + id);
  }
  sf::Sprite newLayer;
  texture->setRepeated(
      true);  // Sprite "infinito" para nao acabar quando sair da tela
  newLayer.setTexture(*texture);

  sf::Vector2u sizeScreen = pGM->getWindowSize();

  sf::Vector2u sizeImg = texture->getSize();
  newLayer.setTextureRect(sf::IntRect(0, 0, 3000.f, sizeImg.y));
  mGround.push_back(newLayer);
}

void Level::drawGround() {
  std::vector<sf::Sprite>::iterator it = mGround.begin();
  while (it != mGround.end()) {
    pGM->drawEnte(&(*it));  // Estamos tirando o pacote sf::string da
                            // caixa(mostrando ao compilador)
    // e depois passando a referencia de novo, se nao o compilador nao deixa
    // é meio estranho eu sei
    it++;
  }
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
