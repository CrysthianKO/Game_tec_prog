#pragma once
#include "state_machine/State.hpp"
// #include "Game.hpp"
#include "entities/characters/Player.hpp"
#include "levels/ExtinctionLevel.hpp"

class CollisionManager;
class ExtinctionLevelState : public State {
 private:
  Player* pPlayer1;
  Player* pPlayer2;
  ExtinctionLevel extinctionLevel;
  GraphicsManager* pGM;
  CollisionManager* pCM;

 public:
  ExtinctionLevelState();
  virtual ~ExtinctionLevelState();
  virtual void setGameContext(Game* game);
  void processEvents(const sf::Event& event);
  void update();
  void render();
};
