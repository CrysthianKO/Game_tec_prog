#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/System/Vector2.hpp"
#include "managers/ResourceManager.hpp"

class Ente;

class GraphicsManager {
 private:
  unsigned int mWidth;   // compri janela
  unsigned int mHeight;  // altura janela
  sf::View mCamera;
  ResourceManager<sf::Texture, std::string>
      mTextureManager;                                  // Managers de textura
  ResourceManager<sf::Font, std::string> mFontManager;  // e fonte
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

  void updateCameraPos(sf::Vector2f pos);

  sf::Texture* getTexture(string id);
  sf::Vector2u getWindowSize();
  void showMousePosition();

  void drawEnte(sf::Sprite* sprite);
  void drawPosition(sf::Vector2f position);
};
