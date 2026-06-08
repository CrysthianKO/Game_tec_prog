#include "managers/GraphicsManager.hpp"

#include <sstream>
#include <stdexcept>
#include <string>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"

GraphicsManager::GraphicsManager() : mWidth(1280), mHeight(720) {
  mWindow.create(sf::VideoMode(mWidth, mHeight), "JOGO MASSA DINOSSAUR 2000X",
                 sf::Style::Titlebar |
                     sf::Style::Close);  // Criando a janela de modo que nao
                                         // permita esticar/comprimir ela
  mWindow.setFramerateLimit(60);

  mCamera.setSize((float)mWidth, (float)mHeight);  // Define o tamanho da Camera
  mCamera.setCenter((float)mWidth / 2,
                    (float)mHeight / 2);  // define a centralização da camera
  mCamera.zoom(0.8f);
  mWindow.setView(mCamera);

  bool texturesLoaded;
  for (int i = 0; i <= 9; i++) {
    string id = "FOREST_BACKGROUND_" + to_string(i);
    string filename = "./media/forest/Layer_" + to_string(i) + ".png";
    texturesLoaded = mTextureManager.load(id, filename);
    if (!texturesLoaded) break;
  }

  for (int i = 0; i <= 1; i++) {
    string id = "FOREST_GROUND_" + to_string(i);
    string filename = "./media/forest/Ground_" + to_string(i) + ".png";
    texturesLoaded = mTextureManager.load(id, filename);
    if (!texturesLoaded) break;
  }

  // ResourceManagers funcionando para carregar as texturas
  // talvez mudar para ficar melhor carregar texturas?
  mTextureManager.load("RAPTOR", "./media/entities/raptor-idle.png");
  mTextureManager.load("BULLET", "./media/projectiles/PistolAmmoBig.png");
  mTextureManager.load("VINE", "./media/obstacles/vine.png");
  mTextureManager.load("PLATFORM", "./media/obstacles/platform.png");
  mTextureManager.load("PTERODACYL", "./media/entities/Pterodacyl.png");

  bool playerLoaded = mTextureManager.load(
      "PLAYER_TEXTURE", "./media/Massospondylus_idle_spritesheet.png");

  bool testFontLoaded =
      mFontManager.load("FONT_TESTE", "./media/fonte_teste.ttf");

  bool platformTexture =
      mTextureManager.load("PLATFORM_TEXTURE", "./media/platform-test.png");

  if (!texturesLoaded || !platformTexture || !testFontLoaded ||
      !platformTexture) {
    throw invalid_argument("ERRO: Nao foi possivel carregar texturas");
  }
  mFont.loadFromFile("./media/fonte_teste.ttf");
  mText.setFont(mFont);
}

GraphicsManager::~GraphicsManager() {}

void GraphicsManager::clear() { mWindow.clear(); }
void GraphicsManager::display() { mWindow.display(); }
void GraphicsManager::close() { mWindow.close(); }
bool GraphicsManager::isOpen() { return mWindow.isOpen(); };

void GraphicsManager::drawEnte(sf::Sprite* sprite) {
  if (!sprite) {
    throw invalid_argument("ERROR: ENT SEM SPRITE!");
  }
  if (sprite->getTexture() == NULL) {
    throw invalid_argument("ERROR: SPRITE SEM TEXTURA!");
  }
  mWindow.draw(*sprite);
}

void GraphicsManager::updateCameraPos(sf::Vector2f pos) {
  float maxDownView = 480.f;
  float maxUpperView = 300.f;
  float maxLeftView = 514.f;
  if (pos.y > maxDownView) {
    pos.y = maxDownView;
  }
  if (pos.y < maxUpperView) {
    pos.y = maxUpperView;
  }
  if (pos.x < maxLeftView) {
    pos.x = maxLeftView;
  }
  mCamera.setCenter(pos.x, pos.y);
  mWindow.setView(mCamera);
}

sf::Texture* GraphicsManager::getTexture(string id) {
  sf::Texture* texture = mTextureManager.get(
      id);  // Se o resource tiver carregado vai nos retornar a textura
  // Ja ha uma msg de erro caso de errado
  return texture;
}

sf::Vector2u GraphicsManager::getWindowSize() { return mWindow.getSize(); }

void GraphicsManager::drawPosition(sf::Vector2f position) {
  sf::String msg = "Player position:\nx = " + std::to_string(position.x) +
                   ", y = " + std::to_string(position.y);
  mText.setString(msg);
  sf::Vector2f camPos = mCamera.getCenter();
  mText.setPosition(camPos.x - (mWidth / 2), camPos.y - (mHeight / 2));
  mWindow.draw(mText);
}

void GraphicsManager::showMousePosition() {
  sf::Vector2i mousePos = sf::Mouse::getPosition();
  stringstream msg;
  msg << "Mouse position:\n x =" << mousePos.x << ", y = " << mousePos.y;

  mText.setString(msg.str());
  sf::Vector2f camPos = mCamera.getCenter();
  mText.setPosition(camPos.x - (mWidth / 2), camPos.y - (mHeight / 2));
  mWindow.draw(mText);
}
