#pragma once
#include <SFML/Graphics.hpp>

#include "entities/characters/Enemy.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {

class Velociraptor : public Enemy {
 private:
  static float position;

 public:
  Velociraptor();
  virtual ~Velociraptor();
  void execute();
  void save();
  void damage();
};

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
