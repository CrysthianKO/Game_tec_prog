#include "GraphicsManager.hpp"

#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

GraphicsManager::GraphicsManager()
    : mWindow(sf::VideoMode({mWidth, mHeight}), "JOGO MUITO BOM"),
      mWidth(1366),
      mHeight(768),
      mText(mFont) {
  if (!mFont.openFromFile("media/fonte_teste.ttf")) {
    throw std::invalid_argument("ERROR: COULD NOT LOAD FONT");
  }
  mText.setFont(mFont);
}

GraphicsManager::~GraphicsManager() {}

void GraphicsManager::clear() { mWindow.clear(); }
void GraphicsManager::display() { mWindow.display(); }
void GraphicsManager::close() { mWindow.close(); }
bool GraphicsManager::isOpen() { return mWindow.isOpen(); };

void GraphicsManager::drawEnte(sf::Sprite sprite) { mWindow.draw(sprite); }

void GraphicsManager::drawPosition(sf::Vector2f position) {
  sf::String msg = "Player position:\nx = " + std::to_string(position.x) +
                   ", y = " + std::to_string(position.y);
  mText.setString(msg);
  mWindow.draw(mText);
}
