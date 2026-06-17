#include "managers/CollisionManager.hpp"

#include <iostream>
#include <stdexcept>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "entities/Entity.hpp"
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
  manageCollisionWall();
}

const bool CollisionManager::checkCollision(Entity* pE1, Entity* pE2) const {
  if (!pE1 || !pE2) cout << "Ponteiros vazio ao tratar colisoes." << endl;
  return pE1->getGlobalBounds().intersects(pE2->getGlobalBounds());
}

sf::FloatRect CollisionManager::getIntersection(Entity* pE1, Entity* pE2) {
  sf::FloatRect intercession;
  pE1->getGlobalBounds().intersects(pE2->getGlobalBounds(), intercession);
  return intercession;
}

void CollisionManager::manageCollisionEnemyPlayer() {
  vector<Player*> vecPlayer;
  if (pPlayer1) vecPlayer.push_back(pPlayer1);
  if (pPlayer2) vecPlayer.push_back(pPlayer2);
  sf::FloatRect intercession;

  for (int i = 0; i < vecPlayer.size(); i++) {
    Player* currentPlayer = vecPlayer[i];

    for (int j = 0; j < mVecEnemies.size(); j++) {
      Enemy* currentEnemy = mVecEnemies[j];
      bool collided = checkCollision(currentPlayer, currentEnemy);
      if (collided) {  // Colidiu
        intercession = getIntersection(static_cast<Entity*>(currentPlayer),
                                       static_cast<Entity*>(currentEnemy));

        bool verticalCollision = intercession.width > intercession.height;
        if (verticalCollision) {  // Colidiu verticalmente
          if (currentPlayer->getVelocity().y > 0.f &&
              currentPlayer->getPosition().y < currentEnemy->getPosition().y) {
            currentEnemy->damage();
            currentPlayer->move(sf::Vector2f(0.f, -intercession.height));
            currentPlayer->bounce();
          }
        } else {  // colidiu pelos lados
          if (currentPlayer->getPosition().x < currentEnemy->getPosition().x) {
            currentPlayer->takeDamage(1, -1);
          } else {
            currentPlayer->takeDamage(1, 1);
          }
        }
      }
    }
  }
}

void CollisionManager::manageCollisionObstaclesPlayer() {
  vector<Player*> vecPlayer;
  if (pPlayer1) vecPlayer.push_back(pPlayer1);
  if (pPlayer2) vecPlayer.push_back(pPlayer2);
  sf::FloatRect intercession;

  for (int i = 0; i < vecPlayer.size(); i++) {
    Player* currentPlayer = vecPlayer[i];

    list<Obstacle*>::iterator it = mListObstacle.begin();
    while (it != mListObstacle.end()) {
      Obstacle* obstacle = *it;
      bool collided = checkCollision(static_cast<Entity*>(pPlayer1),
                                     static_cast<Entity*>(*it));
      if (collided) {
        intercession = getIntersection(pPlayer1, *it);
        obstacle->obstruct(pPlayer1, intercession);
      }
      it++;
    }
  }
}

void CollisionManager::manageCollisionProjectilePlayer() {
  vector<Player*> vecPlayer;
  if (pPlayer1) vecPlayer.push_back(pPlayer1);
  if (pPlayer2) vecPlayer.push_back(pPlayer2);

  for (int i = 0; i < vecPlayer.size(); i++) {
    Player* currentPlayer = vecPlayer[i];

    set<Projectile*>::iterator it = mSetProjectables.begin();

    for (; it != mSetProjectables.end(); it++) {
      Projectile* projecile = *it;
      bool collided =
          checkCollision(static_cast<Entity*>(currentPlayer), projecile);
      if (collided) {
        if (currentPlayer->getPosition().x < projecile->getPosition().x) {
          currentPlayer->takeDamage(1, -1);
        } else {
          currentPlayer->takeDamage(1, 1);
        }
        projecile->setPosition(sf::Vector2f(-999999.f, -99999.f));
      }
    }
  }
}

void CollisionManager::manageCollisionGround() {
  if (!pLevel) throw invalid_argument("Ponteiro da fase NULO!");

  vector<Player*> vecPlayer;
  if (pPlayer1) vecPlayer.push_back(pPlayer1);
  if (pPlayer2) vecPlayer.push_back(pPlayer2);

  float ground = pLevel->getGround();
  float difference;

  for (int i = 0; i < vecPlayer.size(); i++) {
    Player* currentPlayer = vecPlayer[i];
    difference = ground - currentPlayer->getGlobalBounds().height / 2;
    if (currentPlayer->getPosition().y > difference) {
      currentPlayer->setPosition(
          sf::Vector2f(currentPlayer->getPosition().x, difference));
      currentPlayer->setOnGround(true);
    } else
      currentPlayer->setOnGround(false);
  }

  bool onGround;

  for (int i = 0; i < mVecEnemies.size(); i++) {
    Enemy* currentEnemy = mVecEnemies[i];
    difference = ground - currentEnemy->getGlobalBounds().height / 2;
    if (currentEnemy->getPosition().y > difference) {
      currentEnemy->setPosition(
          sf::Vector2f(currentEnemy->getPosition().x, difference));
      onGround = true;
    } else
      onGround = false;
    currentEnemy->setOnGround(onGround);
  }
}

void CollisionManager::manageCollisionWall() {
  vector<Player*> vecPlayer;
  if (pPlayer1) vecPlayer.push_back(pPlayer1);
  if (pPlayer2) vecPlayer.push_back(pPlayer2);
  float difference;

  for (int i = 0; i < vecPlayer.size(); i++) {
    Player* currentPlayer = vecPlayer[i];
    difference = currentPlayer->getGlobalBounds().height / 2;
    if (currentPlayer->getPosition().x < difference) {
      currentPlayer->setPosition(
          sf::Vector2f(difference, currentPlayer->getPosition().y));
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
