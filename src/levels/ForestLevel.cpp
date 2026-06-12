#include "levels/ForestLevel.hpp"

#include <cstdlib>

#include "SFML/System/Vector2.hpp"
#include "entities/characters/Pterodactyl.hpp"
#include "entities/obstacles/Vine.hpp"
#include "managers/CollisionManager.hpp"

ForestLevel::ForestLevel() {
  maxMidEnemies = 5;
  maxMidObstacles = 5;
}

ForestLevel::~ForestLevel() {}

void ForestLevel::setup() {
  pCM->includeLevel(this);
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
  for (int i = 0; i < maxMidEnemies; i++) {
    Pterodactyl* newPtero = new Pterodactyl();
    pListEntities->include(newPtero);
    pCM->includeEnemy(newPtero);
  }
}

void ForestLevel::createObstacles() {
  for (int i = 0; i < maxMidObstacles; i++) {
    Vine* vine = new Vine();
    pListEntities->include(vine);
    pCM->IncludeObstacle(vine);
  }
}

void ForestLevel::createScenario() {
  for (int i = 0; i <= 9; i++) {
    string id = "FOREST_BACKGROUND_" + to_string(i);
    addBackgroundLayer(id, 0.0f);
  }
  for (int i = 0; i <= 1; i++) {
    string id = "FOREST_GROUND_" + to_string(i);
    addGroundLayer(id);
  }

  sf::Vector2f oldPos = mGround[0].getPosition();
  mGround[0].setPosition(oldPos.x, -20);
  mGround[1].setPosition(oldPos.x, -20);
  mGroundLevel = mGround[0].getLocalBounds().height - 75.f;
}
