#pragma once
#include <SFML/Graphics.hpp>
#include <list>

#include "entities/characters/Player.hpp"
#include "entities/obstacles/Obstacle.hpp"

using namespace std;
class CollisionManager {
 private:
  // vector<Enemy>
  list<Obstacle> listObstacle;
  Player* pPlayer1;
  Player* pPlayer2;

 private:
  const bool checkCollision(Player* pP1, Player* pP2) const;
};
