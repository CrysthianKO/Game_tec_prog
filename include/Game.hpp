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

#include "entities/characters/Player.hpp"
#include "entities/obstacles/Platform.hpp"
#include "managers/GraphicsManager.hpp"

class Game {
 private:
  GraphicsManager GM;
  Platform mPlat;
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
