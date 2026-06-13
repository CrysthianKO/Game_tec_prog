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
#include "levels/ForestLevel.hpp"
#include "managers/GraphicsManager.hpp"

class State;
class CollisionManager;
class Game {
 private:
  GraphicsManager* pGM;
  CollisionManager* pCM;
  State* currentState;
  //Player* mPlayer;
  //ForestLevel mForestLevel;

 public:
  Game();
  ~Game();
  void run();
  void changeState(State* newState);

 private:
  void processEvents();
  void update();
  void render();
};
