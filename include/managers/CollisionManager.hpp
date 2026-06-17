#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <set>
#include <vector>

#include "SFML/Graphics/Rect.hpp"
#include "entities/Entity.hpp"
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
  const bool checkCollision(Entity* pE1, Entity* pE2) const;
  void manageCollisionObstaclesPlayer();
  void manageCollisionEnemyPlayer();
  void manageCollisionGround();
  void manageCollisionProjectilePlayer();
  void manageCollisionWall();
  sf::FloatRect getIntersection(Entity* pE1, Entity* pE2);

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
