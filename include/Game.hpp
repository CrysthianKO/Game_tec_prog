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
#include "Bone.hpp"
#include "GraphicsManager.hpp"
#include "Player.hpp"

class Game {
 private:
  GraphicsManager GM;
  sf::Texture mPlayerTexture;
  Player mPlayer;
  const sf::Time timePerFrame;

 public:
  Game();
  ~Game();
  void execute();
  // void addScore(Bone* bone);

 private:
  void processEvents();
  void update(sf::Time dt);
  void render();
};
