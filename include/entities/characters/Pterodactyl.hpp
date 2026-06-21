#include "entities/characters/Enemy.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {

class Pterodactyl : public Enemy {
 private:
  static float position;
  float mFlyPosition;

 public:
  Pterodactyl();
  ~Pterodactyl();
  void execute();
  void save();
  void damage();
};

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
