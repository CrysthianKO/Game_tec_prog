#include "levels/ForestLevel.hpp"

#include <cstdlib>

#include "SFML/System/Vector2.hpp"
#include "entities/characters/Pterodactyl.hpp"
#include "entities/obstacles/Vine.hpp"
#include "managers/CollisionManager.hpp"

ForestLevel::ForestLevel() {}

ForestLevel::~ForestLevel() {}

void ForestLevel::setup() {
  CM.includeLevel(this);
  createEasyEnemies();
  createEnemies();
  createScenario();
  createObstacles(5);
  createPlatforms(5);
}

void ForestLevel::render() {
  drawBackground();
  mListEntities.drawEntities();
  drawGround();
}

void ForestLevel::execute() {
  CM.execute();
  mListEntities.execute();
}
void ForestLevel::createEnemies() {
  for (int i = 0; i < maxMidEnemies; i++) {
    Pterodactyl* newPtero = new Pterodactyl();
    newPtero->setTexture("PTERODACYL");
    mListEntities.include(newPtero);
    CM.includeEnemy(newPtero);
  }
}

void ForestLevel::createObstacles(int numObstacles) {
  int numPossibleObtacles = numObstacles * 5;
  vector<int> possiblePositions;
  for (int i = 1; i <= numPossibleObtacles; i++) {
    possiblePositions.push_back(i * 160.f);
  }

  for (int i = 0; i < numObstacles; i++) {
    int randPos = rand() % (0 - numPossibleObtacles +
                            1);  // (inicial - final + 1) + inicial
    float xPos = possiblePositions.at(randPos);
    Vine* vine = new Vine(xPos);
    vine->setTexture("VINE");
    mListEntities.include(vine);
    CM.IncludeObstacle(vine);
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
