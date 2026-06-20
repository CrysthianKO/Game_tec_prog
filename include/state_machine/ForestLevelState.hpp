#pragma once
#include "levels/ForestLevel.hpp"
#include "state_machine/State.hpp"

namespace DinoGame {
namespace StateMachine {

class CollisionManager;
class Player;

class ForestLevelState : public State {
 private:
  Player* pPlayer1;
  Player* pPlayer2;
  Levels::ForestLevel forestLevel;
  GraphicsManager* pGM;
  CollisionManager* pCM;

 public:
  ForestLevelState();
  virtual ~ForestLevelState();
  virtual void setGameContext(Game* game);
  void processEvents(const sf::Event& event);
  void update();
  void winLevel();
  void render();
};

}  // namespace StateMachine
}  // namespace DinoGame
