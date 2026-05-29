#include "levels/ForestLevel.hpp"

ForestLevel::ForestLevel() {}

ForestLevel::~ForestLevel() {}

void ForestLevel::setup() {
  for (int i = 0; i <= 9; i++) {
    string id = "FOREST_LAYER_" + to_string(i);
    addBackgroundLayer(id, 0.0f);
  }
}

void ForestLevel::execute() {}
void ForestLevel::createMidEnemies() {}
void ForestLevel::createMidObst() {}

void ForestLevel::createEnemies() {}
void ForestLevel::createObstacles() {}
