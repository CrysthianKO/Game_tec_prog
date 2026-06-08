#include "managers/CollisionManager.hpp"

#include <iostream>
#include <stdexcept>

#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "levels/Level.hpp"

CollisionManager::CollisionManager() : pPlayer1(NULL), pPlayer2(NULL) {};

CollisionManager::~CollisionManager() { mListEnemies.clear(); };

void CollisionManager::execute() {
  manageCollisionGround();
  manageCollisionEnemyPlayer();
  manageCollisionObstaclesPlayer();
}

void CollisionManager::manageCollisionEnemyPlayer() {
  sf::FloatRect hitboxP1 = pPlayer1->getGlobalBounds();
  sf::FloatRect hitBoxEnemy;
  sf::FloatRect intercession;
  for (int i = 0; i < mListEnemies.size(); i++) {
    hitBoxEnemy = mListEnemies[i]->getGlobalBounds();
    bool collision = hitboxP1.intersects(hitBoxEnemy, intercession);
    if (collision) {  // Colidiu
      bool verticalCollision = intercession.width > intercession.height;
      if (verticalCollision) {  // Colidiu verticalmente
        if (pPlayer1->getVelocity().y > 0.f &&
            pPlayer1->getPosition().y < mListEnemies[i]->getPosition().y) {
          mListEnemies[i]->damage();
          pPlayer1->bounce();
        }
      } else {  // colidiu pelos lados
        if (pPlayer1->getPosition().x < mListEnemies[i]->getPosition().x)
          pPlayer1->move(sf::Vector2f(-intercession.width, 0.f));
        else
          pPlayer1->move(sf::Vector2f(intercession.width, 0.f));
        pPlayer1->bounce();
      }
    }
  }
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

  for (int i = 0; i < mListEnemies.size(); i++) {
    difference = ground - mListEnemies[i]->getGlobalBounds().height / 2;
    if (mListEnemies[i]->getPosition().y > difference) {
      mListEnemies[i]->setPosition(
          sf::Vector2f(mListEnemies[i]->getPosition().x, difference));
      onGround = true;
    } else
      onGround = false;
    mListEnemies[i]->setOnGround(onGround);
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
  mListEnemies.push_back(pE);
}

void CollisionManager::IncludeObstacle(Obstacle* pO) {
  if (!pO) throw invalid_argument("Ponteiro obstaculo vazio!");
  mListObstacle.push_back(pO);
}

void CollisionManager::includeLevel(Level* pL) {
  if (!pL) throw invalid_argument("Ponteiro da fase NULO!");
  pLevel = pL;
}
