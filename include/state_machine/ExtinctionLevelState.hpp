#pragma once
#include "levels/ExtinctionLevel.hpp"
#include "state_machine/State.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Player;
}
}  // namespace Entities
namespace Managers {
class GraphicsManager;
class CollisionManager;
}  // namespace Managers
namespace StateMachine {

class ExtinctionLevelState : public State {
 private:
  Entities::Characters::Player* pPlayer1;
  Entities::Characters::Player* pPlayer2;
  Levels::ExtinctionLevel extinctionLevel;
  Managers::GraphicsManager* pGM;
  Managers::CollisionManager* pCM;

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
