#include "levels/Level.hpp"

#include <stdexcept>
#include <string>
#include <vector>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "entities/characters/Player.hpp"
#include "entities/characters/Velociraptor.hpp"
#include "entities/obstacles/Platform.hpp"
#include "managers/CollisionManager.hpp"

Level::Level()
    : pCM(CollisionManager::getInstance()),
      mLayers(),
      mGround(),
      mGroundLevel(0.f),
      pListEntities(NULL),
      mFont(),
      txtPlayer1(),
      txtPlayer2() {
  pListEntities = new ListEntities();
  if (pCM) {
    pCM->includeLevel(this);
  }
  playerHUD();
}

Level::~Level() {
  if (pListEntities) {
    delete pListEntities;
    pListEntities = NULL;
  }
}

void Level::includePlayer(Player* pE) {
  pE->setDestroyable(false);
  pListEntities->include(pE);
  pCM->includePlayer(pE);
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
  newLayer.sprite.setTextureRect(sf::IntRect(0, 0, 6800.f, sizeScreen.y));
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
  newLayer.setTextureRect(sf::IntRect(0, 0, 6800.f, sizeImg.y));
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

void Level::drawHUD(Player* p1, Player* p2) {
  sf::RenderWindow* window = pGM->getWindow();
  if (window) {
    const sf::View& currentView = window->getView();
    sf::Vector2f camCenter = currentView.getCenter();
    sf::Vector2f camSize = currentView.getSize();
    float topLeftX = camCenter.x - (camSize.x / 2.f);
    float topLeftY = camCenter.y - (camSize.y / 2.f);
    float topRightX = topLeftX + camSize.x - 220.f;
    if (p1) {
      std::string p1str = "P1 Lives: " + std::to_string(p1->getNumberLives()) +
                          "\nScore: " + std::to_string(p1->getScore());
      txtPlayer1.setString(p1str);
      txtPlayer1.setPosition(topLeftX + 20.f, topLeftY + 20.f);
      window->draw(txtPlayer1);
    }
    if (p2) {
      std::string p2str = "P2 Lives: " + std::to_string(p2->getNumberLives()) +
                          "\nScore: " + std::to_string(p2->getScore());
      txtPlayer2.setString(p2str);
      txtPlayer2.setPosition(topRightX, topLeftY + 20.f);
      window->draw(txtPlayer2);
    }
  }
}

void Level::playerHUD() {
  if (!mFont.loadFromFile("media/fonte_teste.ttf")) {
    throw std::runtime_error(
        "Erro Critico: Falha ao carregar a fonte em media/fonte_teste.ttf");
  }
  // Configurações do Player 1 (Canto superior esquerdo)
  txtPlayer1.setFont(mFont);
  txtPlayer1.setCharacterSize(24);
  txtPlayer1.setFillColor(sf::Color::White);
  txtPlayer1.setPosition(20.f, 20.f);
  // Configurações do Player 2 (Canto superior direito)
  txtPlayer2.setFont(mFont);
  txtPlayer2.setCharacterSize(24);
  txtPlayer2.setFillColor(sf::Color::White);
  float posX = pGM->getWindowWidth();
  txtPlayer2.setPosition(posX - 300.f, 20.f);
}

void Level::drawBackground() {
  std::vector<BackgroundLayer>::iterator it = mLayers.begin();
  while (it != mLayers.end()) {
    pGM->drawEnte(&it->sprite);
    it++;
  }
}

float Level::getGround() { return mGroundLevel; }

float Level::getWall() { return mGround[0].getGlobalBounds().width; }

void Level::createEasyEnemies() {
  float numEnemies =
      (rand() % (3 - 6 + 1)) + 3;  // (inicial - final + 1) + inicial
  for (int i = 0; i < numEnemies; i++) {
    Velociraptor* newEnemy = new Velociraptor();
    pListEntities->include(newEnemy);
    pCM->includeEnemy(newEnemy);
  }
}
void Level::createPlatforms() {
  float numPlat =
      (rand() % (3 - 6 + 1)) + 3;  // (inicial - final + 1) + inicial
  for (int i = 0; i < numPlat; i++) {
    Platform* platform = new Platform();
    pListEntities->include(platform);
    pCM->IncludeObstacle(platform);
  }
}
