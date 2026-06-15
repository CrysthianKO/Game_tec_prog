#pragma once
#include "entities/characters/Player.hpp"
#include "levels/ForestLevel.hpp"
#include "state_machine/State.hpp"

class CollisionManager;
class ForestLevelState : public State {
 private:
  Player* player1;
  ForestLevel level1;
  GraphicsManager* pGM;
  CollisionManager* pCM;

 public:
  ForestLevelState();
  virtual ~ForestLevelState();
  void processEvents(const sf::Event& event);
  void update();
  void render();
};
