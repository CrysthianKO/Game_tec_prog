#include "entities/obstacles/Obstacle.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {
class Player;
}
namespace Obstacles {

class Fire : public Obstacle {
 private:
  float static position;

 public:
  Fire();
  ~Fire();

  void execute();
  void save();
  void obstruct(Characters::Player* pPlayer, sf::FloatRect intercession);
};

}  // namespace Obstacles
}  // namespace Entities
}  // namespace DinoGame
