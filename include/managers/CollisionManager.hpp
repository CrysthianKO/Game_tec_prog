#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <set>
#include "entities/characters/Enemy.hpp"
//#include "entities/characters/Player.hpp"
#include "entities/obstacles/Obstacle.hpp"
#include "Projectable.hpp"

class Player;
class Level;

using namespace std;

class CollisionManager {
 private:
  vector<Enemy*> mListEnemies;
  list<Obstacle*> mListObstacle;
  set<Projectable*> mListProjectables;
  Player* pPlayer1;
  Player* pPlayer2;
  Level* pLevel;
  static CollisionManager* instance;

 private:
  const bool checkCollision(Player* pP1, Player* pP2) const;
  void manageCollisionObstaclesPlayer();
  void manageCollisionEnemyPlayer();
  void manageCollisionGround();
  // void manageCollisionProjectilePlayer();

 private:
  CollisionManager();
 public:
  ~CollisionManager();
  static CollisionManager* getInstance();
  void includePlayer(Player* pPlayer);
  void includeEnemy(Enemy* pE);
  void IncludeObstacle(Obstacle* pO);
  void includeLevel(Level* pL);
  // void includeProjectile();
  void clearComponents();
  void execute();
};
