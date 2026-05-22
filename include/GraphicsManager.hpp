#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"

class Ente;

class GraphicsManager {
 private:
  unsigned int mWidth;   // compri janela
  unsigned int mHeight;  // altura janela
  sf::Font mFont;
  sf::Text mText;

 public:
  sf::RenderWindow mWindow;  // VAI SER SINGLETON

 public:
  GraphicsManager();
  ~GraphicsManager();
  void clear();
  void display();
  void close();
  bool isOpen();
  void drawEnte(sf::Sprite sprite);
  void drawPosition(sf::Vector2f position);
};
