#pragma once
#include "levels/ForestLevel.hpp"
#include "state_machine/State.hpp"

namespace DinoGame {

namespace Managers {
class CollisionManager;
class GraphicsManager;
}  // namespace Managers
namespace Entities {
namespace Characters {
class Player;
}
}  // namespace Entities
namespace Levels {
class ForestLevel;
}

namespace StateMachine {

class ForestLevelState : public State {
 private:
  Entities::Characters::Player* pPlayer1;
  Entities::Characters::Player* pPlayer2;
  Levels::ForestLevel forestLevel;
  Managers::GraphicsManager* pGM;
  Managers::CollisionManager* pCM;

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
