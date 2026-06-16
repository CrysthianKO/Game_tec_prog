#include "managers/CollisionManager.hpp"

#include <iostream>
#include <stdexcept>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "entities/characters/Player.hpp"
#include "levels/Level.hpp"

CollisionManager* CollisionManager::instance = NULL;

CollisionManager::CollisionManager()
    : pPlayer1(NULL),
      pPlayer2(NULL),
      pLevel(NULL),
      mVecEnemies(),
      mListObstacle(),
      mSetProjectables() {};

CollisionManager::~CollisionManager() { clearComponents(); }
CollisionManager* CollisionManager::getInstance() {
  if (!instance) {
    instance = new CollisionManager();
  }
  return instance;
};

void CollisionManager::clearComponents() {
  mVecEnemies.clear();
  mListObstacle.clear();
  mSetProjectables.clear();
  pPlayer1 = NULL;
  pPlayer2 = NULL;
  pLevel = NULL;
}

void CollisionManager::execute() {
  manageCollisionGround();
  manageCollisionEnemyPlayer();
  manageCollisionObstaclesPlayer();
  manageCollisionProjectilePlayer();
}

void CollisionManager::manageCollisionEnemyPlayer() {
  sf::FloatRect hitboxP1 = pPlayer1->getGlobalBounds();
  sf::FloatRect hitBoxEnemy;
  sf::FloatRect intercession;
  for (int i = 0; i < mVecEnemies.size(); i++) {
    hitBoxEnemy = mVecEnemies[i]->getGlobalBounds();
    bool collision = hitboxP1.intersects(hitBoxEnemy, intercession);
    if (collision) {  // Colidiu
      bool verticalCollision = intercession.width > intercession.height;
      if (verticalCollision) {  // Colidiu verticalmente
        if (pPlayer1->getVelocity().y > 0.f &&
            pPlayer1->getPosition().y < mVecEnemies[i]->getPosition().y) {
          mVecEnemies[i]->damage();
          pPlayer1->move(sf::Vector2f(0.f, -intercession.height));
          pPlayer1->setVelocity(
              sf::Vector2f(pPlayer1->getVelocity().x, -520.f));
        }
      } else {  // colidiu pelos lados
        if (pPlayer1->getPosition().x < mVecEnemies[i]->getPosition().x) {
          pPlayer1->takeDamage(1, -1);
        } else {
          pPlayer1->takeDamage(1, 1);
        }
      }
    }
  }
}

const bool CollisionManager::checkCollision(Player* pP1, Player* pP2) const {
  return false;
}

void CollisionManager::manageCollisionObstaclesPlayer() {
  sf::FloatRect hitboxP1 = pPlayer1->getGlobalBounds();
  list<Obstacle*>::iterator it = mListObstacle.begin();
  sf::FloatRect hitBoxObject;
  sf::FloatRect intercession;

  while (it != mListObstacle.end()) {
    Obstacle* obstacle = *it;
    hitBoxObject = obstacle->getGlobalBounds();
    if (hitboxP1.intersects(hitBoxObject, intercession)) {
      obstacle->obstruct(pPlayer1, intercession);
    }
    it++;
  }
}
void CollisionManager::manageCollisionGround() {
  if (!pLevel) throw invalid_argument("Ponteiro da fase NULO!");

  float ground = pLevel->getGround();
  float difference;

  difference = ground - pPlayer1->getGlobalBounds().height / 2;
  if (pPlayer1->getPosition().y > difference) {
    pPlayer1->setPosition(sf::Vector2f(pPlayer1->getPosition().x, difference));
    pPlayer1->setOnGround(true);
  } else
    pPlayer1->setOnGround(false);

  bool onGround;

  for (int i = 0; i < mVecEnemies.size(); i++) {
    difference = ground - mVecEnemies[i]->getGlobalBounds().height / 2;
    if (mVecEnemies[i]->getPosition().y > difference) {
      mVecEnemies[i]->setPosition(
          sf::Vector2f(mVecEnemies[i]->getPosition().x, difference));
      onGround = true;
    } else
      onGround = false;
    mVecEnemies[i]->setOnGround(onGround);
  }
}

void CollisionManager::manageCollisionProjectilePlayer() {
  sf::FloatRect playerHitbox = pPlayer1->getGlobalBounds();
  sf::FloatRect projectileHitBox;
  sf::FloatRect intercession;
  set<Projectile*>::iterator it = mSetProjectables.begin();

  for (; it != mSetProjectables.end(); it++) {
    Projectile* projecile = *it;
    projectileHitBox = projecile->getGlobalBounds();
    if (playerHitbox.intersects(projectileHitBox, intercession)) {
      if (pPlayer1->getPosition().x < projecile->getPosition().x) {
        pPlayer1->takeDamage(1, -1);
      } else {
        pPlayer1->takeDamage(1, 1);
      }
      projecile->setPosition(sf::Vector2f(-999999.f, -99999.f));
    }
  }
}

void CollisionManager::includePlayer(Player* pPlayer) {
  if (!pPlayer)
    throw invalid_argument(
        "Ponteiro vazio ao incluir player no gerenciador de colisoes");

  if (!pPlayer1) {
    pPlayer1 = pPlayer;
    return;
  }
  if (!pPlayer2) {
    pPlayer2 = pPlayer;
    return;
  }
  cout << "Nao da pra colocar mais player cabo" << endl;
}

void CollisionManager::includeEnemy(Enemy* pE) {
  if (!pE)
    throw invalid_argument(
        "Ponteiro vazio ao incluir inimigo no gerenciador de colisoes");
  mVecEnemies.push_back(pE);
}

void CollisionManager::IncludeObstacle(Obstacle* pO) {
  if (!pO) throw invalid_argument("Ponteiro obstaculo vazio!");
  mListObstacle.push_back(pO);
}

void CollisionManager::includeLevel(Level* pL) {
  if (!pL) throw invalid_argument("Ponteiro da fase NULO!");
  pLevel = pL;
}

void CollisionManager::includeProjectile(Projectile* pE) {
  if (!pE) throw invalid_argument("Ponteiro projetil NULO!");
  mSetProjectables.insert(pE);
}
