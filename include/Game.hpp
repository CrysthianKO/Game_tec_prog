#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <ctime>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <vector>

#include "Bone.hpp"
#include "GraphicsManager.hpp"
#include "Physics.hpp"
#include "Player.hpp"
#include "SFML/Graphics/Rect.hpp"

class Game {
 private:
  GraphicsManager GG;
  sf::Texture mPlayerTexture;
  Player mPlayer;
  Bone mCurrentBone;
  const sf::Time timePerFrame;
  int mScore;
  sf::Font mFont;
  std::optional<sf::Text>
      mScoreText;  // Opcional, pois só existirá se a fonte carregar
                   //
 public:
  Game();
  ~Game();
  void run();
  void addScore(Bone* bone);

 private:
  void processEvents();
  void update(sf::Time dt);
  void render();
};
