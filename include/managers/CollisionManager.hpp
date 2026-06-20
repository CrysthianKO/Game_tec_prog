#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <set>
#include <vector>

#include "SFML/Graphics/Rect.hpp"

using namespace std;

namespace DinoGame {
namespace Managers {

class Entity;
class Enemy;
class Obstacle;
class Projectile;
class Player;
class Level;

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
}  // namespace Managers
}  // namespace DinoGame
