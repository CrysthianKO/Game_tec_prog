#pragma once
#include <SFML/Graphics.hpp>

#include "entities/characters/Enemy.hpp"
#include "entities/characters/Player.hpp"
// #include "entities/obstacles/Obstacle.hpp"

class Level;

using namespace std;
class CollisionManager {
 private:
  vector<Enemy*> mListEnemies;
  // list<Obstacle> mListObstacle;
  Player* pPlayer1;
  Player* pPlayer2;
  Level* pLevel;

 private:
  const bool checkCollision(Player* pP1, Player* pP2) const;
  // void manageCollisionObstaclesPlayer();
  void manageCollisionEnemyPlayer();
  void manageCollisionGround();
  // void manageCollisionProjectilePlayer();

 public:
  CollisionManager();
  ~CollisionManager();
  void includePlayer(Player* pPlayer);
  void includeEnemy(Enemy* pE);
  void includeLevel(Level* pL);
  // void IncludeObstacle();
  // void includeProjectile();
  void execute();
};
