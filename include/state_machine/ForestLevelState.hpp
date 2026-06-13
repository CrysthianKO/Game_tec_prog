#pragma once
#include "state_machine/State.hpp"
//#include "Game.hpp"
#include "entities/characters/Player.hpp"
#include "levels/ForestLevel.hpp"

//class ForestLevel;
class Player;
class CollisionManager;
class ForestLevelState :
    public State
{
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
