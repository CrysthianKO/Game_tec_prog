#include "managers/GraphicsManager.hpp"

#include <stdexcept>
#include <string>

#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector2.hpp"
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
  mWindow.setView(mCamera);

  bool texturesLoaded;
  for (int i = 0; i <= 9; i++) {
    string id = "FOREST_LAYER_" + to_string(i);
    string filename = "./media/Forest/Layer_" + to_string(i) + ".png";
    texturesLoaded = mTextureManager.load(id, filename);
    if (!texturesLoaded) break;
  }

  // ResourceManagers funcionando para carregar as texturas
  // talvez mudar para ficar melhor carregar texturas?
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
  mWindow.draw(mText);
}
