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

 private:
  sf::RenderWindow mWindow;  // VAI SER SINGLETON
  static GraphicsManager* instance;
 private:
  GraphicsManager();
 public:
  ~GraphicsManager();
  static GraphicsManager* getInstance();
  
  void clear();
  void display();
  void close();
  bool isOpen();
  bool pollEvent(sf::Event& event);

  void updateCameraPos(sf::Vector2f pos);

  sf::Texture* getTexture(string id);
  sf::Vector2u getWindowSize();
  void showMousePosition();

  void drawEnte(sf::Sprite* sprite);
  void drawPosition(sf::Vector2f position);

  sf::RenderWindow* getWindow();

  const float getWindowWidth() const;
  const float getWindowHeight() const;
};
