#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <set>
#include <vector>

#include "entities/characters/Enemy.hpp"
// #include "entities/characters/Player.hpp"
#include "entities/obstacles/Obstacle.hpp"
#include "entities/projectile/Projectile.hpp"

class Player;
class Level;

using namespace std;

class CollisionManager {
 private:
  vector<Enemy*> mVecEnemies;
  list<Obstacle*> mListObstacle;
  set<Projectile*> mSetProjectables;
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
  void includeProjectile(Projectile* pE);
  void clearComponents();
  void execute();
};
