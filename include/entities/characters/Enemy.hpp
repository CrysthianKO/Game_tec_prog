#pragma once
#include <SFML/Graphics.hpp>

#include "Character.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {

class Enemy : public Character {
 protected:
  int badLevel;
  float mWalkingTime;
  bool mMovingRight;
  float mRange;
  float mSpawnX;

 public:
  Enemy();
  virtual ~Enemy();
  void saveDataBuffer();
  int getBadLevel();
  virtual void execute() = 0;
  virtual void save() = 0;
  virtual void damage() = 0;
};

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
