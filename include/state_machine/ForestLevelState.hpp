#pragma once
#include "entities/characters/Player.hpp"
#include "levels/ForestLevel.hpp"
#include "state_machine/State.hpp"

class CollisionManager;
class ForestLevelState : public State {
 private:
  Player* pPlayer1;
  Player* pPlayer2;
  ForestLevel forestLevel;
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
