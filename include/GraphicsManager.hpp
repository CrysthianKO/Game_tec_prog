#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFML/Graphics/Sprite.hpp"

class GraphicsManager {
 private:
  unsigned int width;   // compri janela
  unsigned int height;  // altura janela

 public:
  sf::RenderWindow mWindow;

 public:
  GraphicsManager();
  ~GraphicsManager();
  void drawEnte(sf::Sprite sprite);
};
