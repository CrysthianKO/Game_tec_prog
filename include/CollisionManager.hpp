#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

#include "Obstacle.hpp"
#include "Player.hpp"

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
