#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <set>
#include <vector>

#include "SFML/Graphics/Rect.hpp"

namespace DinoGame {

namespace Entities {
class Projectile;
class Entity;
namespace Characters {
class Enemy;
class Player;
}  // namespace Characters
namespace Obstacles {
class Obstacle;
}
}  // namespace Entities

namespace Levels {
class Level;
}

namespace Managers {

using namespace std;

class CollisionManager {
 private:
  vector<Entities::Characters::Enemy*> mVecEnemies;
  list<Entities::Obstacles::Obstacle*> mListObstacle;
  set<Entities::Projectile*> mSetProjectables;
  Entities::Characters::Player* pPlayer1;
  Entities::Characters::Player* pPlayer2;
  Levels::Level* pLevel;
  static CollisionManager* instance;

 private:
  const bool checkCollision(Entities::Entity* pE1, Entities::Entity* pE2) const;
  void manageCollisionObstaclesPlayer();
  void manageCollisionEnemyPlayer();
  void manageCollisionGround();
  void manageCollisionProjectilePlayer();
  void manageCollisionWall();
  sf::FloatRect getIntersection(Entities::Entity* pE1, Entities::Entity* pE2);

 private:
  CollisionManager();

 public:
  ~CollisionManager();
  static CollisionManager* getInstance();
  void includePlayer(Entities::Characters::Player* pPlayer);
  void includeEnemy(Entities::Characters::Enemy* pE);
  void IncludeObstacle(Entities::Obstacles::Obstacle* pO);
  void includeLevel(Levels::Level* pL);
  void includeProjectile(Entities::Projectile* pE);
  void clearComponents();
  void execute();
};

}  // namespace Managers
}  // namespace DinoGame
