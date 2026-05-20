#include "GraphicsManager.hpp"

GraphicsManager::GraphicsManager()
    : mWindow(sf::VideoMode({width, height}), "JOGO MUITO BOM"),
      width(1366),
      height(768) {}

GraphicsManager::~GraphicsManager() {}

void GraphicsManager::drawEnte(sf::Sprite sprite) {
  mWindow.clear();
  mWindow.draw(sprite);
}
