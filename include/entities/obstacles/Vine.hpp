#include "entities/obstacles/Obstacle.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Player;
}
namespace Obstacles {

class Vine : public Obstacle {
 private:
  static float position;

 public:
  Vine();
  ~Vine();

  void execute();
  void save();
  void obstruct(Characters::Player* pPlayer, sf::FloatRect intercession);
};

}  // namespace Obstacles
}  // namespace Entities
}  // namespace DinoGame
