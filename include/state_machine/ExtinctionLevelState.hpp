#pragma once
#include "levels/ExtinctionLevel.hpp"
#include "state_machine/State.hpp"

namespace DinoGame {
namespace StateMachine {

class Player;

class CollisionManager;
class ExtinctionLevelState : public State {
 private:
  Player* pPlayer1;
  Player* pPlayer2;
  Levels::ExtinctionLevel extinctionLevel;
  GraphicsManager* pGM;
  CollisionManager* pCM;

 public:
  ExtinctionLevelState();
  virtual ~ExtinctionLevelState();
  virtual void setGameContext(Game* game);
  void processEvents(const sf::Event& event);
  void update();
  void winLevel();
  void render();
};

}  // namespace StateMachine
}  // namespace DinoGame
