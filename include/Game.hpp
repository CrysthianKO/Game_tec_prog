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

#include "managers/GraphicsManager.hpp"

namespace DinoGame {

class State;
class CollisionManager;
class TimeManager;
class GraphicsManager;

class Game {
 private:
  GraphicsManager* pGM;
  CollisionManager* pCM;
  TimeManager* pTM;
  State* currentState;
  State* nextState;
  Player* pPlayer1;
  Player* pPlayer2;
  float mScore;

 public:
  Game();
  ~Game();
  void run();
  void applyChangeState(/*State* newState*/);
  void changeState(State* newState);
  // void setPlayers(Player*& p1, Player*& p2);
  Player* getPlayer1();
  Player* getPlayer2();

 private:
  void processEvents();
  void update();
  void render();
};

}  // namespace DinoGame
