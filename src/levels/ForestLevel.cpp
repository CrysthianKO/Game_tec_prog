#include "levels/ForestLevel.hpp"

ForestLevel::ForestLevel() {
  for (int i = 0; i <= 9; i++) {
    string id = "FOREST_LAYER_" + to_string(i);
    this->setTexture(&mLayers[i].sprite, id);
  }
}
