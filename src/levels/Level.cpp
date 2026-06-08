#include "levels/Level.hpp"

#include <stdexcept>
#include <vector>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "entities/characters/Player.hpp"
#include "entities/characters/Velociraptor.hpp"
#include "entities/obstacles/Platform.hpp"

Level::Level() {}

Level::~Level() {}

void Level::includePlayer(Player* pE) {
  mListEntities.include(pE);
  CM.includePlayer(pE);
}

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
  newLayer.sprite.setTextureRect(sf::IntRect(0, 0, 8000.f, sizeScreen.y));
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
  newLayer.setTextureRect(sf::IntRect(0, 0, 8000.f, sizeImg.y));
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

float Level::getGround() { return mGroundLevel; }

void Level::createEasyEnemies() {
  float numEnemies =
      rand() % (3 - 5 + 1) + 3;  // (inicial - final + 1) + inicial
  for (int i = 0; i < numEnemies; i++) {
    Velociraptor* newEnemy = new Velociraptor();
    newEnemy->setTexture("RAPTOR");
    mListEntities.include(newEnemy);
    CM.includeEnemy(newEnemy);
  }
}
void Level::createPlatforms(float numPlat) {
  for (int i = 0; i < numPlat; i++) {
  }
  int numPossiblePlatforms = numPlat * 10;
  vector<int> possiblePositions;
  for (int i = 1; i <= numPossiblePlatforms; i++) {
    possiblePositions.push_back(i * 90.f);
  }

  for (int i = 0; i < numPlat; i++) {
    int randPos = rand() % (0 - numPossiblePlatforms +
                            1);  // (inicial - final + 1) + inicial
    float xPos = possiblePositions.at(randPos);
    possiblePositions.erase(possiblePositions.begin() + randPos);
    Platform* platform = new Platform(xPos);
    platform->setTexture("PLATFORM");
    mListEntities.include(platform);
    CM.IncludeObstacle(platform);
  }
}
