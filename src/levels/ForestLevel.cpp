#include "levels/ForestLevel.hpp"

#include <cstdlib>

#include "SFML/System/Vector2.hpp"
#include "entities/characters/Pterodactyl.hpp"
#include "entities/obstacles/Vine.hpp"
#include "managers/CollisionManager.hpp"

ForestLevel::ForestLevel() : maxMidEnemies(7), maxMidObstacles(7) {}

ForestLevel::~ForestLevel() {}

void ForestLevel::setup() {
 // pCM->includeLevel(this);
  createEasyEnemies();
  createEnemies();
  createScenario();
  createObstacles();
  createPlatforms();
}

void ForestLevel::render() {
  drawBackground();
  pListEntities->drawEntities();
  drawGround();
}

void ForestLevel::execute() {
  pCM->execute();
  pListEntities->execute();
}
void ForestLevel::createEnemies() {
  int max = rand() % (maxMidEnemies - 3 + 1) + 3;
  for (int i = 0; i < max; i++) {
    Pterodactyl* newPtero = new Pterodactyl();
    pListEntities->include(newPtero);
    pCM->includeEnemy(newPtero);
  }
}

void ForestLevel::createObstacles() {
  int max = rand() % (maxMidObstacles - 3 + 1) + 3;
  for (int i = 0; i < max; i++) {
    Vine* vine = new Vine();
    pListEntities->include(vine);
    pCM->IncludeObstacle(vine);
  }
}

void ForestLevel::createScenario() {
  for (int i = 0; i <= 9; i++) {
    string id = "FOREST_BACKGROUND_" + to_string(i);
    // TEXTURA DO SITE https://edermunizz.itch.io/free-pixel-art-forest
    addBackgroundLayer(id, 0.0f);
  }
  for (int i = 0; i <= 1; i++) {
    string id = "FOREST_GROUND_" + to_string(i);
    // TEXTURA DO SITE https://edermunizz.itch.io/free-pixel-art-forest
    addGroundLayer(id);
  }

  sf::Vector2f oldPos = mGround[0].getPosition();
  mGround[0].setPosition(oldPos.x, -20);
  mGround[1].setPosition(oldPos.x, -20);
  mGroundLevel = mGround[0].getLocalBounds().height - 75.f;
}
