#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Player.hpp"

class Game {
 public:
  Game();
  void run();

 private:
  void processEvents();
  void update(sf::Time dt);
  void render();

 private:
  Player mPlayer;
  sf::RenderWindow mWindow;
  const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
};
