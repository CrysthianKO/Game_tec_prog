#include "levels/ForestLevel.hpp"

#include "SFML/System/Vector2.hpp"

ForestLevel::ForestLevel() {}

ForestLevel::~ForestLevel() {}

void ForestLevel::setup() {
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
  mGroundLevel = -20;
}

void ForestLevel::execute() {
  drawBackground();
  mListEntities.drawEntities();
  drawGround();
}
void ForestLevel::createMidEnemies() {}
void ForestLevel::createMidObst() {}

void ForestLevel::createEnemies() {}
void ForestLevel::createObstacles() {}
