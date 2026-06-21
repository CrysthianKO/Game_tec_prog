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
namespace Entities {
namespace Characters {
class Player;
}
}  // namespace Entities

namespace StateMachine {
class State;
}
namespace Managers {
class CollisionManager;
class TimeManager;
class GraphicsManager;
}  // namespace Managers
//

class Game {
 private:
  Managers::GraphicsManager* pGM;
  Managers::CollisionManager* pCM;
  Managers::TimeManager* pTM;
  StateMachine::State* currentState;
  StateMachine::State* nextState;
  Entities::Characters::Player* pPlayer1;
  Entities::Characters::Player* pPlayer2;
  float mScore;

 public:
  Game();
  ~Game();
  void run();
  void applyChangeState(/*State* newState*/);
  void changeState(StateMachine::State* newState);
  // void setPlayers(Player*& p1, Player*& p2);
  Entities::Characters::Player* getPlayer1();
  Entities::Characters::Player* getPlayer2();

 private:
  void processEvents();
  void update();
  void render();
};

}  // namespace DinoGame
